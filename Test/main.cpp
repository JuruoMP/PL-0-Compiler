#pragma warning(disable:4996)
#include <stdio.h>
char _string[] = "%s";
char _value[] = "%d";
char _charac[] = "%c";
char in_string0[] = "i=";
char in_string1[] = "  ";
char in_string2[] = "j=";
char in_string3[] = " ";
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
			SUB	esp, 12
			; LARGETK		Condition		LARGETK		1		100		Label2
			PUSH	esi
			MOV	edx, 1
			POP	esi
			MOV	eax, edx
			PUSH	esi
			MOV	edx, 100
			POP	esi
			MOV	ebx, edx
			CMP	eax, ebx
			JG	Label2
			; Assign		SETTK		i		1
			PUSH	esi
			MOV	edx, 1
			POP	esi
			MOV	eax, edx
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -28
			POP	edx
			MOV[esi], eax
			; Goto:		Label1
			JMP	Label1
			; Label:		Label0
		Label0 :
		; Assign		ADDTK		i		i		1
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -28
			POP	edx
			MOV	edx, [esi]
			POP	esi
			MOV	eax, edx
			PUSH	esi
			MOV	edx, 1
			POP	esi
			MOV	ebx, edx
			ADD	eax, ebx
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -28
			POP	edx
			MOV[esi], eax
			; Label:		Label1
		Label1 :
		; Write		String0
			LEA	eax, in_string0
			LEA	ebx, dword ptr[_string]
			PUSH	eax
			PUSH	ebx
			CALL	printf
			ADD	esp, 8
			; Write		i
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -28
			POP	edx
			MOV	edx, [esi]
			POP	esi
			MOV	eax, edx
			LEA	ebx, dword ptr[_value]
			PUSH	eax
			PUSH	ebx
			CALL	printf
			ADD	esp, 8
			; Write		String1
			LEA	eax, in_string1
			LEA	ebx, dword ptr[_string]
			PUSH	eax
			PUSH	ebx
			CALL	printf
			ADD	esp, 8
			; Assign		SUBTK		Temp5		50		i
			PUSH	esi
			MOV	edx, 50
			POP	esi
			MOV	eax, edx
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -28
			POP	edx
			MOV	edx, [esi]
			POP	esi
			MOV	ebx, edx
			SUB	eax, ebx
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -36
			POP	edx
			MOV[esi], eax
			; Assign		MULTK		Temp5		i		Temp5
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -28
			POP	edx
			MOV	edx, [esi]
			POP	esi
			MOV	eax, edx
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -36
			POP	edx
			MOV	edx, [esi]
			POP	esi
			MOV	ebx, edx
			IMUL	eax, ebx
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -36
			POP	edx
			MOV[esi], eax
			; Assign		SETTK		j		Temp5
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -36
			POP	edx
			MOV	edx, [esi]
			POP	esi
			MOV	eax, edx
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -32
			POP	edx
			MOV[esi], eax
			; Write		String2
			LEA	eax, in_string2
			LEA	ebx, dword ptr[_string]
			PUSH	eax
			PUSH	ebx
			CALL	printf
			ADD	esp, 8
			; Write		j
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -32
			POP	edx
			MOV	edx, [esi]
			POP	esi
			MOV	eax, edx
			LEA	ebx, dword ptr[_value]
			PUSH	eax
			PUSH	ebx
			CALL	printf
			ADD	esp, 8
			; Write		String3
			LEA	eax, in_string3
			LEA	ebx, dword ptr[_string]
			PUSH	eax
			PUSH	ebx
			CALL	printf
			ADD	esp, 8
			; SMALLTK		Condition		SMALLTK		i		100		Label0
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -28
			POP	edx
			MOV	edx, [esi]
			POP	esi
			MOV	eax, edx
			PUSH	esi
			MOV	edx, 100
			POP	esi
			MOV	ebx, edx
			CMP	eax, ebx
			JL	Label0
			; Label:		Label2
		Label2 :
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
