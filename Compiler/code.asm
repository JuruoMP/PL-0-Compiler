
NODE : 0

NODE : 1
Call		fp_proc_2		argv=0

NODE : 2
FP:(2)		fp_proc_2
Assign		SETTK		Temp1		1		
Assign		SETTK		Temp5		2		
Assign		SETTK		arr		Temp5		


ASM CODE : 


NODE : 1
PUSH	ebp
MOV	ebp, esp
PUSH	eax
PUSH	ebx
PUSH	ecx
PUSH	edx
PUSH	esi
PUSH	edi
MOV	esi, ebp
ADD	esi, 8
;MARK	esi, 8
PUSH	ebp
CALL	fp_proc_2		
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



NODE : 2
fp_proc_2:
PUSH	ebp
MOV	ebp, esp
PUSH	eax
PUSH	ebx
PUSH	ecx
PUSH	edx
PUSH	esi
PUSH	edi
SUB	esp, 8
PUSH	esi
MOV	edx, 1
POP	esi
MOV	eax, edx
PUSH	edx
MOV	esi, ebp
ADD	esi, -4
POP	edx
MOV	[esi], eax
PUSH	esi
MOV	edx, 2
POP	esi
MOV	eax, edx
PUSH	edx
MOV	esi, ebp
ADD	esi, -8
POP	edx
MOV	[esi], eax
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
ADD	esi, 8
;MARK	esi, 8
MOV	esi, [esi]
PUSH	esi
PUSH	edx
MOV	esi, ebp
ADD	esi, -4
POP	edx
MOV	edx, [esi]
POP	esi
IMUL	edx, 4
ADD	esi, edx
POP	edx
MOV	[esi], eax
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
