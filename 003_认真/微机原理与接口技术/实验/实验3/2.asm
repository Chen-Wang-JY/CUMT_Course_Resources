PORT_A   EQU 2A0H
PORT_C   EQU 2A2H
PORT_CTL EQU 2A3H
;0809端口地址
PORT_IN4 EQU 284H

CODE SEGMENT
    ASSUME CS:CODE
START:
    MOV DX, PORT_CTL
    MOV AL, 10001001B   ;A口方式0，输出，C口输入
    OUT DX, AL
    MOV CX, 0FFFFH
MAIN:
    MOV DX, PORT_IN4
    OUT DX, AL          ;虚写

    MOV DX, PORT_C
    WAIT_EOC:
        IN AL, DX
        TEST AL, 00000001;
        JZ WAIT_EOC
    MOV DX, PORT_IN4
    IN  AL, DX
    MOV DX, PORT_A
    OUT DX, AL
    LOOP MAIN
CODE ENDS
    END