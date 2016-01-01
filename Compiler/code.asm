#pragma warning(disable:4996)
#include <stdio.h>
char _string[] = "%s";
char _value[] = "%d";
char _charac[] = "%c";
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
SUB	esp, 60
;;NOP	SetBegin
PUSH	esi
MOV	edx, 3
POP	esi
MOV	eax, edx
PUSH	edx
MOV	esi, ebp
ADD	esi, -28
POP	edx
MOV	[esi], eax
;;NOP	SetBegin
PUSH	esi
MOV	edx, 100
POP	esi
MOV	eax, edx
PUSH	edx
MOV	esi, ebp
ADD	esi, -32
POP	edx
MOV	[esi], eax
;;NOP	SetBegin
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
ADD	esi, -32
POP	edx
MOV	edx, [esi]
POP	esi
MOV	ebx, edx
ADD	eax, ebx
PUSH	edx
MOV	esi, ebp
ADD	esi, -52
POP	edx
MOV	[esi], eax
PUSH	esi
PUSH	edx
MOV	esi, ebp
ADD	esi, -52
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
ADD	esi, -56
POP	edx
MOV	[esi], eax
PUSH	esi
PUSH	edx
MOV	esi, ebp
ADD	esi, -56
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
ADD	esi, -60
POP	edx
MOV	[esi], eax
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
ADD	esi, -36
POP	edx
MOV	[esi], eax
;;NOP	SetBegin
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
ADD	esi, -32
POP	edx
MOV	edx, [esi]
POP	esi
MOV	ebx, edx
ADD	eax, ebx
PUSH	edx
MOV	esi, ebp
ADD	esi, -64
POP	edx
MOV	[esi], eax
PUSH	esi
PUSH	edx
MOV	esi, ebp
ADD	esi, -64
POP	edx
MOV	edx, [esi]
POP	esi
MOV	eax, edx
PUSH	esi
PUSH	edx
MOV	esi, ebp
ADD	esi, -64
POP	edx
MOV	edx, [esi]
POP	esi
MOV	ebx, edx
ADD	eax, ebx
PUSH	edx
MOV	esi, ebp
ADD	esi, -72
POP	edx
MOV	[esi], eax
PUSH	esi
PUSH	edx
MOV	esi, ebp
ADD	esi, -72
POP	edx
MOV	edx, [esi]
POP	esi
MOV	eax, edx
PUSH	esi
PUSH	edx
MOV	esi, ebp
ADD	esi, -64
POP	edx
MOV	edx, [esi]
POP	esi
MOV	ebx, edx
ADD	eax, ebx
PUSH	edx
MOV	esi, ebp
ADD	esi, -80
POP	edx
MOV	[esi], eax
PUSH	esi
PUSH	edx
MOV	esi, ebp
ADD	esi, -80
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
ADD	eax, ebx
PUSH	edx
MOV	esi, ebp
ADD	esi, -84
POP	edx
MOV	[esi], eax
PUSH	esi
PUSH	edx
MOV	esi, ebp
ADD	esi, -84
POP	edx
MOV	edx, [esi]
POP	esi
MOV	eax, edx
PUSH	edx
MOV	esi, ebp
ADD	esi, -48
POP	edx
MOV	[esi], eax
;Write		r
PUSH	esi
PUSH	edx
MOV	esi, ebp
ADD	esi, -48
POP	edx
MOV	edx, [esi]
POP	esi
MOV	eax, edx
LEA	ebx, dword ptr [_value]
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
