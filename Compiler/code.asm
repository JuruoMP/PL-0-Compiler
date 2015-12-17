#pragma warning(disable:4996)
#include <stdio.h>
char _string[] = "%s";
char _value[] = "%d";
char _charac[] = "%c";
char in_string0[] = "  ";
char in_string1[] = "  ";
char in_string2[] = "  ";
char in_string3[] = "  ";
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
SUB	esp, 12
;Call		fp_p1_2		(no ret)	argc=1
MOV	esi, ebp
ADD	esi, 8
LEA	edi, [ebp]
PUSH	edi
PUSH	4
CALL	fp_p1_2		
ADD	esp, 8
;Assign		ADDTK		Temp8		b		10
PUSH	esi
PUSH	edx
MOV	esi, ebp
ADD	esi, -32
POP	edx
MOV	edx, [esi]
POP	esi
MOV	eax, edx
PUSH	esi
MOV	edx, 10
POP	esi
MOV	ebx, edx
ADD	eax, ebx
PUSH	edx
MOV	esi, ebp
ADD	esi, -36
POP	edx
MOV	[esi], eax
;Assign		SETTK		a		Temp8		
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
;Write		String3
LEA	eax, in_string3
LEA	ebx, _string
PUSH	eax
PUSH	ebx
CALL	printf
ADD	esp, 8
;Write		a
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



;NODE : 2
;FP:(2)		fp_p1_2
fp_p1_2:
PUSH	ebp
MOV	ebp, esp
PUSH	eax
PUSH	ebx
PUSH	ecx
PUSH	edx
PUSH	esi
PUSH	edi
PUSH	2
PUSH	97
PUSH	100
PUSH	99
SUB	esp, 8
;Write		a
PUSH	esi
PUSH	edx
MOV	esi, ebp
ADD	esi, -32
POP	edx
MOV	edx, [esi]
POP	esi
MOV	eax, edx
LEA	ebx, _charac
PUSH	eax
PUSH	ebx
CALL	printf
ADD	esp, 8
;Assign		ADDTK		Temp4		d		a
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
ADD	esi, -32
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
;Assign		SETTK		b		Temp4		
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
;add display offset to esi:
ADD	esi, 12
;display is to esi:
MOV	esi, [esi]
ADD	esi, -32
POP	edx
MOV	[esi], eax
;Call		fp_p2_3		(no ret)	argc=1
MOV	esi, ebp
ADD	esi, 16
PUSH	[esi - 4]
LEA	edi, [ebp]
PUSH	edi
PUSH	esi
PUSH	edx
MOV	esi, ebp
;add display offset to esi:
ADD	esi, 12
;display is to esi:
MOV	esi, [esi]
ADD	esi, -32
POP	edx
MOV	edx, [esi]
POP	esi
PUSH	edx
CALL	fp_p2_3		
ADD	esp, 12
;Write		String2
LEA	eax, in_string2
LEA	ebx, _string
PUSH	eax
PUSH	ebx
CALL	printf
ADD	esp, 8
;Assign		ADDTK		Temp5		q		two
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
ADD	eax, ebx
PUSH	edx
MOV	esi, ebp
ADD	esi, -48
POP	edx
MOV	[esi], eax
;Write		Temp5
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
;FP:(3)		fp_p2_3
fp_p2_3:
PUSH	ebp
MOV	ebp, esp
PUSH	eax
PUSH	ebx
PUSH	ecx
PUSH	edx
PUSH	esi
PUSH	edi
SUB	esp, 12
;Assign		ADDTK		Temp2		x		a
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
;add display offset to esi:
ADD	esi, 12
;display is to esi:
MOV	esi, [esi]
ADD	esi, -32
POP	edx
MOV	edx, [esi]
POP	esi
MOV	ebx, edx
ADD	eax, ebx
PUSH	edx
MOV	esi, ebp
ADD	esi, -32
POP	edx
MOV	[esi], eax
;Assign		SETTK		y		Temp2		
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
ADD	esi, -28
POP	edx
MOV	[esi], eax
;Write		String0
LEA	eax, in_string0
LEA	ebx, _string
PUSH	eax
PUSH	ebx
CALL	printf
ADD	esp, 8
;Write		y
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
;Assign		SUBTK		Temp3		x		c
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
;add display offset to esi:
ADD	esi, 12
;display is to esi:
MOV	esi, [esi]
ADD	esi, -40
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
;Assign		SETTK		x		Temp3		
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
ADD	esi, 8
POP	edx
MOV	[esi], eax
;Write		String1
LEA	eax, in_string1
LEA	ebx, _string
PUSH	eax
PUSH	ebx
CALL	printf
ADD	esp, 8
;Write		x
PUSH	esi
PUSH	edx
MOV	esi, ebp
ADD	esi, 8
POP	edx
MOV	edx, [esi]
POP	esi
MOV	eax, edx
LEA	ebx, _charac
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
