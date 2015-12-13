#pragma warning(disable:4996)
#include <stdio.h>
char _string[] = "%s";
char _value[] = "%d";
char _charac[] = "%c";
char in_string0[] = "i = ";
char in_string1[] = "char integer const var for if array of ";
char in_string2[] = "Compile error";
char in_string3[] = "Sub check passed";
char in_string4[] = "result > 10";
char in_string5[] = "Compile error";
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
			PUSH	10
			PUSH - 5
			PUSH	1
			PUSH	122
			SUB	esp, 136
			; Assign		SETTK		e		63
			PUSH	esi
			MOV	edx, 63
			POP	esi
			MOV	eax, edx
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -32
			POP	edx
			MOV[esi], eax
			; Assign		MULTK		Temp56		e		4
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -32
			POP	edx
			MOV	edx, [esi]
			POP	esi
			MOV	eax, edx
			PUSH	esi
			MOV	edx, 4
			POP	esi
			MOV	ebx, edx
			IMUL	eax, ebx
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -112
			POP	edx
			MOV[esi], eax
			; Assign		MULTK		Temp58		e		2
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -32
			POP	edx
			MOV	edx, [esi]
			POP	esi
			MOV	eax, edx
			PUSH	esi
			MOV	edx, 2
			POP	esi
			MOV	ebx, edx
			IMUL	eax, ebx
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -116
			POP	edx
			MOV[esi], eax
			; Assign		DIVTK		Temp56		Temp56		Temp58
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -112
			POP	edx
			MOV	edx, [esi]
			POP	esi
			MOV	eax, edx
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -116
			POP	edx
			MOV	edx, [esi]
			POP	esi
			MOV	ebx, edx
			SUB	edx, edx
			IDIV	ebx
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -112
			POP	edx
			MOV[esi], eax
			; Call		fp_fact1_7		dst = Temp60		argc = 1
			MOV	esi, ebp
			ADD	esi, 8
			; MARK	esi, 8
			LEA	edi, [ebp - 4]
			PUSH	edi
			PUSH	3
			CALL	fp_fact1_7
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -120
			POP	edx
			MOV[esi], eax
			ADD	esp, 8
			; Assign		ADDTK		Temp56		Temp56		Temp60
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -112
			POP	edx
			MOV	edx, [esi]
			POP	esi
			MOV	eax, edx
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -120
			POP	edx
			MOV	edx, [esi]
			POP	esi
			MOV	ebx, edx
			ADD	eax, ebx
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -112
			POP	edx
			MOV[esi], eax
			; Assign		SETTK		result		Temp56
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -112
			POP	edx
			MOV	edx, [esi]
			POP	esi
			MOV	eax, edx
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -84
			POP	edx
			MOV[esi], eax
			; SMALLEQUTK		Condition		SMALLEQUTK		result		10		Label13
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -84
			POP	edx
			MOV	edx, [esi]
			POP	esi
			MOV	eax, edx
			PUSH	esi
			MOV	edx, 10
			POP	esi
			MOV	ebx, edx
			CMP	eax, ebx
			JNG	Label13
			; Write		String4
			LEA	eax, in_string4
			LEA	ebx, _string
			PUSH	eax
			PUSH	ebx
			CALL	printf
			ADD	esp, 8
			; Goto:		Label14
			JMP	Label14
			; Label:		Label13
		Label13 :
		; Label:		Label14
		Label14 :
		; Call		fp_prime_9		dst = Temp62		argc = 0
			MOV	esi, ebp
			ADD	esi, 8
			; MARK	esi, 8
			LEA	edi, [ebp - 4]
			PUSH	edi
			CALL	fp_prime_9
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -124
			POP	edx
			MOV[esi], eax
			ADD	esp, 4
			; Assign		SETTK		iprime		Temp62
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -124
			POP	edx
			MOV	edx, [esi]
			POP	esi
			MOV	eax, edx
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -88
			POP	edx
			MOV[esi], eax
			; Call		fp_prime_9		dst = Temp63		argc = 0
			MOV	esi, ebp
			ADD	esi, 8
			; MARK	esi, 8
			LEA	edi, [ebp - 4]
			PUSH	edi
			CALL	fp_prime_9
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -128
			POP	edx
			MOV[esi], eax
			ADD	esp, 4
			; Call		fp_fact1_7		dst = Temp64		argc = 1
			MOV	esi, ebp
			ADD	esi, 8
			; MARK	esi, 8
			LEA	edi, [ebp - 4]
			PUSH	edi
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -128
			POP	edx
			MOV	edx, [esi]
			POP	esi
			PUSH	edx
			CALL	fp_fact1_7
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -132
			POP	edx
			MOV[esi], eax
			ADD	esp, 8
			; Assign		SETTK		ans1		Temp64
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -132
			POP	edx
			MOV	edx, [esi]
			POP	esi
			MOV	eax, edx
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -92
			POP	edx
			MOV[esi], eax
			; Assign		ADDTK		Temp66		iprime		0
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -88
			POP	edx
			MOV	edx, [esi]
			POP	esi
			MOV	eax, edx
			PUSH	esi
			MOV	edx, 0
			POP	esi
			MOV	ebx, edx
			ADD	eax, ebx
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -136
			POP	edx
			MOV[esi], eax
			; Call		fp_fact2_8		dst = Temp67		argc = 1
			MOV	esi, ebp
			ADD	esi, 8
			; MARK	esi, 8
			LEA	edi, [ebp - 4]
			PUSH	edi
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -136
			POP	edx
			MOV	edx, [esi]
			POP	esi
			PUSH	edx
			CALL	fp_fact2_8
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -140
			POP	edx
			MOV[esi], eax
			ADD	esp, 8
			; Assign		SETTK		ans2		Temp67
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -140
			POP	edx
			MOV	edx, [esi]
			POP	esi
			MOV	eax, edx
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -96
			POP	edx
			MOV[esi], eax
			; abel:EQUTK		Condition		EQUTK		ans1		ans2		Label15
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -92
			POP	edx
			MOV	edx, [esi]
			POP	esi
			MOV	eax, edx
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -96
			POP	edx
			MOV	edx, [esi]
			POP	esi
			MOV	ebx, edx
			CMP	eax, ebx
			JE	Label15
			; Write		String5
			LEA	eax, in_string5
			LEA	ebx, _string
			PUSH	eax
			PUSH	ebx
			CALL	printf
			ADD	esp, 8
			; Goto:		Label16
			JMP	Label16
			; Label:		Label15
		Label15 :
		; Label:		Label16
		Label16 :
		; Call		fp_proc1_2(no ret)	argc = 0
			MOV	esi, ebp
			ADD	esi, 8
			; MARK	esi, 8
			LEA	edi, [ebp - 4]
			PUSH	edi
			CALL	fp_proc1_2
			ADD	esp, 4
			; Assign		SETTK		i		2
			PUSH	esi
			MOV	edx, 2
			POP	esi
			MOV	eax, edx
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -100
			POP	edx
			MOV[esi], eax
			; Label:		Label17
		Label17 :
		; Assign		SETTK		j		i
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -100
			POP	edx
			MOV	edx, [esi]
			POP	esi
			MOV	eax, edx
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -104
			POP	edx
			MOV[esi], eax
			; Label:		Label19
		Label19 :
		; Assign		ADDTK		Temp72		0		0
			PUSH	esi
			MOV	edx, 0
			POP	esi
			MOV	eax, edx
			PUSH	esi
			MOV	edx, 0
			POP	esi
			MOV	ebx, edx
			ADD	eax, ebx
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -144
			POP	edx
			MOV[esi], eax
			; Assign		ADDTK		Temp73		i		j
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -100
			POP	edx
			MOV	edx, [esi]
			POP	esi
			MOV	eax, edx
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -104
			POP	edx
			MOV	edx, [esi]
			POP	esi
			MOV	ebx, edx
			ADD	eax, ebx
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -148
			POP	edx
			MOV[esi], eax
			; Assign		SUBTK		Temp74		i		j
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -100
			POP	edx
			MOV	edx, [esi]
			POP	esi
			MOV	eax, edx
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -104
			POP	edx
			MOV	edx, [esi]
			POP	esi
			MOV	ebx, edx
			SUB	eax, ebx
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -152
			POP	edx
			MOV[esi], eax
			; Assign		SETTK		arr[Temp73]		Temp74
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -152
			POP	edx
			MOV	edx, [esi]
			POP	esi
			MOV	eax, edx
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -72
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -148
			POP	edx
			MOV	edx, [esi]
			POP	esi
			IMUL	edx, 4
			ADD	esi, edx
			POP	edx
			MOV[esi], eax
			; SMALLEQUTK		Condition		SMALLEQUTK		j		Temp72		Label20
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -104
			POP	edx
			MOV	edx, [esi]
			POP	esi
			MOV	eax, edx
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -144
			POP	edx
			MOV	edx, [esi]
			POP	esi
			MOV	ebx, edx
			CMP	eax, ebx
			JNG	Label20
			; Assign		SUBTK		j		j		1
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -104
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
			ADD	esi, -104
			POP	edx
			MOV[esi], eax
			; Goto:		Label19
			JMP	Label19
			; Label:		Label20
		Label20 :
		; Label:LARGEEQUTK		Condition		LARGEEQUTK		i		5		Label18
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -100
			POP	edx
			MOV	edx, [esi]
			POP	esi
			MOV	eax, edx
			PUSH	esi
			MOV	edx, 5
			POP	esi
			MOV	ebx, edx
			CMP	eax, ebx
			JNL	Label18
			; Assign		ADDTK		i		i		1
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -100
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
			ADD	esi, -100
			POP	edx
			MOV[esi], eax
			; Goto:		Label17
			JMP	Label17
			; Label:		Label18
		Label18 :
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
			; FP:(2)		fp_proc1_2
		fp_proc1_2 :
		PUSH	ebp
			MOV	ebp, esp
			PUSH	eax
			PUSH	ebx
			PUSH	ecx
			PUSH	edx
			PUSH	esi
			PUSH	edi
			SUB	esp, 84
			; Assign		SUBTK		Temp9		0		1
			PUSH	esi
			MOV	edx, 0
			POP	esi
			MOV	eax, edx
			PUSH	esi
			MOV	edx, 1
			POP	esi
			MOV	ebx, edx
			SUB	eax, ebx
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -52
			POP	edx
			MOV[esi], eax
			; Assign		SUBTK		Temp9		0		Temp9
			PUSH	esi
			MOV	edx, 0
			POP	esi
			MOV	eax, edx
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -52
			POP	edx
			MOV	edx, [esi]
			POP	esi
			MOV	ebx, edx
			SUB	eax, ebx
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -52
			POP	edx
			MOV[esi], eax
			; Assign		SETTK		t[0]		Temp9
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -52
			POP	edx
			MOV	edx, [esi]
			POP	esi
			MOV	eax, edx
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -40
			PUSH	esi
			MOV	edx, 0
			POP	esi
			IMUL	edx, 4
			ADD	esi, edx
			POP	edx
			MOV[esi], eax
			; Assign		MULTK		Temp14		18		3
			PUSH	esi
			MOV	edx, 18
			POP	esi
			MOV	eax, edx
			PUSH	esi
			MOV	edx, 3
			POP	esi
			MOV	ebx, edx
			IMUL	eax, ebx
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -56
			POP	edx
			MOV[esi], eax
			; Assign		DIVTK		Temp14		Temp14		6
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -56
			POP	edx
			MOV	edx, [esi]
			POP	esi
			MOV	eax, edx
			PUSH	esi
			MOV	edx, 6
			POP	esi
			MOV	ebx, edx
			SUB	edx, edx
			IDIV	ebx
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -56
			POP	edx
			MOV[esi], eax
			; Assign		SUBTK		Temp14		10		Temp14
			PUSH	esi
			MOV	edx, 10
			POP	esi
			MOV	eax, edx
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -56
			POP	edx
			MOV	edx, [esi]
			POP	esi
			MOV	ebx, edx
			SUB	eax, ebx
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -56
			POP	edx
			MOV[esi], eax
			; Assign		SETTK		t[1]		Temp14
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
			PUSH	esi
			MOV	edx, 1
			POP	esi
			IMUL	edx, 4
			ADD	esi, edx
			POP	edx
			MOV[esi], eax
			; Assign		SUBTK		Temp19		2		0
			PUSH	esi
			MOV	edx, 2
			POP	esi
			MOV	eax, edx
			PUSH	esi
			MOV	edx, 0
			POP	esi
			MOV	ebx, edx
			SUB	eax, ebx
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -60
			POP	edx
			MOV[esi], eax
			; Assign		SUBTK		Temp19		Temp19		0
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -60
			POP	edx
			MOV	edx, [esi]
			POP	esi
			MOV	eax, edx
			PUSH	esi
			MOV	edx, 0
			POP	esi
			MOV	ebx, edx
			SUB	eax, ebx
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -60
			POP	edx
			MOV[esi], eax
			; Assign		SETTK		t[2]		Temp19
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -60
			POP	edx
			MOV	edx, [esi]
			POP	esi
			MOV	eax, edx
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -40
			PUSH	esi
			MOV	edx, 2
			POP	esi
			IMUL	edx, 4
			ADD	esi, edx
			POP	edx
			MOV[esi], eax
			; Assign		DIVTK		Temp23		6		2
			PUSH	esi
			MOV	edx, 6
			POP	esi
			MOV	eax, edx
			PUSH	esi
			MOV	edx, 2
			POP	esi
			MOV	ebx, edx
			SUB	edx, edx
			IDIV	ebx
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -64
			POP	edx
			MOV[esi], eax
			; Assign		SETTK		i		Temp23
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
			; Label:		Label0
		Label0 :
		; Assign		ADDTK		Temp26		2		4
			PUSH	esi
			MOV	edx, 2
			POP	esi
			MOV	eax, edx
			PUSH	esi
			MOV	edx, 4
			POP	esi
			MOV	ebx, edx
			ADD	eax, ebx
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -68
			POP	edx
			MOV[esi], eax
			; Assign		SUBTK		Temp28		i		1
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -44
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
			ADD	esi, -72
			POP	edx
			MOV[esi], eax
			; Assign		SUBTK		Temp30		i		2
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -44
			POP	edx
			MOV	edx, [esi]
			POP	esi
			MOV	eax, edx
			PUSH	esi
			MOV	edx, 2
			POP	esi
			MOV	ebx, edx
			SUB	eax, ebx
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -76
			POP	edx
			MOV[esi], eax
			; Assign		ADDTK		Temp31		t[Temp28]		t[Temp30]
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -40
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -72
			POP	edx
			MOV	edx, [esi]
			POP	esi
			IMUL	edx, 4
			ADD	esi, edx
			POP	edx
			MOV	edx, [esi]
			POP	esi
			MOV	eax, edx
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -40
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -76
			POP	edx
			MOV	edx, [esi]
			POP	esi
			IMUL	edx, 4
			ADD	esi, edx
			POP	edx
			MOV	edx, [esi]
			POP	esi
			MOV	ebx, edx
			ADD	eax, ebx
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -80
			POP	edx
			MOV[esi], eax
			; Assign		SETTK		t[i]		Temp31
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -80
			POP	edx
			MOV	edx, [esi]
			POP	esi
			MOV	eax, edx
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -40
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -44
			POP	edx
			MOV	edx, [esi]
			POP	esi
			IMUL	edx, 4
			ADD	esi, edx
			POP	edx
			MOV[esi], eax
			; Label:LARGEEQUTK		Condition		LARGEEQUTK		i		Temp26		Label1
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -44
			POP	edx
			MOV	edx, [esi]
			POP	esi
			MOV	eax, edx
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -68
			POP	edx
			MOV	edx, [esi]
			POP	esi
			MOV	ebx, edx
			CMP	eax, ebx
			JNL	Label1
			; Assign		ADDTK		i		i		1
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -44
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
			ADD	esi, -44
			POP	edx
			MOV[esi], eax
			; Goto:		Label0
			JMP	Label0
			; Label:		Label1
		Label1 :
		; Assign		MULTK		Temp34		2		3
			PUSH	esi
			MOV	edx, 2
			POP	esi
			MOV	eax, edx
			PUSH	esi
			MOV	edx, 3
			POP	esi
			MOV	ebx, edx
			IMUL	eax, ebx
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -84
			POP	edx
			MOV[esi], eax
			; Label:LARGEEQUTK		Condition		LARGEEQUTK		i		Temp34		Label2
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -44
			POP	edx
			MOV	edx, [esi]
			POP	esi
			MOV	eax, edx
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -84
			POP	edx
			MOV	edx, [esi]
			POP	esi
			MOV	ebx, edx
			CMP	eax, ebx
			JNL	Label2
			; Write		String2
			LEA	eax, in_string2
			LEA	ebx, _string
			PUSH	eax
			PUSH	ebx
			CALL	printf
			ADD	esp, 8
			; Goto:		Label3
			JMP	Label3
			; Label:		Label2
		Label2 :
		; Label:		Label3
		Label3 :
		; Assign		SETTK		tmp		t[2]
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -40
			PUSH	esi
			MOV	edx, 2
			POP	esi
			IMUL	edx, 4
			ADD	esi, edx
			POP	edx
			MOV	edx, [esi]
			POP	esi
			MOV	eax, edx
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -48
			POP	edx
			MOV[esi], eax
			; Call		fp_proc2_3(no ret)	argc = 3
			MOV	esi, ebp
			ADD	esi, 12
			PUSH[esi - 4]
			; MARK[esi - 4]
			LEA	edi, [ebp - 4]
			PUSH	edi
			PUSH	edx
			MOV	esi, ebp
			; add display offset to esi :
		ADD	esi, 8
			; display is to esi :
		MOV	esi, [esi]
			POP	edx
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -40
			PUSH	esi
			MOV	edx, 1
			POP	esi
			IMUL	edx, 4
			ADD	esi, edx
			POP	edx
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -40
			PUSH	esi
			MOV	edx, 2
			POP	esi
			IMUL	edx, 4
			ADD	esi, edx
			POP	edx
			PUSH	esi
			CALL	fp_proc2_3
			ADD	esp, 20
			; abel:EQUTK		Condition		EQUTK		t[2]		tmp		Label4
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -40
			PUSH	esi
			MOV	edx, 2
			POP	esi
			IMUL	edx, 4
			ADD	esi, edx
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
			CMP	eax, ebx
			JE	Label4
			; Write		String3
			LEA	eax, in_string3
			LEA	ebx, _string
			PUSH	eax
			PUSH	ebx
			CALL	printf
			ADD	esp, 8
			; Goto:		Label5
			JMP	Label5
			; Label:		Label4
		Label4 :
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
			RET



			; NODE: 3
			; FP:(3)		fp_proc2_3
		fp_proc2_3 :
		PUSH	ebp
			MOV	ebp, esp
			PUSH	eax
			PUSH	ebx
			PUSH	ecx
			PUSH	edx
			PUSH	esi
			PUSH	edi
			SUB	esp, 8
			; Assign		SUBTK		Temp3		0		b1
			PUSH	esi
			MOV	edx, 0
			POP	esi
			MOV	eax, edx
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			; add display offset to esi :
		ADD	esi, 24
			; display is to esi :
		MOV	esi, [esi]
			POP	edx
			MOV	edx, [esi]
			POP	esi
			MOV	ebx, edx
			SUB	eax, ebx
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -4
			POP	edx
			MOV[esi], eax
			; Assign		ADDTK		Temp3		a2		Temp3
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			; add display offset to esi :
		ADD	esi, 24
			; display is to esi :
		MOV	esi, [esi]
			POP	edx
			MOV	edx, [esi]
			POP	esi
			MOV	eax, edx
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -4
			POP	edx
			MOV	edx, [esi]
			POP	esi
			MOV	ebx, edx
			ADD	eax, ebx
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -4
			POP	edx
			MOV[esi], eax
			; Assign		SETTK		a2		Temp3
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -4
			POP	edx
			MOV	edx, [esi]
			POP	esi
			MOV	eax, edx
			PUSH	edx
			MOV	esi, ebp
			; add display offset to esi :
		ADD	esi, 24
			; display is to esi :
		MOV	esi, [esi]
			POP	edx
			MOV[esi], eax
			; Write		String1
			LEA	eax, in_string1
			LEA	ebx, _string
			PUSH	eax
			PUSH	ebx
			CALL	printf
			ADD	esp, 8
			; Assign		ADDTK		Temp6		1		10
			PUSH	esi
			MOV	edx, 1
			POP	esi
			MOV	eax, edx
			PUSH	esi
			MOV	edx, 10
			POP	esi
			MOV	ebx, edx
			ADD	eax, ebx
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -8
			POP	edx
			MOV[esi], eax
			; Write		Temp6
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -8
			POP	edx
			MOV	edx, [esi]
			POP	esi
			MOV	eax, edx
			LEA	ebx, _value
			PUSH	eax
			PUSH	ebx
			CALL	printf
			ADD	esp, 8
			; Write		c1
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			; add display offset to esi :
		ADD	esi, 24
			; display is to esi :
		MOV	esi, [esi]
			POP	edx
			MOV	edx, [esi]
			POP	esi
			MOV	eax, edx
			LEA	ebx, _value
			PUSH	eax
			PUSH	ebx
			CALL	printf
			ADD	esp, 8
			; Call		fp_proc3_4(no ret)	argc = 0
			MOV	esi, ebp
			ADD	esi, 28
			PUSH[esi - 4]
			PUSH[esi - 8]
			; MARK[esi - 8]
			LEA	edi, [ebp - 4]
			PUSH	edi
			CALL	fp_proc3_4
			ADD	esp, 12
			POP	edi
			POP	esi
			POP	edx
			POP	ecx
			POP	ebx
			POP	eax
			MOV	esp, ebp
			POP	ebp
			RET



			; NODE: 4
			; FP:(4)		fp_proc3_4
		fp_proc3_4 :
		PUSH	ebp
			MOV	ebp, esp
			PUSH	eax
			PUSH	ebx
			PUSH	ecx
			PUSH	edx
			PUSH	esi
			PUSH	edi
			SUB	esp, 4
			; Assign		SETTK		tmp		10
			PUSH	esi
			MOV	edx, 10
			POP	esi
			MOV	eax, edx
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -4
			POP	edx
			MOV[esi], eax
			; Write		String0
			LEA	eax, in_string0
			LEA	ebx, _string
			PUSH	eax
			PUSH	ebx
			CALL	printf
			ADD	esp, 8
			; Write		i
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			; add display offset to esi :
		ADD	esi, 12
			; display is to esi :
		MOV	esi, [esi]
			POP	edx
			MOV	edx, [esi]
			POP	esi
			MOV	eax, edx
			LEA	ebx, _value
			PUSH	eax
			PUSH	ebx
			CALL	printf
			ADD	esp, 8
			; Write		tmp
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -4
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
			RET



			; NODE: 5
			; FP:(5)		fp_proc2_5
		fp_proc2_5 :
		PUSH	ebp
			MOV	ebp, esp
			PUSH	eax
			PUSH	ebx
			PUSH	ecx
			PUSH	edx
			PUSH	esi
			PUSH	edi
			SUB	esp, 0
			POP	edi
			POP	esi
			POP	edx
			POP	ecx
			POP	ebx
			POP	eax
			MOV	esp, ebp
			POP	ebp
			RET



			; NODE: 6
			; FP:(6)		fp_proc3_6
		fp_proc3_6 :
		PUSH	ebp
			MOV	ebp, esp
			PUSH	eax
			PUSH	ebx
			PUSH	ecx
			PUSH	edx
			PUSH	esi
			PUSH	edi
			SUB	esp, 0
			POP	edi
			POP	esi
			POP	edx
			POP	ecx
			POP	ebx
			POP	eax
			MOV	esp, ebp
			POP	ebp
			RET



			; NODE: 7
			; FP:(7)		fp_fact1_7
		fp_fact1_7 :
		PUSH	ebp
			MOV	ebp, esp
			PUSH	ebx
			PUSH	ecx
			PUSH	edx
			PUSH	esi
			PUSH	edi
			SUB	esp, 12
			; Label:LARGEEQUTK		Condition		LARGEEQUTK		0		0		Label6
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, 8
			POP	edx
			MOV	edx, [esi]
			POP	esi
			MOV	eax, edx
			PUSH	esi
			MOV	edx, 0
			POP	esi
			MOV	ebx, edx
			CMP	eax, ebx
			JNL	Label6
			; Assign		SETTK		0		0
			PUSH	esi
			MOV	edx, 0
			POP	esi
			MOV	eax, edx
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, 8
			POP	edx
			MOV[esi], eax
			; Goto:		Label7
			JMP	Label7
			; Label:		Label6
		Label6 :
		; Label:		Label7
		Label7 :
		; bel:NEQUTK		Condition		NEQUTK		0		0		Label8
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, 8
			POP	edx
			MOV	edx, [esi]
			POP	esi
			MOV	eax, edx
			PUSH	esi
			MOV	edx, 0
			POP	esi
			MOV	ebx, edx
			CMP	eax, ebx
			JNE	Label8
			; Assign		SETTK		fact1		1
			PUSH	esi
			MOV	edx, 1
			POP	esi
			MOV	eax, edx
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -4
			POP	edx
			MOV[esi], eax
			; Goto:		Label9
			JMP	Label9
			; Label:		Label8
		Label8 :
		; Assign		SUBTK		Temp44		0		1
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
			SUB	eax, ebx
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -8
			POP	edx
			MOV[esi], eax
			; Call		fp_fact1_7		dst = Temp45		argc = 1
			MOV	esi, ebp
			ADD	esi, 16
			PUSH[esi - 4]
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -8
			POP	edx
			MOV	edx, [esi]
			POP	esi
			PUSH	edx
			CALL	fp_fact1_7
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -12
			POP	edx
			MOV[esi], eax
			ADD	esp, 8
			; Assign		MULTK		Temp45		Temp45		0
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -12
			POP	edx
			MOV	edx, [esi]
			POP	esi
			MOV	eax, edx
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, 8
			POP	edx
			MOV	edx, [esi]
			POP	esi
			MOV	ebx, edx
			IMUL	eax, ebx
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -12
			POP	edx
			MOV[esi], eax
			; Assign		SETTK		fact1		Temp45
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -12
			POP	edx
			MOV	edx, [esi]
			POP	esi
			MOV	eax, edx
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -4
			POP	edx
			MOV[esi], eax
			; Label:		Label9
		Label9 :
		MOV	eax, [ebp - 4]
			POP	edi
			POP	esi
			POP	edx
			POP	ecx
			POP	ebx
			MOV	esp, ebp
			POP	ebp
			RET



			; NODE: 8
			; FP:(8)		fp_fact2_8
		fp_fact2_8 :
		PUSH	ebp
			MOV	ebp, esp
			PUSH	ebx
			PUSH	ecx
			PUSH	edx
			PUSH	esi
			PUSH	edi
			SUB	esp, 16
			; LARGETK		Condition		LARGETK		0		1		Label10
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
			CMP	eax, ebx
			JG	Label10
			; Assign		SETTK		0		1
			PUSH	esi
			MOV	edx, 1
			POP	esi
			MOV	eax, edx
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, 8
			POP	edx
			MOV[esi], eax
			; Goto:		Label11
			JMP	Label11
			; Label:		Label10
		Label10 :
		; Label:		Label11
		Label11 :
		; Assign		SETTK		temp		1
			PUSH	esi
			MOV	edx, 1
			POP	esi
			MOV	eax, edx
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -8
			POP	edx
			MOV[esi], eax
			; Label:		Label12
		Label12 :
		; Assign		MULTK		Temp49		temp		0
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -8
			POP	edx
			MOV	edx, [esi]
			POP	esi
			MOV	eax, edx
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, 8
			POP	edx
			MOV	edx, [esi]
			POP	esi
			MOV	ebx, edx
			IMUL	eax, ebx
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -12
			POP	edx
			MOV[esi], eax
			; Assign		SETTK		temp		Temp49
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -12
			POP	edx
			MOV	edx, [esi]
			POP	esi
			MOV	eax, edx
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -8
			POP	edx
			MOV[esi], eax
			; Assign		SUBTK		Temp51		0		1
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
			SUB	eax, ebx
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -16
			POP	edx
			MOV[esi], eax
			; Assign		SETTK		0		Temp51
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -16
			POP	edx
			MOV	edx, [esi]
			POP	esi
			MOV	eax, edx
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, 8
			POP	edx
			MOV[esi], eax
			; Label:LARGEEQUTK		Condition		LARGEEQUTK		0		1		Label12
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
			CMP	eax, ebx
			JNL	Label12
			; Assign		SETTK		fact2		temp
			PUSH	esi
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -8
			POP	edx
			MOV	edx, [esi]
			POP	esi
			MOV	eax, edx
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -4
			POP	edx
			MOV[esi], eax
			MOV	eax, [ebp - 4]
			POP	edi
			POP	esi
			POP	edx
			POP	ecx
			POP	ebx
			MOV	esp, ebp
			POP	ebp
			RET



			; NODE: 9
			; FP:(9)		fp_prime_9
		fp_prime_9 :
		PUSH	ebp
			MOV	ebp, esp
			PUSH	ebx
			PUSH	ecx
			PUSH	edx
			PUSH	esi
			PUSH	edi
			SUB	esp, 4
			; Assign		SETTK		prime		7
			PUSH	esi
			MOV	edx, 7
			POP	esi
			MOV	eax, edx
			PUSH	edx
			MOV	esi, ebp
			ADD	esi, -4
			POP	edx
			MOV[esi], eax
			MOV	eax, [ebp - 4]
			POP	edi
			POP	esi
			POP	edx
			POP	ecx
			POP	ebx
			MOV	esp, ebp
			POP	ebp
			RET

		ENDPOINT :
	}
	return 0;
}
