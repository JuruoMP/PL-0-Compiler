#pragma warning(disable:4996)
#include <stdio.h>
char _string[] = "%s";
char _value[] = "%d";
char _charac[] = "%c";
char in_string0[] = " ";
char in_string1[] = " ";
char in_string2[] = " ";
char in_string3[] = " ";
char in_string4[] = " ";
char in_string5[] = " ";
int main()
{
	_asm{


		; NODE: 1
			; FP:(1)		fp_fp_main_1
		fp_fp_main_1 :
		PUSH	ebp
			MOV	ebp, esp
			PUSH	eax
			PUSH	ebx
			PUSH	ecx
			PUSH	edx
			PUSH	esi
			PUSH	edi
			SUB	esp, 136
			; Assign		ADDTK		Temp4		1		1
			; getTempValue Srart :
		PUSH	esi
			MOV	edx, 1
			POP	esi
			; getTempValue End :
		MOV	eax, edx
			; getTempValue Srart :
		PUSH	esi
			MOV	edx, 1
			POP	esi
			; getTempValue End :
		MOV	ebx, edx
			ADD	eax, ebx
			; getTempAddr Srart :
		PUSH	edx
			MOV	esi, ebp
			ADD	esi, -128
			POP	edx
			; getTempAddr End :
		MOV[esi], eax
			; Assign		SETTK		a		Temp4
			; getTempValue Srart :
		PUSH	esi
			; getTempAddr Srart :
		PUSH	edx
			MOV	esi, ebp
			ADD	esi, -128
			POP	edx
			; getTempAddr End :
		MOV	edx, [esi]
			POP	esi
			; getTempValue End :
		MOV	eax, edx
			; getTempAddr Srart :
		PUSH	edx
			MOV	esi, ebp
			ADD	esi, -28
			POP	edx
			; getTempAddr End :
		MOV[esi], eax
			; Assign		ADDTK		Temp6		2		a
			; getTempValue Srart :
		PUSH	esi
			MOV	edx, 2
			POP	esi
			; getTempValue End :
		MOV	eax, edx
			; getTempValue Srart :
		PUSH	esi
			; getTempAddr Srart :
		PUSH	edx
			MOV	esi, ebp
			ADD	esi, -28
			POP	edx
			; getTempAddr End :
		MOV	edx, [esi]
			POP	esi
			; getTempValue End :
		MOV	ebx, edx
			ADD	eax, ebx
			; getTempAddr Srart :
		PUSH	edx
			MOV	esi, ebp
			ADD	esi, -132
			POP	edx
			; getTempAddr End :
		MOV[esi], eax
			; Assign		SETTK		b		Temp6
			; getTempValue Srart :
		PUSH	esi
			; getTempAddr Srart :
		PUSH	edx
			MOV	esi, ebp
			ADD	esi, -132
			POP	edx
			; getTempAddr End :
		MOV	edx, [esi]
			POP	esi
			; getTempValue End :
		MOV	eax, edx
			; getTempAddr Srart :
		PUSH	edx
			MOV	esi, ebp
			ADD	esi, -32
			POP	edx
			; getTempAddr End :
		MOV[esi], eax
			; Assign		SUBTK		Temp8		b		2
			; getTempValue Srart :
		PUSH	esi
			; getTempAddr Srart :
		PUSH	edx
			MOV	esi, ebp
			ADD	esi, -32
			POP	edx
			; getTempAddr End :
		MOV	edx, [esi]
			POP	esi
			; getTempValue End :
		MOV	eax, edx
			; getTempValue Srart :
		PUSH	esi
			MOV	edx, 2
			POP	esi
			; getTempValue End :
		MOV	ebx, edx
			SUB	eax, ebx
			; getTempAddr Srart :
		PUSH	edx
			MOV	esi, ebp
			ADD	esi, -136
			POP	edx
			; getTempAddr End :
		MOV[esi], eax
			; Assign		SETTK		c		Temp8
			; getTempValue Srart :
		PUSH	esi
			; getTempAddr Srart :
		PUSH	edx
			MOV	esi, ebp
			ADD	esi, -136
			POP	edx
			; getTempAddr End :
		MOV	edx, [esi]
			POP	esi
			; getTempValue End :
		MOV	eax, edx
			; getTempAddr Srart :
		PUSH	edx
			MOV	esi, ebp
			ADD	esi, -36
			POP	edx
			; getTempAddr End :
		MOV[esi], eax
			; Assign		DIVTK		Temp9		b		c
			; getTempValue Srart :
		PUSH	esi
			; getTempAddr Srart :
		PUSH	edx
			MOV	esi, ebp
			ADD	esi, -32
			POP	edx
			; getTempAddr End :
		MOV	edx, [esi]
			POP	esi
			; getTempValue End :
		MOV	eax, edx
			; getTempValue Srart :
		PUSH	esi
			; getTempAddr Srart :
		PUSH	edx
			MOV	esi, ebp
			ADD	esi, -36
			POP	edx
			; getTempAddr End :
		MOV	edx, [esi]
			POP	esi
			; getTempValue End :
		MOV	ebx, edx
			CDQ
			IDIV	ebx
			; getTempAddr Srart :
		PUSH	edx
			MOV	esi, ebp
			ADD	esi, -140
			POP	edx
			; getTempAddr End :
		MOV[esi], eax
			; Assign		SETTK		d		Temp9
			; getTempValue Srart :
		PUSH	esi
			; getTempAddr Srart :
		PUSH	edx
			MOV	esi, ebp
			ADD	esi, -140
			POP	edx
			; getTempAddr End :
		MOV	edx, [esi]
			POP	esi
			; getTempValue End :
		MOV	eax, edx
			; getTempAddr Srart :
		PUSH	edx
			MOV	esi, ebp
			ADD	esi, -40
			POP	edx
			; getTempAddr End :
		MOV[esi], eax
			; Write		String0
			LEA	eax, in_string0
			LEA	ebx, _string
			PUSH	eax
			PUSH	ebx
			CALL	printf
			ADD	esp, 8
			; Write		a
			; getTempValue Srart :
		PUSH	esi
			; getTempAddr Srart :
		PUSH	edx
			MOV	esi, ebp
			ADD	esi, -28
			POP	edx
			; getTempAddr End :
		MOV	edx, [esi]
			POP	esi
			; getTempValue End :
		MOV	eax, edx
			LEA	ebx, _value
			PUSH	eax
			PUSH	ebx
			CALL	printf
			ADD	esp, 8
			; Write		String1
			LEA	eax, in_string1
			LEA	ebx, _string
			PUSH	eax
			PUSH	ebx
			CALL	printf
			ADD	esp, 8
			; Write		b
			; getTempValue Srart :
		PUSH	esi
			; getTempAddr Srart :
		PUSH	edx
			MOV	esi, ebp
			ADD	esi, -32
			POP	edx
			; getTempAddr End :
		MOV	edx, [esi]
			POP	esi
			; getTempValue End :
		MOV	eax, edx
			LEA	ebx, _value
			PUSH	eax
			PUSH	ebx
			CALL	printf
			ADD	esp, 8
			; Write		String2
			LEA	eax, in_string2
			LEA	ebx, _string
			PUSH	eax
			PUSH	ebx
			CALL	printf
			ADD	esp, 8
			; Write		c
			; getTempValue Srart :
		PUSH	esi
			; getTempAddr Srart :
		PUSH	edx
			MOV	esi, ebp
			ADD	esi, -36
			POP	edx
			; getTempAddr End :
		MOV	edx, [esi]
			POP	esi
			; getTempValue End :
		MOV	eax, edx
			LEA	ebx, _value
			PUSH	eax
			PUSH	ebx
			CALL	printf
			ADD	esp, 8
			; Write		String3
			LEA	eax, in_string3
			LEA	ebx, _string
			PUSH	eax
			PUSH	ebx
			CALL	printf
			ADD	esp, 8
			; Write		d
			; getTempValue Srart :
		PUSH	esi
			; getTempAddr Srart :
		PUSH	edx
			MOV	esi, ebp
			ADD	esi, -40
			POP	edx
			; getTempAddr End :
		MOV	edx, [esi]
			POP	esi
			; getTempValue End :
		MOV	eax, edx
			LEA	ebx, _value
			PUSH	eax
			PUSH	ebx
			CALL	printf
			ADD	esp, 8
			; Assign		ADDTK		Temp10		a		b
			; getTempValue Srart :
		PUSH	esi
			; getTempAddr Srart :
		PUSH	edx
			MOV	esi, ebp
			ADD	esi, -28
			POP	edx
			; getTempAddr End :
		MOV	edx, [esi]
			POP	esi
			; getTempValue End :
		MOV	eax, edx
			; getTempValue Srart :
		PUSH	esi
			; getTempAddr Srart :
		PUSH	edx
			MOV	esi, ebp
			ADD	esi, -32
			POP	edx
			; getTempAddr End :
		MOV	edx, [esi]
			POP	esi
			; getTempValue End :
		MOV	ebx, edx
			ADD	eax, ebx
			; getTempAddr Srart :
		PUSH	edx
			MOV	esi, ebp
			ADD	esi, -144
			POP	edx
			; getTempAddr End :
		MOV[esi], eax
			; Assign		MULTK		Temp10		Temp10		c
			; getTempValue Srart :
		PUSH	esi
			; getTempAddr Srart :
		PUSH	edx
			MOV	esi, ebp
			ADD	esi, -144
			POP	edx
			; getTempAddr End :
		MOV	edx, [esi]
			POP	esi
			; getTempValue End :
		MOV	eax, edx
			; getTempValue Srart :
		PUSH	esi
			; getTempAddr Srart :
		PUSH	edx
			MOV	esi, ebp
			ADD	esi, -36
			POP	edx
			; getTempAddr End :
		MOV	edx, [esi]
			POP	esi
			; getTempValue End :
		MOV	ebx, edx
			IMUL	eax, ebx
			; getTempAddr Srart :
		PUSH	edx
			MOV	esi, ebp
			ADD	esi, -144
			POP	edx
			; getTempAddr End :
		MOV[esi], eax
			; Assign		ADDTK		Temp11		d		a
			; getTempValue Srart :
		PUSH	esi
			; getTempAddr Srart :
		PUSH	edx
			MOV	esi, ebp
			ADD	esi, -40
			POP	edx
			; getTempAddr End :
		MOV	edx, [esi]
			POP	esi
			; getTempValue End :
		MOV	eax, edx
			; getTempValue Srart :
		PUSH	esi
			; getTempAddr Srart :
		PUSH	edx
			MOV	esi, ebp
			ADD	esi, -28
			POP	edx
			; getTempAddr End :
		MOV	edx, [esi]
			POP	esi
			; getTempValue End :
		MOV	ebx, edx
			ADD	eax, ebx
			; getTempAddr Srart :
		PUSH	edx
			MOV	esi, ebp
			ADD	esi, -148
			POP	edx
			; getTempAddr End :
		MOV[esi], eax
			; Assign		DIVTK		Temp11		Temp11		b
			; getTempValue Srart :
		PUSH	esi
			; getTempAddr Srart :
		PUSH	edx
			MOV	esi, ebp
			ADD	esi, -148
			POP	edx
			; getTempAddr End :
		MOV	edx, [esi]
			POP	esi
			; getTempValue End :
		MOV	eax, edx
			; getTempValue Srart :
		PUSH	esi
			; getTempAddr Srart :
		PUSH	edx
			MOV	esi, ebp
			ADD	esi, -32
			POP	edx
			; getTempAddr End :
		MOV	edx, [esi]
			POP	esi
			; getTempValue End :
		MOV	ebx, edx
			CDQ
			IDIV	ebx
			; getTempAddr Srart :
		PUSH	edx
			MOV	esi, ebp
			ADD	esi, -148
			POP	edx
			; getTempAddr End :
		MOV[esi], eax
			; Assign		ADDTK		Temp10		Temp10		Temp11
			; getTempValue Srart :
		PUSH	esi
			; getTempAddr Srart :
		PUSH	edx
			MOV	esi, ebp
			ADD	esi, -144
			POP	edx
			; getTempAddr End :
		MOV	edx, [esi]
			POP	esi
			; getTempValue End :
		MOV	eax, edx
			; getTempValue Srart :
		PUSH	esi
			; getTempAddr Srart :
		PUSH	edx
			MOV	esi, ebp
			ADD	esi, -148
			POP	edx
			; getTempAddr End :
		MOV	edx, [esi]
			POP	esi
			; getTempValue End :
		MOV	ebx, edx
			ADD	eax, ebx
			; getTempAddr Srart :
		PUSH	edx
			MOV	esi, ebp
			ADD	esi, -144
			POP	edx
			; getTempAddr End :
		MOV[esi], eax
			; Assign		DIVTK		Temp10		Temp10		d
			; getTempValue Srart :
		PUSH	esi
			; getTempAddr Srart :
		PUSH	edx
			MOV	esi, ebp
			ADD	esi, -144
			POP	edx
			; getTempAddr End :
		MOV	edx, [esi]
			POP	esi
			; getTempValue End :
		MOV	eax, edx
			; getTempValue Srart :
		PUSH	esi
			; getTempAddr Srart :
		PUSH	edx
			MOV	esi, ebp
			ADD	esi, -40
			POP	edx
			; getTempAddr End :
		MOV	edx, [esi]
			POP	esi
			; getTempValue End :
		MOV	ebx, edx
			CDQ
			IDIV	ebx
			; getTempAddr Srart :
		PUSH	edx
			MOV	esi, ebp
			ADD	esi, -144
			POP	edx
			; getTempAddr End :
		MOV[esi], eax
			; Assign		SETTK		a		Temp10
			; getTempValue Srart :
		PUSH	esi
			; getTempAddr Srart :
		PUSH	edx
			MOV	esi, ebp
			ADD	esi, -144
			POP	edx
			; getTempAddr End :
		MOV	edx, [esi]
			POP	esi
			; getTempValue End :
		MOV	eax, edx
			; getTempAddr Srart :
		PUSH	edx
			MOV	esi, ebp
			ADD	esi, -28
			POP	edx
			; getTempAddr End :
		MOV[esi], eax
			; Write		String4
			LEA	eax, in_string4
			LEA	ebx, _string
			PUSH	eax
			PUSH	ebx
			CALL	printf
			ADD	esp, 8
			; Write		a
			; getTempValue Srart :
		PUSH	esi
			; getTempAddr Srart :
		PUSH	edx
			MOV	esi, ebp
			ADD	esi, -28
			POP	edx
			; getTempAddr End :
		MOV	edx, [esi]
			POP	esi
			; getTempValue End :
		MOV	eax, edx
			LEA	ebx, _value
			PUSH	eax
			PUSH	ebx
			CALL	printf
			ADD	esp, 8
			; Assign		SETTK		arr[0]		1
			; getTempValue Srart :
		PUSH	esi
			MOV	edx, 1
			POP	esi
			; getTempValue End :
		MOV	eax, edx
			; getTempAddr Srart :
		PUSH	edx
			MOV	esi, ebp
			ADD	esi, -120
			; getTempValue Srart :
		PUSH	esi
			MOV	edx, 0
			POP	esi
			; getTempValue End :
		IMUL	edx, edx, 4
			ADD	esi, edx
			POP	edx
			; getTempAddr End :
		MOV[esi], eax
			; Assign		SETTK		arr[1]		1
			; getTempValue Srart :
		PUSH	esi
			MOV	edx, 1
			POP	esi
			; getTempValue End :
		MOV	eax, edx
			; getTempAddr Srart :
		PUSH	edx
			MOV	esi, ebp
			ADD	esi, -120
			; getTempValue Srart :
		PUSH	esi
			MOV	edx, 1
			POP	esi
			; getTempValue End :
		IMUL	edx, edx, 4
			ADD	esi, edx
			POP	edx
			; getTempAddr End :
		MOV[esi], eax
			; Assign		SETTK		i		2
			; getTempValue Srart :
		PUSH	esi
			MOV	edx, 2
			POP	esi
			; getTempValue End :
		MOV	eax, edx
			; getTempAddr Srart :
		PUSH	edx
			MOV	esi, ebp
			ADD	esi, -124
			POP	edx
			; getTempAddr End :
		MOV[esi], eax
			; Label:		Label0
		Label0 :
		; LARGETK		Condition		LARGETK		i		19		Label1
			; getTempValue Srart :
		PUSH	esi
			; getTempAddr Srart :
		PUSH	edx
			MOV	esi, ebp
			ADD	esi, -124
			POP	edx
			; getTempAddr End :
		MOV	edx, [esi]
			POP	esi
			; getTempValue End :
		MOV	eax, edx
			; getTempValue Srart :
		PUSH	esi
			MOV	edx, 19
			POP	esi
			; getTempValue End :
		MOV	ebx, edx
			CMP	eax, ebx
			JG	Label1
			; Assign		SUBTK		Temp19		i		1
			; getTempValue Srart :
		PUSH	esi
			; getTempAddr Srart :
		PUSH	edx
			MOV	esi, ebp
			ADD	esi, -124
			POP	edx
			; getTempAddr End :
		MOV	edx, [esi]
			POP	esi
			; getTempValue End :
		MOV	eax, edx
			; getTempValue Srart :
		PUSH	esi
			MOV	edx, 1
			POP	esi
			; getTempValue End :
		MOV	ebx, edx
			SUB	eax, ebx
			; getTempAddr Srart :
		PUSH	edx
			MOV	esi, ebp
			ADD	esi, -152
			POP	edx
			; getTempAddr End :
		MOV[esi], eax
			; Assign		SUBTK		Temp21		i		2
			; getTempValue Srart :
		PUSH	esi
			; getTempAddr Srart :
		PUSH	edx
			MOV	esi, ebp
			ADD	esi, -124
			POP	edx
			; getTempAddr End :
		MOV	edx, [esi]
			POP	esi
			; getTempValue End :
		MOV	eax, edx
			; getTempValue Srart :
		PUSH	esi
			MOV	edx, 2
			POP	esi
			; getTempValue End :
		MOV	ebx, edx
			SUB	eax, ebx
			; getTempAddr Srart :
		PUSH	edx
			MOV	esi, ebp
			ADD	esi, -156
			POP	edx
			; getTempAddr End :
		MOV[esi], eax
			; Assign		ADDTK		Temp22		arr[Temp19]		arr[Temp21]
			; getTempValue Srart :
		PUSH	esi
			; getTempAddr Srart :
		PUSH	edx
			MOV	esi, ebp
			ADD	esi, -120
			; getTempValue Srart :
		PUSH	esi
			; getTempAddr Srart :
		PUSH	edx
			MOV	esi, ebp
			ADD	esi, -152
			POP	edx
			; getTempAddr End :
		MOV	edx, [esi]
			POP	esi
			; getTempValue End :
		IMUL	edx, edx, 4
			ADD	esi, edx
			POP	edx
			; getTempAddr End :
		MOV	edx, [esi]
			POP	esi
			; getTempValue End :
		MOV	eax, edx
			; getTempValue Srart :
		PUSH	esi
			; getTempAddr Srart :
		PUSH	edx
			MOV	esi, ebp
			ADD	esi, -120
			; getTempValue Srart :
		PUSH	esi
			; getTempAddr Srart :
		PUSH	edx
			MOV	esi, ebp
			ADD	esi, -156
			POP	edx
			; getTempAddr End :
		MOV	edx, [esi]
			POP	esi
			; getTempValue End :
		IMUL	edx, edx, 4
			ADD	esi, edx
			POP	edx
			; getTempAddr End :
		MOV	edx, [esi]
			POP	esi
			; getTempValue End :
		MOV	ebx, edx
			ADD	eax, ebx
			; getTempAddr Srart :
		PUSH	edx
			MOV	esi, ebp
			ADD	esi, -160
			POP	edx
			; getTempAddr End :
		MOV[esi], eax
			; Assign		SETTK		arr[i]		Temp22
			; getTempValue Srart :
		PUSH	esi
			; getTempAddr Srart :
		PUSH	edx
			MOV	esi, ebp
			ADD	esi, -160
			POP	edx
			; getTempAddr End :
		MOV	edx, [esi]
			POP	esi
			; getTempValue End :
		MOV	eax, edx
			; getTempAddr Srart :
		PUSH	edx
			MOV	esi, ebp
			ADD	esi, -120
			; getTempValue Srart :
		PUSH	esi
			; getTempAddr Srart :
		PUSH	edx
			MOV	esi, ebp
			ADD	esi, -124
			POP	edx
			; getTempAddr End :
		MOV	edx, [esi]
			POP	esi
			; getTempValue End :
		IMUL	edx, edx, 4
			ADD	esi, edx
			POP	edx
			; getTempAddr End :
		MOV[esi], eax
			; Assign		ADDTK		i		i		1
			; getTempValue Srart :
		PUSH	esi
			; getTempAddr Srart :
		PUSH	edx
			MOV	esi, ebp
			ADD	esi, -124
			POP	edx
			; getTempAddr End :
		MOV	edx, [esi]
			POP	esi
			; getTempValue End :
		MOV	eax, edx
			; getTempValue Srart :
		PUSH	esi
			MOV	edx, 1
			POP	esi
			; getTempValue End :
		MOV	ebx, edx
			ADD	eax, ebx
			; getTempAddr Srart :
		PUSH	edx
			MOV	esi, ebp
			ADD	esi, -124
			POP	edx
			; getTempAddr End :
		MOV[esi], eax
			; Goto:		Label0
			JMP	Label0
			; Label:		Label1
		Label1 :
		; Assign		SETTK		i		0
			; getTempValue Srart :
		PUSH	esi
			MOV	edx, 0
			POP	esi
			; getTempValue End :
		MOV	eax, edx
			; getTempAddr Srart :
		PUSH	edx
			MOV	esi, ebp
			ADD	esi, -124
			POP	edx
			; getTempAddr End :
		MOV[esi], eax
			; Label:		Label2
		Label2 :
		; LARGETK		Condition		LARGETK		i		19		Label3
			; getTempValue Srart :
		PUSH	esi
			; getTempAddr Srart :
		PUSH	edx
			MOV	esi, ebp
			ADD	esi, -124
			POP	edx
			; getTempAddr End :
		MOV	edx, [esi]
			POP	esi
			; getTempValue End :
		MOV	eax, edx
			; getTempValue Srart :
		PUSH	esi
			MOV	edx, 19
			POP	esi
			; getTempValue End :
		MOV	ebx, edx
			CMP	eax, ebx
			JG	Label3
			; Write		String5
			LEA	eax, in_string5
			LEA	ebx, _string
			PUSH	eax
			PUSH	ebx
			CALL	printf
			ADD	esp, 8
			; Write		arr[i]
			; getTempValue Srart :
		PUSH	esi
			; getTempAddr Srart :
		PUSH	edx
			MOV	esi, ebp
			ADD	esi, -120
			; getTempValue Srart :
		PUSH	esi
			; getTempAddr Srart :
		PUSH	edx
			MOV	esi, ebp
			ADD	esi, -124
			POP	edx
			; getTempAddr End :
		MOV	edx, [esi]
			POP	esi
			; getTempValue End :
		IMUL	edx, edx, 4
			ADD	esi, edx
			POP	edx
			; getTempAddr End :
		MOV	edx, [esi]
			POP	esi
			; getTempValue End :
		MOV	eax, edx
			LEA	ebx, _value
			PUSH	eax
			PUSH	ebx
			CALL	printf
			ADD	esp, 8
			; Assign		ADDTK		i		i		1
			; getTempValue Srart :
		PUSH	esi
			; getTempAddr Srart :
		PUSH	edx
			MOV	esi, ebp
			ADD	esi, -124
			POP	edx
			; getTempAddr End :
		MOV	edx, [esi]
			POP	esi
			; getTempValue End :
		MOV	eax, edx
			; getTempValue Srart :
		PUSH	esi
			MOV	edx, 1
			POP	esi
			; getTempValue End :
		MOV	ebx, edx
			ADD	eax, ebx
			; getTempAddr Srart :
		PUSH	edx
			MOV	esi, ebp
			ADD	esi, -124
			POP	edx
			; getTempAddr End :
		MOV[esi], eax
			; Goto:		Label2
			JMP	Label2
			; Label:		Label3
		Label3 :
		POP	edi
			POP	esi
			POP	edx
			POP	ecx
			POP	ebx
			POP	eax
			MOV	esp, ebp
			POP	ebp
			JMP	ENDPOINT

		ENDPOINT :
	}
	return 0;
}
