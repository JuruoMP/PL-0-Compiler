#include <cstdio>

int main()
{
	int value;
	__asm{
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
			  ; MARK	esi, 8
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
			  JMP	END


		  fp_proc_2 :
		  PUSH	ebp
			  MOV	ebp, esp
			  PUSH	eax
			  PUSH	ebx
			  PUSH	ecx
			  PUSH	edx
			  PUSH	esi
			  PUSH	edi
			  SUB	esp, 8
			  ; getTempValue Start
			  PUSH	esi
			  MOV	edx, 1
			  POP	esi
			  ; getTempValue End
			  MOV	eax, edx
			  ; getTempAddr Start
			  PUSH	edx
			  MOV	esi, ebp
			  ADD	esi, -4
			  POP	edx
			  ; getTempAddr End
			  MOV[esi], eax
			  ; getTempValue Start
			  PUSH	esi
			  MOV	edx, 2
			  POP	esi
			  ; getTempValue End
			  MOV	eax, edx
			  ; getTempAddr Start
			  PUSH	edx
			  MOV	esi, ebp
			  ADD	esi, -8
			  POP	edx
			  ; getTempAddr End
			  MOV[esi], eax
			  ; getTempValue Start
			  PUSH	esi
			  ; getTempAddr Start
			  PUSH	edx
			  MOV	esi, ebp
			  ADD	esi, -8
			  POP	edx
			  ; getTempAddr End
			  MOV	edx, [esi]
			  POP	esi
			  ; getTempValue End
			  MOV	eax, edx

			  ; getTempAddr Start
			  PUSH	edx
			  MOV	esi, ebp
			  ADD	esi, 8
			  ; MARK	esi, 8
			  MOV	esi, [esi]
			  ADD	esi, -56
			  ; getTempValue Start
			  PUSH	esi
			  ; getTempAddr Start
			  PUSH	edx
			  MOV	esi, ebp
			  ADD	esi, -4
			  POP	edx
			  ; getTempAddr End
			  MOV	edx, [esi]
			  POP	esi
			  ; getTempValue End
			  IMUL	edx, 4
			  ADD	esi, edx
			  POP	edx
			  ; getTempAddr End
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

			  END:

	}
}