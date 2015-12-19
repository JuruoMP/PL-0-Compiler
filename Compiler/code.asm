#pragma warning(disable:4996)
#include <stdio.h>
char _string[] = "%s";
char _value[] = "%d";
char _charac[] = "%c";
char in_string0[] = " ";
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
SUB	esp, 8
;Assign		SETTK		i		1023		
PUSH	esi
MOV	edx, 1023
POP	esi
MOV	eax, edx
PUSH	edx
MOV	esi, ebp
ADD	esi, -28
POP	edx
MOV	[esi], eax
;Label:		Label0
Label0:
;Assign		DIVTK		Temp4		i		2
PUSH	esi
PUSH	edx
MOV	esi, ebp
ADD	esi, -28
POP	edx
MOV	edx, [esi]
POP	esi
MOV	eax, edx
PUSH	esi
MOV	edx, 2
POP	esi
MOV	ebx, edx
CDQ	
IDIV	ebx
PUSH	edx
MOV	esi, ebp
ADD	esi, -32
POP	edx
MOV	[esi], eax
;Assign		SETTK		i		Temp4		
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
;Write		i
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
;bel:NEQUTK		Condition		NEQUTK		i		0		Label0
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
CMP	eax, ebx
JNE	Label0
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
