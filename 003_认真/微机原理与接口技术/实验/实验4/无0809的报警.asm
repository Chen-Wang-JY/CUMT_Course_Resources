CODE SEGMENT
ASSUME CS:CODE
START:
    MOV AL,35H     
    MOV DX,293H    ;控制口
    OUT DX,AL      ;输出控制字
    MOV AL,00H     ;低字节
    MOV DX,290H    ;通道0口
    OUT DX,AL
    MOV AL,20H     ;高字节
    OUT DX,AL
                   ;级联
    MOV AL,77H     
    MOV DX,293H    
    OUT DX,AL
    MOV AL,00H
    MOV DX,291H    ;通道1口
    OUT DX,AL
    MOV AL,20H
    OUT DX,AL

    MOV DX,283H    ;8255控制口
    MOV AL,10010000B     
    OUT DX,AL
    MOV BL,80H     ;初始化
LIGHT1:
    MOV DX,280H    ;A口输入
    IN AL,DX
    AND AX,01H     ;和00000001与保留最低位
    CMP AL,01H     ;比较最低位
    JZ DOWN        ;高电平不亮
    MOV DX,282H    ;低电平时C口输出
    MOV AL,BL
    OUT DX,AL      ;输出
    TEST AL,4H      ;检测是否到达第六位
    JNZ XIANG       ;是第六位的话就响
WAN:    ROR BL,1       
ON:
    MOV DX,280H    ;A口输入
    IN AL,DX
    AND AX,01H     
    CMP AL,01H     ;比较最低位是否为1
    JNZ ON        
DOWN:
    MOV DX,280H    ;A口输入
    IN AL,DX
    AND AX,01H
    CMP AL,0H      ;比较最低位是否为0
    JNZ DOWN        
    JMP LIGHT1     ;最低位为0时跳到LIGHT1
XIANG: MOV DX,281H
     MOV AL,01H
     OUT DX,AL

    MOV AL,35H     
    MOV DX,293H    ;控制口
    OUT DX,AL      ;输出控制字
    MOV AL,00H     ;低字节
    MOV DX,290H    ;通道0口
    OUT DX,AL
    MOV AL,20H     ;高字节
    OUT DX,AL
                   ;级联
    MOV AL,11110001B    
    MOV DX,293H    
    OUT DX,AL
    MOV AL,00H
    MOV DX,291H    ;通道1口
    OUT DX,AL
    MOV AL,10H
    OUT DX,AL

CHK:    MOV DX,280H
    IN AL,DX
    TEST AL,01H ;检测是否到达高电频
    JZ CHK       ;不是就继续监测，是就关闭蜂鸣器
     MOV AL,0H
     MOV DX,281H
     OUT DX,AL     
     JMP WAN     ;然后跳回跑马灯执行程序


CODE ENDS
END START 
