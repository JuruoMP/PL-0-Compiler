#pragma warning(disable:4996)
#include <stdio.h>
char _string[] = "%s";
char _value[] = "%d";
char _characr[] = " %c";
char _characw[] = "%c";
char in_string0[] = "\n";
char in_string1[] = "\n";
char in_string2[] = "catalan(n) = C(2n, n) / (n + 1)\n";
char in_string3[] = "cannot output such a big number";
char in_string4[] = "Tips: the number is between 1 to 10, good luck!\n";
char in_string5[] = "Input number:";
char in_string6[] = "Wrong, try again.\n";
char in_string7[] = "Correct, congratulations!";
char in_string8[] = ",";
char in_string9[] = "=";
char in_string10[] = ",";
char in_string11[] = "\n";
char in_string12[] = "Input n, output fibonacci(n):\n";
char in_string13[] = "Now we are going to paint a picture.\n";
char in_string14[] = "input size(int, <=6) & character(char):";
char in_string15[] = "n is too big";
char in_string16[] = "Input n(<=8), output Catalan(n):\n";
char in_string17[] = "\n";
char in_string18[] = "At last, let's play a game.\n";
char in_string19[] = "Guess what is the number I'm thinking.\n";
int main()
{
_asm{


;NODE : 1
;FP:(1)		fp_fp_main_1
fp_fp_main_1:
PUSH	ebp
MOV	ebp, esp
PUSH	eax
PUSH	ebx
PUSH	ecx
PUSH	edx
PUSH	esi
PUSH	edi
PUSH	97
PUSH	122
PUSH	65
PUSH	111
SUB	esp, 64
;;NOP	SetBegin
;Assign		SETTK		c1		ca		
PUSH	esi
PUSH	edx
MOV	esi, ebp
ADD	esi, -28
POP	edx
MOV	edx, [esi]
POP	esi
MOV	eax, edx
AND	eax, 0xff
PUSH	edx
MOV	esi, ebp
ADD	esi, -64
POP	edx
MOV	[esi], eax
;;NOP	SetEnd
;;NOP	SetBegin
;Assign		SUBTK		Temp34		cz		3
PUSH	esi
PUSH	edx
MOV	esi, ebp
ADD	esi, -32
POP	edx
MOV	edx, [esi]
POP	esi
MOV	eax, edx
PUSH	esi
MOV	edx, 3
POP	esi
MOV	ebx, edx
SUB	eax, ebx
PUSH	edx
MOV	esi, ebp
ADD	esi, -84
POP	edx
MOV	[esi], eax
;Assign		SETTK		c2		Temp34		
PUSH	esi
PUSH	edx
MOV	esi, ebp
ADD	esi, -84
POP	edx
MOV	edx, [esi]
POP	esi
MOV	eax, edx
AND	eax, 0xff
PUSH	edx
MOV	esi, ebp
ADD	esi, -68
POP	edx
MOV	[esi], eax
;;NOP	SetEnd
;Write		c1
PUSH	esi
PUSH	edx
MOV	esi, ebp
ADD	esi, -64
POP	edx
MOV	edx, [esi]
POP	esi
MOV	eax, edx
LEA	ebx, dword ptr [_characw]
PUSH	eax
PUSH	ebx
CALL	printf
ADD	esp, 8
;Write		String8
LEA	eax, in_string8
LEA	ebx, dword ptr [_string]
PUSH	eax
PUSH	ebx
CALL	printf
ADD	esp, 8
;Write		c2
PUSH	esi
PUSH	edx
MOV	esi, ebp
ADD	esi, -68
POP	edx
MOV	edx, [esi]
POP	esi
MOV	eax, edx
LEA	ebx, dword ptr [_characw]
PUSH	eax
PUSH	ebx
CALL	printf
ADD	esp, 8
;Write		String9
LEA	eax, in_string9
LEA	ebx, dword ptr [_string]
PUSH	eax
PUSH	ebx
CALL	printf
ADD	esp, 8
;Assign		ADDTK		Temp36		ca		0
PUSH	esi
PUSH	edx
MOV	esi, ebp
ADD	esi, -28
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
ADD	esi, -88
POP	edx
MOV	[esi], eax
;Write		Temp36
PUSH	esi
PUSH	edx
MOV	esi, ebp
ADD	esi, -88
POP	edx
MOV	edx, [esi]
POP	esi
MOV	eax, edx
LEA	ebx, dword ptr [_value]
PUSH	eax
PUSH	ebx
CALL	printf
ADD	esp, 8
;Write		String10
LEA	eax, in_string10
LEA	ebx, dword ptr [_string]
PUSH	eax
PUSH	ebx
CALL	printf
ADD	esp, 8
;Assign		SUBTK		Temp38		cz		3
PUSH	esi
PUSH	edx
MOV	esi, ebp
ADD	esi, -32
POP	edx
MOV	edx, [esi]
POP	esi
MOV	eax, edx
PUSH	esi
MOV	edx, 3
POP	esi
MOV	ebx, edx
SUB	eax, ebx
PUSH	edx
MOV	esi, ebp
ADD	esi, -92
POP	edx
MOV	[esi], eax
;Write		Temp38
PUSH	esi
PUSH	edx
MOV	esi, ebp
ADD	esi, -92
POP	edx
MOV	edx, [esi]
POP	esi
MOV	eax, edx
LEA	ebx, dword ptr [_value]
PUSH	eax
PUSH	ebx
CALL	printf
ADD	esp, 8
;Write		String11
LEA	eax, in_string11
LEA	ebx, dword ptr [_string]
PUSH	eax
PUSH	ebx
CALL	printf
ADD	esp, 8
;Write		String12
LEA	eax, in_string12
LEA	ebx, dword ptr [_string]
PUSH	eax
PUSH	ebx
CALL	printf
ADD	esp, 8
;Read		n
PUSH	edx
MOV	esi, ebp
ADD	esi, -80
POP	edx
LEA	ebx, _value
PUSH	esi
PUSH	ebx
CALL	scanf
ADD	esp, 8
;Call		fp_calcfib_4		dst=Temp39		argc=1
MOV	esi, ebp
ADD	esi, 8
LEA	edi, [ebp]
PUSH	edi
PUSH	esi
PUSH	edx
MOV	esi, ebp
ADD	esi, -80
POP	edx
MOV	edx, [esi]
POP	esi
PUSH	edx
CALL	fp_calcfib_4		
PUSH	edx
MOV	esi, ebp
ADD	esi, -96
POP	edx
MOV	[esi], eax
ADD	esp, 8
;Write		Temp39
PUSH	esi
PUSH	edx
MOV	esi, ebp
ADD	esi, -96
POP	edx
MOV	edx, [esi]
POP	esi
MOV	eax, edx
LEA	ebx, dword ptr [_value]
PUSH	eax
PUSH	ebx
CALL	printf
ADD	esp, 8
;Write		String13
LEA	eax, in_string13
LEA	ebx, dword ptr [_string]
PUSH	eax
PUSH	ebx
CALL	printf
ADD	esp, 8
;Write		String14
LEA	eax, in_string14
LEA	ebx, dword ptr [_string]
PUSH	eax
PUSH	ebx
CALL	printf
ADD	esp, 8
;Read		n
PUSH	edx
MOV	esi, ebp
ADD	esi, -80
POP	edx
LEA	ebx, _value
PUSH	esi
PUSH	ebx
CALL	scanf
ADD	esp, 8
;Read		c
PUSH	edx
MOV	esi, ebp
ADD	esi, -60
POP	edx
LEA	ebx, _characr
PUSH	esi
PUSH	ebx
CALL	scanf
ADD	esp, 8
MOV	eax, [esi]
AND	eax, 0xff
MOV	[esi], eax
;SMALLEQUTK		Condition		SMALLEQUTK		n		6		Label28
PUSH	esi
PUSH	edx
MOV	esi, ebp
ADD	esi, -80
POP	edx
MOV	edx, [esi]
POP	esi
MOV	eax, edx
PUSH	esi
MOV	edx, 6
POP	esi
MOV	ebx, edx
CMP	eax, ebx
JNG	Label28
;Write		String15
LEA	eax, in_string15
LEA	ebx, dword ptr [_string]
PUSH	eax
PUSH	ebx
CALL	printf
ADD	esp, 8
;Goto:		Label29
JMP	Label29
;Label:		Label28
Label28:
;Call		fp_paint_5		(no ret)	argc=2
MOV	esi, ebp
ADD	esi, 8
LEA	edi, [ebp]
PUSH	edi
PUSH	esi
PUSH	edx
MOV	esi, ebp
ADD	esi, -60
POP	edx
MOV	edx, [esi]
POP	esi
PUSH	edx
PUSH	esi
PUSH	edx
MOV	esi, ebp
ADD	esi, -80
POP	edx
MOV	edx, [esi]
POP	esi
PUSH	edx
CALL	fp_paint_5		
ADD	esp, 12
;Label:		Label29
Label29:
;Write		String16
LEA	eax, in_string16
LEA	ebx, dword ptr [_string]
PUSH	eax
PUSH	ebx
CALL	printf
ADD	esp, 8
;Read		n
PUSH	edx
MOV	esi, ebp
ADD	esi, -80
POP	edx
LEA	ebx, _value
PUSH	esi
PUSH	ebx
CALL	scanf
ADD	esp, 8
;;NOP	SetBegin
;Call		fp_catalan_7		dst=Temp41		argc=1
MOV	esi, ebp
ADD	esi, 8
LEA	edi, [ebp]
PUSH	edi
PUSH	edx
MOV	esi, ebp
ADD	esi, -80
POP	edx
PUSH	esi
CALL	fp_catalan_7		
PUSH	edx
MOV	esi, ebp
ADD	esi, -100
POP	edx
MOV	[esi], eax
ADD	esp, 8
;Assign		SETTK		a		Temp41		
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
ADD	esi, -44
POP	edx
MOV	[esi], eax
;;NOP	SetEnd
;Assign		SUBTK		Temp43		0		1
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
ADD	esi, -104
POP	edx
MOV	[esi], eax
;abel:EQUTK		Condition		EQUTK		a		Temp43		Label30
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
ADD	esi, -104
POP	edx
MOV	edx, [esi]
POP	esi
MOV	ebx, edx
CMP	eax, ebx
JE	Label30
;Write		a
PUSH	esi
PUSH	edx
MOV	esi, ebp
ADD	esi, -44
POP	edx
MOV	edx, [esi]
POP	esi
MOV	eax, edx
LEA	ebx, dword ptr [_value]
PUSH	eax
PUSH	ebx
CALL	printf
ADD	esp, 8
;Goto:		Label31
JMP	Label31
;Label:		Label30
Label30:
;Label:		Label31
Label31:
;Write		String17
LEA	eax, in_string17
LEA	ebx, dword ptr [_string]
PUSH	eax
PUSH	ebx
CALL	printf
ADD	esp, 8
;Write		String18
LEA	eax, in_string18
LEA	ebx, dword ptr [_string]
PUSH	eax
PUSH	ebx
CALL	printf
ADD	esp, 8
;Write		String19
LEA	eax, in_string19
LEA	ebx, dword ptr [_string]
PUSH	eax
PUSH	ebx
CALL	printf
ADD	esp, 8
;Call		fp_game_9		(no ret)	argc=0
MOV	esi, ebp
ADD	esi, 8
LEA	edi, [ebp]
PUSH	edi
CALL	fp_game_9		
ADD	esp, 4
POP	edi
POP	esi
POP	edx
POP	ecx
POP	ebx
POP	eax
MOV	esp, ebp
POP	ebp
JMP	ENDPOINT



;NODE : 2
;FP:(2)		fp_swap_2
fp_swap_2:
PUSH	ebp
MOV	ebp, esp
PUSH	eax
PUSH	ebx
PUSH	ecx
PUSH	edx
PUSH	esi
PUSH	edi
SUB	esp, 4
;;NOP	SetBegin
;Assign		SETTK		temp		a		
PUSH	esi
PUSH	edx
MOV	esi, ebp
ADD	esi, 8
MOV	esi, [esi]
POP	edx
MOV	edx, [esi]
POP	esi
MOV	eax, edx
PUSH	edx
MOV	esi, ebp
ADD	esi, -28
POP	edx
MOV	[esi], eax
;;NOP	SetEnd
;;NOP	SetBegin
;Assign		SETTK		a		b		
PUSH	esi
PUSH	edx
MOV	esi, ebp
ADD	esi, 12
MOV	esi, [esi]
POP	edx
MOV	edx, [esi]
POP	esi
MOV	eax, edx
PUSH	edx
MOV	esi, ebp
ADD	esi, 8
MOV	esi, [esi]
POP	edx
MOV	[esi], eax
;;NOP	SetEnd
;;NOP	SetBegin
;Assign		SETTK		b		temp		
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
ADD	esi, 12
MOV	esi, [esi]
POP	edx
MOV	[esi], eax
;;NOP	SetEnd
POP	edi
POP	esi
POP	edx
POP	ecx
POP	ebx
POP	eax
MOV	esp, ebp
POP	ebp
RET	



;NODE : 3
;FP:(3)		fp_empty_3
fp_empty_3:
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



;NODE : 4
;FP:(4)		fp_calcfib_4
fp_calcfib_4:
PUSH	ebp
MOV	ebp, esp
PUSH	ebx
PUSH	ecx
PUSH	edx
PUSH	esi
PUSH	edi
SUB	esp, 24
;;NOP	SetBegin
;Assign		SETTK		num1		1		
PUSH	esi
MOV	edx, 1
POP	esi
MOV	eax, edx
PUSH	edx
MOV	esi, ebp
ADD	esi, -28
POP	edx
MOV	[esi], eax
;;NOP	SetEnd
;;NOP	SetBegin
;Assign		MULTK		Temp4		num1		1
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
IMUL	eax, ebx
PUSH	edx
MOV	esi, ebp
ADD	esi, -40
POP	edx
MOV	[esi], eax
;Assign		SETTK		num2		Temp4		
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
ADD	esi, -32
POP	edx
MOV	[esi], eax
;;NOP	SetEnd
;LARGETK		Condition		LARGETK		n		2		Label0
PUSH	esi
PUSH	edx
MOV	esi, ebp
ADD	esi, 8
POP	edx
MOV	edx, [esi]
POP	esi
MOV	eax, edx
PUSH	esi
MOV	edx, 2
POP	esi
MOV	ebx, edx
CMP	eax, ebx
JG	Label0
;;NOP	SetBegin
;Assign		SETTK		calcfib		1		
PUSH	esi
MOV	edx, 1
POP	esi
MOV	eax, edx
PUSH	edx
MOV	esi, ebp
ADD	esi, -24
POP	edx
MOV	[esi], eax
;;NOP	SetEnd
;Goto:		Label1
JMP	Label1
;Label:		Label0
Label0:
;LARGETK		Condition		LARGETK		3		n		Label4
PUSH	esi
MOV	edx, 3
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
CMP	eax, ebx
JG	Label4
;Assign		SETTK		i		3		
PUSH	esi
MOV	edx, 3
POP	esi
MOV	eax, edx
PUSH	edx
MOV	esi, ebp
ADD	esi, -36
POP	edx
MOV	[esi], eax
;Goto:		Label3
JMP	Label3
;Label:		Label2
Label2:
;Assign		ADDTK		i		i		1
PUSH	esi
PUSH	edx
MOV	esi, ebp
ADD	esi, -36
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
ADD	esi, -36
POP	edx
MOV	[esi], eax
;Label:		Label3
Label3:
;Call		fp_swap_2		(no ret)	argc=2
MOV	esi, ebp
ADD	esi, 16
PUSH	[esi - 4]
PUSH	edx
MOV	esi, ebp
ADD	esi, -32
POP	edx
PUSH	esi
PUSH	edx
MOV	esi, ebp
ADD	esi, -28
POP	edx
PUSH	esi
CALL	fp_swap_2		
ADD	esp, 12
;;NOP	SetBegin
;Assign		ADDTK		Temp8		num2		num1
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
ADD	esi, -28
POP	edx
MOV	edx, [esi]
POP	esi
MOV	ebx, edx
ADD	eax, ebx
PUSH	edx
MOV	esi, ebp
ADD	esi, -44
POP	edx
MOV	[esi], eax
;Assign		SETTK		num2		Temp8		
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
ADD	esi, -32
POP	edx
MOV	[esi], eax
;;NOP	SetEnd
;SMALLTK		Condition		SMALLTK		i		n		Label2
PUSH	esi
PUSH	edx
MOV	esi, ebp
ADD	esi, -36
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
CMP	eax, ebx
JL	Label2
;Label:		Label4
Label4:
;;NOP	SetBegin
;Assign		SETTK		calcfib		num2		
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
ADD	esi, -24
POP	edx
MOV	[esi], eax
;;NOP	SetEnd
;Label:		Label1
Label1:
MOV	eax, [ebp - 24]
POP	edi
POP	esi
POP	edx
POP	ecx
POP	ebx
MOV	esp, ebp
POP	ebp
RET	



;NODE : 5
;FP:(5)		fp_paint_5
fp_paint_5:
PUSH	ebp
MOV	ebp, esp
PUSH	eax
PUSH	ebx
PUSH	ecx
PUSH	edx
PUSH	esi
PUSH	edi
SUB	esp, 88
;;NOP	SetBegin
;Assign		SETTK		i		1		
PUSH	esi
MOV	edx, 1
POP	esi
MOV	eax, edx
PUSH	edx
MOV	esi, ebp
ADD	esi, -28
POP	edx
MOV	[esi], eax
;;NOP	SetEnd
;Label:		Label16
Label16:
;Call		fp_paintsingle_6		(no ret)	argc=2
MOV	esi, ebp
ADD	esi, 20
PUSH	[esi - 4]
LEA	edi, [ebp]
PUSH	edi
PUSH	esi
PUSH	edx
MOV	esi, ebp
ADD	esi, 12
POP	edx
MOV	edx, [esi]
POP	esi
PUSH	edx
PUSH	esi
PUSH	edx
MOV	esi, ebp
ADD	esi, -28
POP	edx
MOV	edx, [esi]
POP	esi
PUSH	edx
CALL	fp_paintsingle_6		
ADD	esp, 16
;;NOP	SetBegin
;Assign		ADDTK		Temp14		i		1
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
ADD	esi, -112
POP	edx
MOV	[esi], eax
;Assign		SETTK		i		Temp14		
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
ADD	esi, -28
POP	edx
MOV	[esi], eax
;;NOP	SetEnd
;SMALLEQUTK		Condition		SMALLEQUTK		i		n		Label16
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
ADD	esi, 8
POP	edx
MOV	edx, [esi]
POP	esi
MOV	ebx, edx
CMP	eax, ebx
JNG	Label16
POP	edi
POP	esi
POP	edx
POP	ecx
POP	ebx
POP	eax
MOV	esp, ebp
POP	ebp
RET	



;NODE : 6
;FP:(6)		fp_paintsingle_6
fp_paintsingle_6:
PUSH	ebp
MOV	ebp, esp
PUSH	eax
PUSH	ebx
PUSH	ecx
PUSH	edx
PUSH	esi
PUSH	edi
SUB	esp, 88
;LARGETK		Condition		LARGETK		1		n		Label7
PUSH	esi
MOV	edx, 1
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
CMP	eax, ebx
JG	Label7
;Assign		SETTK		i		1		
PUSH	esi
MOV	edx, 1
POP	esi
MOV	eax, edx
PUSH	edx
MOV	esi, ebp
ADD	esi, -28
POP	edx
MOV	[esi], eax
;Goto:		Label6
JMP	Label6
;Label:		Label5
Label5:
;Assign		ADDTK		i		i		1
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
MOV	[esi], eax
;Label:		Label6
Label6:
;LARGETK		Condition		LARGETK		1		n		Label10
PUSH	esi
MOV	edx, 1
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
CMP	eax, ebx
JG	Label10
;Assign		SETTK		j		1		
PUSH	esi
MOV	edx, 1
POP	esi
MOV	eax, edx
PUSH	edx
MOV	esi, ebp
ADD	esi, -32
POP	edx
MOV	[esi], eax
;Goto:		Label9
JMP	Label9
;Label:		Label8
Label8:
;Assign		ADDTK		j		j		1
PUSH	esi
PUSH	edx
MOV	esi, ebp
ADD	esi, -32
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
MOV	[esi], eax
;Label:		Label9
Label9:
;LARGETK		Condition		LARGETK		j		i		Label11
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
ADD	esi, -28
POP	edx
MOV	edx, [esi]
POP	esi
MOV	ebx, edx
CMP	eax, ebx
JG	Label11
;;NOP	SetBegin
;Assign		SETTK		arr[j]		c		
PUSH	esi
PUSH	edx
MOV	esi, ebp
ADD	esi, 12
POP	edx
MOV	edx, [esi]
POP	esi
MOV	eax, edx
PUSH	edx
MOV	esi, ebp
ADD	esi, -112
PUSH	esi
PUSH	edx
MOV	esi, ebp
ADD	esi, -32
POP	edx
MOV	edx, [esi]
POP	esi
IMUL	edx, edx, 4
ADD	esi, edx
POP	edx
MOV	[esi], eax
;;NOP	SetEnd
;Goto:		Label12
JMP	Label12
;Label:		Label11
Label11:
;;NOP	SetBegin
;Assign		SETTK		arr[j]		split		
PUSH	esi
PUSH	edx
MOV	esi, ebp
;add display offset to esi:
ADD	esi, 20
;display is to esi:
MOV	esi, [esi]
ADD	esi, -40
POP	edx
MOV	edx, [esi]
POP	esi
MOV	eax, edx
PUSH	edx
MOV	esi, ebp
ADD	esi, -112
PUSH	esi
PUSH	edx
MOV	esi, ebp
ADD	esi, -32
POP	edx
MOV	edx, [esi]
POP	esi
IMUL	edx, edx, 4
ADD	esi, edx
POP	edx
MOV	[esi], eax
;;NOP	SetEnd
;Label:		Label12
Label12:
;SMALLTK		Condition		SMALLTK		j		n		Label8
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
ADD	esi, 8
POP	edx
MOV	edx, [esi]
POP	esi
MOV	ebx, edx
CMP	eax, ebx
JL	Label8
;Label:		Label10
Label10:
;LARGETK		Condition		LARGETK		1		n		Label15
PUSH	esi
MOV	edx, 1
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
CMP	eax, ebx
JG	Label15
;Assign		SETTK		j		1		
PUSH	esi
MOV	edx, 1
POP	esi
MOV	eax, edx
PUSH	edx
MOV	esi, ebp
ADD	esi, -32
POP	edx
MOV	[esi], eax
;Goto:		Label14
JMP	Label14
;Label:		Label13
Label13:
;Assign		ADDTK		j		j		1
PUSH	esi
PUSH	edx
MOV	esi, ebp
ADD	esi, -32
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
MOV	[esi], eax
;Label:		Label14
Label14:
;Write		arr[j]
PUSH	esi
PUSH	edx
MOV	esi, ebp
ADD	esi, -112
PUSH	esi
PUSH	edx
MOV	esi, ebp
ADD	esi, -32
POP	edx
MOV	edx, [esi]
POP	esi
IMUL	edx, edx, 4
ADD	esi, edx
POP	edx
MOV	edx, [esi]
POP	esi
MOV	eax, edx
LEA	ebx, dword ptr [_characw]
PUSH	eax
PUSH	ebx
CALL	printf
ADD	esp, 8
;SMALLTK		Condition		SMALLTK		j		n		Label13
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
ADD	esi, 8
POP	edx
MOV	edx, [esi]
POP	esi
MOV	ebx, edx
CMP	eax, ebx
JL	Label13
;Label:		Label15
Label15:
;Write		String0
LEA	eax, in_string0
LEA	ebx, dword ptr [_string]
PUSH	eax
PUSH	ebx
CALL	printf
ADD	esp, 8
;SMALLTK		Condition		SMALLTK		i		n		Label5
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
ADD	esi, 8
POP	edx
MOV	edx, [esi]
POP	esi
MOV	ebx, edx
CMP	eax, ebx
JL	Label5
;Label:		Label7
Label7:
;Write		String1
LEA	eax, in_string1
LEA	ebx, dword ptr [_string]
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



;NODE : 7
;FP:(7)		fp_catalan_7
fp_catalan_7:
PUSH	ebp
MOV	ebp, esp
PUSH	ebx
PUSH	ecx
PUSH	edx
PUSH	esi
PUSH	edi
SUB	esp, 20
;Write		String2
LEA	eax, in_string2
LEA	ebx, dword ptr [_string]
PUSH	eax
PUSH	ebx
CALL	printf
ADD	esp, 8
;SMALLEQUTK		Condition		SMALLEQUTK		n		8		Label23
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
MOV	edx, 8
POP	esi
MOV	ebx, edx
CMP	eax, ebx
JNG	Label23
;Write		String3
LEA	eax, in_string3
LEA	ebx, dword ptr [_string]
PUSH	eax
PUSH	ebx
CALL	printf
ADD	esp, 8
;;NOP	SetBegin
;Assign		SUBTK		Temp23		0		1
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
ADD	esi, -28
POP	edx
MOV	[esi], eax
;Assign		SETTK		catalan		Temp23		
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
MOV	[esi], eax
;;NOP	SetEnd
;Goto:		Label24
JMP	Label24
;Label:		Label23
Label23:
;;NOP	SetBegin
;Assign		MULTK		Temp25		2		n
PUSH	esi
MOV	edx, 2
POP	esi
MOV	eax, edx
PUSH	esi
PUSH	edx
MOV	esi, ebp
ADD	esi, 8
MOV	esi, [esi]
POP	edx
MOV	edx, [esi]
POP	esi
MOV	ebx, edx
IMUL	eax, ebx
PUSH	edx
MOV	esi, ebp
ADD	esi, -32
POP	edx
MOV	[esi], eax
;Call		fp_C_8		dst=Temp26		argc=2
MOV	esi, ebp
ADD	esi, 16
PUSH	[esi - 4]
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
PUSH	esi
PUSH	edx
MOV	esi, ebp
ADD	esi, -32
POP	edx
MOV	edx, [esi]
POP	esi
PUSH	edx
CALL	fp_C_8		
PUSH	edx
MOV	esi, ebp
ADD	esi, -36
POP	edx
MOV	[esi], eax
ADD	esp, 16
;Assign		ADDTK		Temp28		n		1
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
ADD	esi, -40
POP	edx
MOV	[esi], eax
;Assign		DIVTK		Temp26		Temp26		Temp28
PUSH	esi
PUSH	edx
MOV	esi, ebp
ADD	esi, -36
POP	edx
MOV	edx, [esi]
POP	esi
MOV	eax, edx
PUSH	esi
PUSH	edx
MOV	esi, ebp
ADD	esi, -40
POP	edx
MOV	edx, [esi]
POP	esi
MOV	ebx, edx
CDQ	
IDIV	ebx
PUSH	edx
MOV	esi, ebp
ADD	esi, -36
POP	edx
MOV	[esi], eax
;Assign		SETTK		catalan		Temp26		
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
ADD	esi, -24
POP	edx
MOV	[esi], eax
;;NOP	SetEnd
;Label:		Label24
Label24:
MOV	eax, [ebp - 24]
POP	edi
POP	esi
POP	edx
POP	ecx
POP	ebx
MOV	esp, ebp
POP	ebp
RET	



;NODE : 8
;FP:(8)		fp_C_8
fp_C_8:
PUSH	ebp
MOV	ebp, esp
PUSH	ebx
PUSH	ecx
PUSH	edx
PUSH	esi
PUSH	edi
SUB	esp, 24
;;NOP	SetBegin
;Assign		SETTK		result		1		
PUSH	esi
MOV	edx, 1
POP	esi
MOV	eax, edx
PUSH	edx
MOV	esi, ebp
ADD	esi, -32
POP	edx
MOV	[esi], eax
;;NOP	SetEnd
;Assign		SUBTK		Temp16		n		m
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
SUB	eax, ebx
PUSH	edx
MOV	esi, ebp
ADD	esi, -36
POP	edx
MOV	[esi], eax
;Assign		ADDTK		Temp16		Temp16		1
PUSH	esi
PUSH	edx
MOV	esi, ebp
ADD	esi, -36
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
ADD	esi, -36
POP	edx
MOV	[esi], eax
;LARGETK		Condition		LARGETK		Temp16		n		Label19
PUSH	esi
PUSH	edx
MOV	esi, ebp
ADD	esi, -36
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
CMP	eax, ebx
JG	Label19
;Assign		SETTK		i		Temp16		
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
ADD	esi, -28
POP	edx
MOV	[esi], eax
;Goto:		Label18
JMP	Label18
;Label:		Label17
Label17:
;Assign		ADDTK		i		i		1
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
MOV	[esi], eax
;Label:		Label18
Label18:
;;NOP	SetBegin
;Assign		MULTK		Temp18		result		i
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
ADD	esi, -28
POP	edx
MOV	edx, [esi]
POP	esi
MOV	ebx, edx
IMUL	eax, ebx
PUSH	edx
MOV	esi, ebp
ADD	esi, -40
POP	edx
MOV	[esi], eax
;Assign		SETTK		result		Temp18		
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
ADD	esi, -32
POP	edx
MOV	[esi], eax
;;NOP	SetEnd
;SMALLTK		Condition		SMALLTK		i		n		Label17
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
ADD	esi, 8
POP	edx
MOV	edx, [esi]
POP	esi
MOV	ebx, edx
CMP	eax, ebx
JL	Label17
;Label:		Label19
Label19:
;SMALLTK		Condition		SMALLTK		m		1		Label22
PUSH	esi
PUSH	edx
MOV	esi, ebp
ADD	esi, 12
POP	edx
MOV	edx, [esi]
POP	esi
MOV	eax, edx
PUSH	esi
MOV	edx, 1
POP	esi
MOV	ebx, edx
CMP	eax, ebx
JL	Label22
;Assign		SETTK		i		m		
PUSH	esi
PUSH	edx
MOV	esi, ebp
ADD	esi, 12
POP	edx
MOV	edx, [esi]
POP	esi
MOV	eax, edx
PUSH	edx
MOV	esi, ebp
ADD	esi, -28
POP	edx
MOV	[esi], eax
;Goto:		Label21
JMP	Label21
;Label:		Label20
Label20:
;Assign		SUBTK		i		i		1
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
SUB	eax, ebx
PUSH	edx
MOV	esi, ebp
ADD	esi, -28
POP	edx
MOV	[esi], eax
;Label:		Label21
Label21:
;;NOP	SetBegin
;Assign		DIVTK		Temp20		result		i
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
ADD	esi, -28
POP	edx
MOV	edx, [esi]
POP	esi
MOV	ebx, edx
CDQ	
IDIV	ebx
PUSH	edx
MOV	esi, ebp
ADD	esi, -44
POP	edx
MOV	[esi], eax
;Assign		SETTK		result		Temp20		
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
ADD	esi, -32
POP	edx
MOV	[esi], eax
;;NOP	SetEnd
;LARGETK		Condition		LARGETK		i		1		Label20
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
CMP	eax, ebx
JG	Label20
;Label:		Label22
Label22:
;;NOP	SetBegin
;Assign		SETTK		C		result		
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
ADD	esi, -24
POP	edx
MOV	[esi], eax
;;NOP	SetEnd
MOV	eax, [ebp - 24]
POP	edi
POP	esi
POP	edx
POP	ecx
POP	ebx
MOV	esp, ebp
POP	ebp
RET	



;NODE : 9
;FP:(9)		fp_game_9
fp_game_9:
PUSH	ebp
MOV	ebp, esp
PUSH	eax
PUSH	ebx
PUSH	ecx
PUSH	edx
PUSH	esi
PUSH	edi
SUB	esp, 4
;Write		String4
LEA	eax, in_string4
LEA	ebx, dword ptr [_string]
PUSH	eax
PUSH	ebx
CALL	printf
ADD	esp, 8
;;NOP	SetBegin
;Assign		SUBTK		Temp30		0		1
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
ADD	esi, -28
POP	edx
MOV	[esi], eax
;Assign		SETTK		i1		Temp30		
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
;add display offset to esi:
ADD	esi, 8
;display is to esi:
MOV	esi, [esi]
ADD	esi, -72
POP	edx
MOV	[esi], eax
;;NOP	SetEnd
;Label:		Label25
Label25:
;Write		String5
LEA	eax, in_string5
LEA	ebx, dword ptr [_string]
PUSH	eax
PUSH	ebx
CALL	printf
ADD	esp, 8
;Read		i1
PUSH	edx
MOV	esi, ebp
;add display offset to esi:
ADD	esi, 8
;display is to esi:
MOV	esi, [esi]
ADD	esi, -72
POP	edx
LEA	ebx, _value
PUSH	esi
PUSH	ebx
CALL	scanf
ADD	esp, 8
;abel:EQUTK		Condition		EQUTK		i1		6		Label26
PUSH	esi
PUSH	edx
MOV	esi, ebp
;add display offset to esi:
ADD	esi, 8
;display is to esi:
MOV	esi, [esi]
ADD	esi, -72
POP	edx
MOV	edx, [esi]
POP	esi
MOV	eax, edx
PUSH	esi
MOV	edx, 6
POP	esi
MOV	ebx, edx
CMP	eax, ebx
JE	Label26
;Write		String6
LEA	eax, in_string6
LEA	ebx, dword ptr [_string]
PUSH	eax
PUSH	ebx
CALL	printf
ADD	esp, 8
;Goto:		Label27
JMP	Label27
;Label:		Label26
Label26:
;Label:		Label27
Label27:
;bel:NEQUTK		Condition		NEQUTK		i1		6		Label25
PUSH	esi
PUSH	edx
MOV	esi, ebp
;add display offset to esi:
ADD	esi, 8
;display is to esi:
MOV	esi, [esi]
ADD	esi, -72
POP	edx
MOV	edx, [esi]
POP	esi
MOV	eax, edx
PUSH	esi
MOV	edx, 6
POP	esi
MOV	ebx, edx
CMP	eax, ebx
JNE	Label25
;Write		String7
LEA	eax, in_string7
LEA	ebx, dword ptr [_string]
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

ENDPOINT :
}
return 0;
}
