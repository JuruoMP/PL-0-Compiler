#pragma warning(disable:4996)
#include <stdio.h>
char _string[] = "%s";
char _value[] = "%d";
char _charac[] = "%c";
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
			SUB	esp, 4
			; Assign		SETTK		a1		10
			PUSH	esi
			MOV	edx, 10
			POP	esi
			MOV	eax, edx
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -28
			POP	edx
			MOV[esi], eax
			; Write		a1
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -28
			POP	edx
			MOV	edx, [esi]
			POP	esi
			MOV	eax, edx
			LEA	ebx, _value
			PUSH	eax
			PUSH	ebx
			CALL	printf
			ADD	esp, 8
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
