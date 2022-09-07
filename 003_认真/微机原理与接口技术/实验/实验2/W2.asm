PORT_IN EQU 2A0H
PORT_OUT EQU 2A2H
PORT_CTL EQU 2A3H
PORT_CLK EQU 2A1H

PORT_CTLX EQU 283H
PORT_IN1 EQU 280H
PORT_IN2 EQU 281H 

CODE SEGMENT
ASSUME CS:CODE
START:
    ;8253控制字
    MOV DX,PORT_CTLX
    MOV AL,00110111B
    OUT DX,AL
    MOV AL,01110101B
    OUT DX,AL
    ;计数器一
    MOV DX,PORT_IN1
    MOV AL,00H
    OUT DX,AL
    MOV AL,30H
    OUT DX,AL
    ;计数器二
    MOV DX,PORT_IN2
    MOV AL,00H
    OUT DX,AL
    MOV AL,10H
    OUT DX,AL
    
    ;写入控制寄存器
    MOV DX, PORT_CTL
    MOV AL, 10010010B     ;A端口方式0，输入。C端口输出
    OUT DX, AL
    ;以AL作为跑马灯状态的寄存器，赋初值
    MOV DX, PORT_OUT
    MOV AL, 00010000B
    OUT DX, AL
    ;设定循环
    MOV CX, 2000H
CYCLE:
    ;控制
    MOV DX, PORT_IN
    MOV BL, AL ;暂存寄存器状态
    IN     AL, DX
    TEST AL, 10000000B
    MOV AL, BL ;放回寄存器原状态
    JZ ELES
    JNZ MAIN1

ELES:
    MOV BL, AL ;暂存寄存器状态
    IN  AL, DX
    TEST AL, 01000000B
    MOV AL, BL ;放回寄存器原状态
    JZ CYCLE
    JNZ MAIN2

MAIN1:
    MOV DX, PORT_OUT
    OUT DX, AL
    ROR AL, 1
    ;LED明亮时间长短的软延迟
    MOV BL, AL  ;暂存
    
    MOV DX, PORT_CLK
    AI1:
        IN AL, DX
        TEST AL, 00000001B
        JNZ AI1
    AI11:
        IN AL, DX
        TEST AL, 00000001B
        JZ AI11

    MOV AL, BL  ;恢复
    ;回到主函数
    DEC CX
    JNZ CYCLE

MAIN2:
    MOV DX, PORT_OUT
    OUT DX, AL
    ROL AL, 1
    MOV BL, AL  ;暂存
    
    MOV DX, PORT_CLK
    AI2:
        IN AL, DX
        TEST AL, 00000001B
        JNZ AI2
    AI22:
        IN AL, DX
        TEST AL, 00000001B
        JZ AI22    
    MOV AL, BL  ;恢复
    DEC CX
    JNZ CYCLE

CODE ENDS
END START