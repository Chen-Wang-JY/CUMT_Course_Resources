;端口地址
PORT_A   EQU 0FF9H ;8255 A口地址，常数值0F9H赋给符号名PORT_A（A端口）
PORT_B   EQU 0FFBH ;8255 B口地址
PORT_CTL EQU 0FFFH ;8255 控制口地址
;定义数据段，键盘扫描码表
DATA SEGMENT;段定义语句
;         0     1     2     3     4     5     6     7
TABLE DB  77H,  7BH,  7DH,  7EH, 0B7H, 0BBH, 0BDH, 0BEH,
;         8     9     A     B     C     D     E     F
      DB 0D7H, 0DBH, 0DDH, 0DEH，0E7H, 0EBH, 0EDH, 0EEH
DATA  ENDS;段定义语句
;定义堆栈段
STACK SEGMENT STACK
      DW 50 DUP(0);定义50个字单元，初值均为0
TOP_STAC LABEL WORD;将TOP_STAC定义为字变量
STACK    ENDS
;定义代码段
CODE  SEGMENT
      ASSUME CS:CODE, DS:DATA, SS:STACK;段分配语句，3个段寄存器分别与哪些段有关
START:MOV AX, STACK
      MOV SS, AX
      LEA SP, TOP_STACK
      MOV AX, DATA
      MOV DS, AX
;初始化 8255A ，方式0， B口 和 C口做输入，A口做输出
      MOV DX, PORT_CTL  ;指向控制口
      MOV AL, 10001011B ;控制字
      OUT DX, AL        ;写入控制字
;向所有行送0
      MOV DX, PORT_A ;A口
      MOV AL, 00H    ;
      OUT DX, AL     ;向A口各位输出0
;读列，查看是否所有键松开
      MOV DX, PORT_B
WAIT_OPEN:IN AL, DX  ;键盘状态读入B口
      AND AL, 0FH    ;只查低4位（列值）
      CMP AL, 0FH    ;是否都为1（各键都松开）？
      JNE WAIT_OPEN  ;否，继续查
;各键均已松开，再查列是否有0，即是否有键压下
WAIT_PRES:IN AL, DX  ;读B口
      AND AL, 0FH    ;只查低4位
      CMP AL, 0FH    ;是否有键压下
      JE  WAIT_PRES  ;无，等待
;有键压下演示20ms，消抖动
      MOV CX, 16EAH
DELAY:LOOP DELAY ;延时20ms（LOOP：CX内容自减1，若CX≠0时，转移到指定标号处，否则退出循环）
;再查列，看键是否仍被压着
      IN  AL, DX
      AND AL, 0FH
      CMP AL, 0FH
      JE  WAIT_PRES   ;已松开，转出等待压键
;键仍被压着，确定是哪一个键被压下
      MOV AL, 0FEH       ;先使D0=0
      MOV CL, AL         ;CL=1111 1110 B
NEXT_ROW:MOV DX, PORT_A  ;A口
      OUT DX, AL         ;向一行输出低电平
      MOV DX, PORT_B     ;B口
      IN  AL, DX         ;读入B口状态
      AND AL, 0FH        ;只截取列值
      CMP AL, 0FH        ;是否均为1？
      JNE ENCODE         ;否，表示有键压下，转去编码（JNE：不为0，跳转）
      ROL CL, 01         ;均为1，使下行输出0
      MOV AL, CL
      JMP NEXT_ROW       ;查看下行
;已找到有一列为低电平，对压键的行列值编码
ENCODE:MOV BX, 000FH       ;建立地址指针，先指向  F  键对应的地址
      IN  AL, DX           ;从B口读入行列号
NEXT_TRY:CMP AL, TABLE[BX] ;读入的行列值与表中查得的相等吗？
      JE  DONE             ;相等，转出（JE：为零，跳转）
      DEC BX               ;不等，指向下一个（键值较小值）地址
      JNS NEXT_NEXT_TRY    ;若地址尚未减为负值，继续查
      MOV AH, 01           ;若减为负值，置出错码01 -> AH中
      JMP EXIT             ;退出（JMP：无条件转移指令）
DONE:MOV AL, BL            ;BL中存有键的十六进制代码
      MOV AH, 00           ;AH=0，读到有效键值
EXIT:HLT                   ;结束，停机指令
CODE ENDS
      END                  ;程序结束语句