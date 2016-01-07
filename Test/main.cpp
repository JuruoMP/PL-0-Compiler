#pragma warning(disable:4996)
#include <stdio.h>
char _string[] = "%s";
char _value[] = "%d";
char _characr[] = " %c";
char _characw[] = "%c";
char in_string0[] = "PASS3 ";
char in_string1[] = "FAILE3 ";
char in_string2[] = "PASS2 ";
char in_string3[] = "FAILE2 ";
char in_string4[] = "PASS1 ";
char in_string5[] = "FAILE1 ";
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
			;; NOP	SetBegin
			PUSH	esi
			MOV	edx, 1
			POP	esi
			MOV	eax, edx
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -28
			POP	edx
			MOV[esi], eax
			; Call		fp_p1_5(no ret)	argc = 1
			MOV	esi, ebp
			ADD	esi, 8
			LEA	edi, [ebp]
			PUSH	edi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -28
			POP	edx
			PUSH	esi
			CALL	fp_p1_5
			ADD	esp, 8
			; bel:NEQUTK		Condition		NEQUTK		a1		4		Label4
			PUSH	esi
			MOV	esi, ebp
			ADD	esi, -28
			MOV	edx, [esi]
			POP	esi
			MOV	eax, edx
			MOV	edx, 4
			MOV	ebx, edx
			CMP	eax, ebx
			JNE	Label4
			; Write		String4
			LEA	eax, in_string4
			LEA	ebx, dword ptr[_string]
			PUSH	eax
			PUSH	ebx
			CALL	printf
			ADD	esp, 8
			; Goto:		Label5
			JMP	Label5
			; Label:		Label4
		Label4 :
		; Write		String5
			LEA	eax, in_string5
			LEA	ebx, dword ptr[_string]
			PUSH	eax
			PUSH	ebx
			CALL	printf
			ADD	esp, 8
			; Label:		Label5
		Label5 :
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
			; FP:(2)		fp_f1_2
		fp_f1_2 :
		PUSH	ebp
			MOV	ebp, esp
			PUSH	ebx
			PUSH	ecx
			PUSH	edx
			PUSH	esi
			PUSH	edi
			SUB	esp, 16
			;; NOP	SetBegin
			; Call		fp_f2_3		dst = Temp8		argc = 1
			MOV	esi, ebp
			ADD	esi, 16
			PUSH[esi - 4]
			LEA	edi, [ebp]
			PUSH	edi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, 8
			MOV	esi, [esi]
			POP	edx
			PUSH	esi
			CALL	fp_f2_3
			MOV	esi, ebp
			ADD	esi, -32
			MOV[esi], eax
			ADD	esp, 12
			; Assign		SETTK		a1		Temp8
			PUSH	esi
			MOV	esi, ebp
			ADD	esi, -32
			MOV	edx, [esi]
			POP	esi
			MOV	eax, edx
			MOV	esi, ebp
			ADD	esi, -28
			MOV[esi], eax
			;; NOP	SetEnd
			;; NOP	SetBegin
			PUSH	esi
			MOV	esi, ebp
			ADD	esi, 8
			MOV	esi, [esi]
			MOV	edx, [esi]
			POP	esi
			MOV	eax, edx
			MOV	edx, 1
			MOV	ebx, edx
			ADD	eax, ebx
			MOV	esi, ebp
			ADD	esi, -36
			MOV[esi], eax
			PUSH	esi
			MOV	esi, ebp
			ADD	esi, -36
			MOV	edx, [esi]
			POP	esi
			MOV	eax, edx
			MOV	esi, ebp
			ADD	esi, 8
			MOV	esi, [esi]
			MOV[esi], eax
			; Call		fp_p2_4(no ret)	argc = 1
			MOV	esi, ebp
			ADD	esi, 16
			PUSH[esi - 4]
			LEA	edi, [ebp]
			PUSH	edi
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, 8
			MOV	esi, [esi]
			POP	edx
			MOV	edx, [esi]
			POP	esi
			PUSH	edx
			CALL	fp_p2_4
			ADD	esp, 12
			;; NOP	SetBegin
			MOV	edx, 5
			MOV	eax, edx
			MOV	esi, ebp
			ADD	esi, -24
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
			; FP:(3)		fp_f2_3
		fp_f2_3 :
		PUSH	ebp
			MOV	ebp, esp
			PUSH	ebx
			PUSH	edx
			PUSH	esi
			SUB	esp, 8
			;; NOP	SetBegin
			PUSH	esi
			MOV	esi, ebp
			ADD	esi, 8
			MOV	esi, [esi]
			MOV	edx, [esi]
			POP	esi
			MOV	eax, edx
			MOV	edx, 1
			MOV	ebx, edx
			ADD	eax, ebx
			MOV	esi, ebp
			ADD	esi, -28
			MOV[esi], eax
			PUSH	esi
			MOV	esi, ebp
			ADD	esi, -28
			MOV	edx, [esi]
			POP	esi
			MOV	eax, edx
			MOV	esi, ebp
			ADD	esi, 8
			MOV	esi, [esi]
			MOV[esi], eax
			;; NOP	SetBegin
			MOV	edx, 5
			MOV	eax, edx
			MOV	esi, ebp
			ADD	esi, -24
			MOV[esi], eax
			MOV	eax, [ebp - 24]
			POP	esi
			POP	edx
			POP	ebx
			MOV	esp, ebp
			POP	ebp
			RET



			; NODE: 4
			; FP:(4)		fp_p2_4
		fp_p2_4 :
		PUSH	ebp
			MOV	ebp, esp
			PUSH	eax
			PUSH	ebx
			PUSH	ecx
			PUSH	edx
			PUSH	esi
			PUSH	edi
			SUB	esp, 4
			;; NOP	SetBegin
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, 8
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
			ADD	esi, 8
			POP	edx
			MOV[esi], eax
			; bel:NEQUTK		Condition		NEQUTK		a1		5		Label0
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			; add display offset to esi :
		ADD	esi, 12
			; display is to esi :
		MOV	esi, [esi]
			ADD	esi, -28
			POP	edx
			MOV	edx, [esi]
			POP	esi
			MOV	eax, edx
			PUSH	esi
			MOV	edx, 5
			POP	esi
			MOV	ebx, edx
			CMP	eax, ebx
			JNE	Label0
			; Write		String0
			LEA	eax, in_string0
			LEA	ebx, dword ptr[_string]
			PUSH	eax
			PUSH	ebx
			CALL	printf
			ADD	esp, 8
			; Goto:		Label1
			JMP	Label1
			; Label:		Label0
		Label0 :
		; Write		String1
			LEA	eax, in_string1
			LEA	ebx, dword ptr[_string]
			PUSH	eax
			PUSH	ebx
			CALL	printf
			ADD	esp, 8
			; Label:		Label1
		Label1 :
		POP	edi
			POP	esi
			POP	edx
			POP	ecx
			POP	ebx
			POP	eax
			MOV	esp, ebp
			POP	ebp
			RET



			; NODE: 5
			; FP:(5)		fp_p1_5
		fp_p1_5 :
		PUSH	ebp
			MOV	ebp, esp
			PUSH	eax
			PUSH	ebx
			PUSH	ecx
			PUSH	edx
			PUSH	esi
			PUSH	edi
			SUB	esp, 12
			;; NOP	SetBegin
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, 8
			MOV	esi, [esi]
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
			ADD	esi, -32
			POP	edx
			MOV[esi], eax
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
			ADD	esi, 8
			MOV	esi, [esi]
			POP	edx
			MOV[esi], eax
			;; NOP	SetBegin
			; Call		fp_f1_2		dst = Temp14		argc = 1
			MOV	esi, ebp
			ADD	esi, 16
			PUSH[esi - 4]
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, 8
			MOV	esi, [esi]
			POP	edx
			PUSH	esi
			CALL	fp_f1_2
			MOV	esi, ebp
			ADD	esi, -36
			MOV[esi], eax
			ADD	esp, 8
			; Assign		SETTK		e2		Temp14
			PUSH	esi
			MOV	esi, ebp
			ADD	esi, -36
			MOV	edx, [esi]
			POP	esi
			MOV	eax, edx
			MOV	esi, ebp
			ADD	esi, -28
			MOV[esi], eax
			;; NOP	SetEnd
			; bel:NEQUTK		Condition		NEQUTK		e2		5		Label2
			PUSH	esi
			MOV	esi, ebp
			ADD	esi, -28
			MOV	edx, [esi]
			POP	esi
			MOV	eax, edx
			MOV	edx, 5
			MOV	ebx, edx
			CMP	eax, ebx
			JNE	Label2
			; Write		String2
			LEA	eax, in_string2
			LEA	ebx, dword ptr[_string]
			PUSH	eax
			PUSH	ebx
			CALL	printf
			ADD	esp, 8
			; Goto:		Label3
			JMP	Label3
			; Label:		Label2
		Label2 :
		; Write		String3
			LEA	eax, in_string3
			LEA	ebx, dword ptr[_string]
			PUSH	eax
			PUSH	ebx
			CALL	printf
			ADD	esp, 8
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
			RET

		ENDPOINT :
	}
	return 0;
}
