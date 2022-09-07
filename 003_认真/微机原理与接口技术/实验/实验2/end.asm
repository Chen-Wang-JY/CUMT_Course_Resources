CODE SEGMENT
ASSUME CS:CODE
START:
	;假设8253的控制端口的地址283H
	MOV DX, 283H
	MOV AL, 00010111B   ;选择通道0，只读写低字节，方式3，BCD码
	OUT DX, AL

	;8253写入计数初值
	MOV AL, 26H
	OUT 280H, AL   ;通道0送入计数初值，开始计数

