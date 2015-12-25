#pragma warning(disable:4996)
#include <stdio.h>
char _string[] = "%s";
char _value[] = "%d";
char _charac[] = "%c";
char in_string0[] = "GCD is:";
char in_string1[] = "LCM is:";
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
			PUSH	2
			SUB	esp, 40
			; SMALLTK		Condition		SMALLTK		i		1		Label2
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -60
			POP	edx
			MOV	edx, [esi]
			POP	esi
			MOV	eax, edx
			PUSH	esi
			MOV	edx, 1
			POP	esi
			MOV	ebx, edx
			CMP	eax, ebx
			JL	Label2
			; Assign		SETTK		i		2
			PUSH	esi
			MOV	edx, 2
			POP	esi
			MOV	eax, edx
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -60
			POP	edx
			MOV[esi], eax
			; Goto:		Label1
			JMP	Label1
			; Label:		Label0
		Label0 :
		; Assign		SUBTK		i		i		1
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -60
			POP	edx
			MOV	edx, [esi]
			POP	esi
			MOV	eax, edx
			PUSH	esi
			MOV	edx, 1
			POP	esi
			MOV	ebx, edx
			SUB	eax, ebx
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -60
			POP	edx
			MOV[esi], eax
			; Label:		Label1
		Label1 :
		; bel:NEQUTK		Condition		NEQUTK		i		2		Label3
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -60
			POP	edx
			MOV	edx, [esi]
			POP	esi
			MOV	eax, edx
			PUSH	esi
			MOV	edx, 2
			POP	esi
			MOV	ebx, edx
			CMP	eax, ebx
			JNE	Label3
			; Assign		SETTK		x		45
			PUSH	esi
			MOV	edx, 45
			POP	esi
			MOV	eax, edx
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -32
			POP	edx
			MOV[esi], eax
			; Assign		SETTK		y		27
			PUSH	esi
			MOV	edx, 27
			POP	esi
			MOV	eax, edx
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -36
			POP	edx
			MOV[esi], eax
			; Goto:		Label4
			JMP	Label4
			; Label:		Label3
		Label3 :
		; Assign		SETTK		x		5
			PUSH	esi
			MOV	edx, 5
			POP	esi
			MOV	eax, edx
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -32
			POP	edx
			MOV[esi], eax
			; Assign		SETTK		y		0
			PUSH	esi
			MOV	edx, 0
			POP	esi
			MOV	eax, edx
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -36
			POP	edx
			MOV[esi], eax
			; Label:		Label4
		Label4 :
		; Assign		SETTK		a		x
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -32
			POP	edx
			MOV	edx, [esi]
			POP	esi
			MOV	eax, edx
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -40
			POP	edx
			MOV[esi], eax
			; Assign		SETTK		b		y
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
			ADD	esi, -44
			POP	edx
			MOV[esi], eax
			; abel:EQUTK		Condition		EQUTK		y		0		Label5
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -36
			POP	edx
			MOV	edx, [esi]
			POP	esi
			MOV	eax, edx
			PUSH	esi
			MOV	edx, 0
			POP	esi
			MOV	ebx, edx
			CMP	eax, ebx
			JE	Label5
			; Label:		Label7
		Label7 :
		; Assign		SETTK		cc		b
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -44
			POP	edx
			MOV	edx, [esi]
			POP	esi
			MOV	eax, edx
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -56
			POP	edx
			MOV[esi], eax
			; Call		fp_mymod_2		dst = Temp11		argc = 2
			MOV	esi, ebp
			ADD	esi, 8
			LEA	edi, [ebp]
			PUSH	edi
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -44
			POP	edx
			MOV	edx, [esi]
			POP	esi
			PUSH	edx
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -40
			POP	edx
			MOV	edx, [esi]
			POP	esi
			PUSH	edx
			CALL	fp_mymod_2
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -64
			POP	edx
			MOV[esi], eax
			ADD	esp, 12
			; Assign		SETTK		b		Temp11
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -64
			POP	edx
			MOV	edx, [esi]
			POP	esi
			MOV	eax, edx
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -44
			POP	edx
			MOV[esi], eax
			; Assign		SETTK		a		cc
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -56
			POP	edx
			MOV	edx, [esi]
			POP	esi
			MOV	eax, edx
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -40
			POP	edx
			MOV[esi], eax
			; bel:NEQUTK		Condition		NEQUTK		b		0		Label7
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -44
			POP	edx
			MOV	edx, [esi]
			POP	esi
			MOV	eax, edx
			PUSH	esi
			MOV	edx, 0
			POP	esi
			MOV	ebx, edx
			CMP	eax, ebx
			JNE	Label7
			; Goto:		Label6
			JMP	Label6
			; Label:		Label5
		Label5 :
		; Label:		Label6
		Label6 :
		; Assign		SETTK		f		a
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -40
			POP	edx
			MOV	edx, [esi]
			POP	esi
			MOV	eax, edx
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -48
			POP	edx
			MOV[esi], eax
			; Assign		MULTK		Temp13		x		y
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -32
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
			ADD	esi, -68
			POP	edx
			MOV[esi], eax
			; Assign		DIVTK		Temp13		Temp13		f
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -68
			POP	edx
			MOV	edx, [esi]
			POP	esi
			MOV	eax, edx
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -48
			POP	edx
			MOV	edx, [esi]
			POP	esi
			MOV	ebx, edx
			CDQ
			IDIV	ebx
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -68
			POP	edx
			MOV[esi], eax
			; Assign		SETTK		g		Temp13
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -68
			POP	edx
			MOV	edx, [esi]
			POP	esi
			MOV	eax, edx
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -52
			POP	edx
			MOV[esi], eax
			; Write		String0
			LEA	eax, in_string0
			LEA	ebx, _string
			PUSH	eax
			PUSH	ebx
			CALL	printf
			ADD	esp, 8
			; Write		f
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -48
			POP	edx
			MOV	edx, [esi]
			POP	esi
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
			; Write		g
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -52
			POP	edx
			MOV	edx, [esi]
			POP	esi
			MOV	eax, edx
			LEA	ebx, _value
			PUSH	eax
			PUSH	ebx
			CALL	printf
			ADD	esp, 8
			; LARGETK		Condition		LARGETK		i		1		Label0
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -60
			POP	edx
			MOV	edx, [esi]
			POP	esi
			MOV	eax, edx
			PUSH	esi
			MOV	edx, 1
			POP	esi
			MOV	ebx, edx
			CMP	eax, ebx
			JG	Label0
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



			; NODE: 2
			; FP:(2)		fp_mymod_2
		fp_mymod_2 :
		PUSH	ebp
			MOV	ebp, esp
			PUSH	ebx
			PUSH	ecx
			PUSH	edx
			PUSH	esi
			PUSH	edi
			SUB	esp, 8
			; Assign		DIVTK		Temp2		x		y
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, 8
			POP	edx
			MOV	edx, [esi]
			POP	esi
			MOV	eax, edx
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, 12
			POP	edx
			MOV	edx, [esi]
			POP	esi
			MOV	ebx, edx
			CDQ
			IDIV	ebx
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -28
			POP	edx
			MOV[esi], eax
			; Assign		MULTK		Temp2		Temp2		y
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
			ADD	esi, 12
			POP	edx
			MOV	edx, [esi]
			POP	esi
			MOV	ebx, edx
			IMUL	eax, ebx
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -28
			POP	edx
			MOV[esi], eax
			; Assign		SUBTK		Temp2		x		Temp2
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, 8
			POP	edx
			MOV	edx, [esi]
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
			ADD	esi, -28
			POP	edx
			MOV[esi], eax
			; Assign		SETTK		mymod		Temp2
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -28
			POP	edx
			MOV	edx, [esi]
			POP	esi
			MOV	eax, edx
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -24
			POP	edx
			MOV[esi], eax
			MOV	eax, [ebp - 24]
			POP	edi
			POP	esi
			POP	edx
			POP	ecx
			POP	ebx
			MOV	esp, ebp
			POP	ebp
			RET



			; NODE: 3
			; FP:(3)		fp_swap_3
		fp_swap_3 :
		PUSH	ebp
			MOV	ebp, esp
			PUSH	eax
			PUSH	ebx
			PUSH	ecx
			PUSH	edx
			PUSH	esi
			PUSH	edi
			SUB	esp, 4
			; Assign		SETTK		temp		x
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			; add display offset to esi :
		ADD	esi, 8
			; display is to esi :
		MOV	esi, [esi]
			ADD	esi, -32
			POP	edx
			MOV	edx, [esi]
			POP	esi
			MOV	eax, edx
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -28
			POP	edx
			MOV[esi], eax
			; Assign		SETTK		x		y
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			; add display offset to esi :
		ADD	esi, 8
			; display is to esi :
		MOV	esi, [esi]
			ADD	esi, -36
			POP	edx
			MOV	edx, [esi]
			POP	esi
			MOV	eax, edx
			PUSH	edx
			MOV	esi, ebp
			; add display offset to esi :
		ADD	esi, 8
			; display is to esi :
		MOV	esi, [esi]
			ADD	esi, -32
			POP	edx
			MOV[esi], eax
			; Assign		SETTK		y		temp
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -28
			POP	edx
			MOV	edx, [esi]
			POP	esi
			MOV	eax, edx
			PUSH	edx
			MOV	esi, ebp
			; add display offset to esi :
		ADD	esi, 8
			; display is to esi :
		MOV	esi, [esi]
			ADD	esi, -36
			POP	edx
			MOV[esi], eax
			POP	edi
			POP	esi
			POP	edx
			POP	ecx
			POP	ebx
			POP	eax
			MOV	esp, ebp
			POP	ebp
			RET

		ENDPOINT :
	}
	return 0;
}
