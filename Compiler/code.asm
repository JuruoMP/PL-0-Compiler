
NODE : 0

NODE : 1
Assign		SETTK		e		63		
Read		inputc
Read		inputi
Assign		MULTK		Temp56		e		4
Assign		MULTK		Temp58		e		2
Assign		DIVTK		Temp56		Temp56		Temp58
Call		fp_fact1_7		dst=Temp59		argc=1
Assign		ADDTK		Temp56		Temp56		Temp59
Assign		SETTK		result		Temp56		
Condition		SMALLEQUTK		result		10		Label13
Write		result > 10
Goto:		Label14
Label:		Label13
Label:		Label14
Call		fp_prime_9		dst=Temp61		argc=0
Assign		SETTK		iprime		Temp61		
Call		fp_prime_9		dst=Temp62		argc=0
Call		fp_fact1_7		dst=Temp63		argc=1
Assign		SETTK		ans1		Temp63		
Assign		ADDTK		Temp65		iprime		0
Call		fp_fact2_8		dst=Temp66		argc=1
Assign		SETTK		ans2		Temp66		
Condition		EQUTK		ans1		ans2		Label15
Write		Compile error
Goto:		Label16
Label:		Label15
Label:		Label16
Call		fp_proc1_2		(no ret)	argc=0
Assign		SETTK		i		2		
Label:		Label17
Assign		SETTK		j		i		
Label:		Label19
Assign		ADDTK		Temp70		0		0
Assign		ADDTK		Temp71		i		j
Assign		SUBTK		Temp72		i		j
Assign		SETTK		arr[Temp71]		Temp72		
Condition		LARGETK		i		Temp70		Label20
Assign		SUBTK		j		j		1
Goto:		Label19
Label:		Label20
Condition		SMALLTK		2		inputi		Label18
Assign		ADDTK		i		i		1
Goto:		Label17
Label:		Label18

NODE : 2
FP:(2)		fp_proc1_2
Assign		SUBTK		Temp9		0		1
Assign		SUBTK		Temp9		0		Temp9
Assign		SETTK		t[0]		Temp9		
Assign		MULTK		Temp14		18		3
Assign		DIVTK		Temp14		Temp14		6
Assign		SUBTK		Temp14		10		Temp14
Assign		SETTK		t[1]		Temp14		
Assign		SUBTK		Temp19		2		0
Assign		SUBTK		Temp19		Temp19		0
Assign		SETTK		t[2]		Temp19		
Assign		DIVTK		Temp23		6		2
Assign		SETTK		i		Temp23		
Label:		Label0
Assign		ADDTK		Temp26		2		4
Assign		SUBTK		Temp28		i		1
Assign		SUBTK		Temp30		i		2
Assign		ADDTK		Temp31		t[Temp28]		t[Temp30]
Assign		SETTK		t[i]		Temp31		
Condition		SMALLTK		Temp23		Temp26		Label1
Assign		ADDTK		i		i		1
Goto:		Label0
Label:		Label1
Assign		MULTK		Temp34		2		3
Condition		LARGEEQUTK		i		Temp34		Label2
Write		Compile error
Goto:		Label3
Label:		Label2
Label:		Label3
Assign		SETTK		tmp		t[2]		
Call		fp_proc2_3		(no ret)	argc=3
Condition		EQUTK		t[2]		tmp		Label4
Write		Sub check passed
Goto:		Label5
Label:		Label4
Label:		Label5

NODE : 3
FP:(3)		fp_proc2_3
Assign		SUBTK		Temp3		0		b1
Assign		ADDTK		Temp3		a2		Temp3
Assign		SETTK		a2		Temp3		
Write		char integer const var for if array of 
Assign		ADDTK		Temp6		1		10
Write		Temp6
Write		c1
Call		fp_proc3_4		(no ret)	argc=0

NODE : 4
FP:(4)		fp_proc3_4
Assign		SETTK		tmp		10		
Write		i = 
Write		i
Write		tmp

NODE : 5
FP:(5)		fp_proc2_5

NODE : 6
FP:(6)		fp_proc3_6

NODE : 7
FP:(7)		fp_fact1_7
Condition		LARGEEQUTK		0		0		Label6
Assign		SETTK		0		0		
Goto:		Label7
Label:		Label6
Label:		Label7
Condition		NEQUTK		0		0		Label8
Assign		SETTK		fact1		1		
Goto:		Label9
Label:		Label8
Assign		SUBTK		Temp44		0		1
Call		fp_fact1_7		dst=Temp45		argc=1
Assign		MULTK		Temp45		Temp45		0
Assign		SETTK		fact1		Temp45		
Label:		Label9
Call		fp_proc2_5		(no ret)	argc=3

NODE : 8
FP:(8)		fp_fact2_8
Call		fp_proc3_6		(no ret)	argc=3
Condition		LARGETK		0		1		Label10
Assign		SETTK		0		1		
Goto:		Label11
Label:		Label10
Label:		Label11
Assign		SETTK		temp		1		
Label:		Label12
Assign		MULTK		Temp49		temp		0
Assign		SETTK		temp		Temp49		
Assign		SUBTK		Temp51		0		1
Assign		SETTK		0		Temp51		
Condition		LARGEEQUTK		0		1		Label12
Assign		SETTK		fact2		temp		

NODE : 9
FP:(9)		fp_prime_9
Assign		SETTK		prime		7		


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
PUSH	esi
MOV	edx, 63
POP	esi
MOV	eax, edx
PUSH	edx
MOV	esi, ebp
ADD	esi, -32
POP	edx
MOV	[esi], eax
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
MOV	[esi], eax
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
MOV	[esi], eax
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
MOV	[esi], eax
MOV	esi, ebp
ADD	esi, 12
;MARK	esi, 12
PUSH	ebp
PUSH	esi
PUSH	edx
MOV	esi, ebp
ADD	esi, -80
POP	edx
MOV	edx, [esi]
POP	esi
PUSH	edx
CALL	fp_fact1_7		
PUSH	edx
MOV	esi, ebp
ADD	esi, -120
POP	edx
MOV	[esi], eax
ADD	esp, 8
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
MOV	[esi], eax
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
MOV	[esi], eax
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
JMP	Label14
Label13:
Label14:
MOV	esi, ebp
ADD	esi, 8
;MARK	esi, 8
PUSH	ebp
CALL	fp_prime_9		
PUSH	edx
MOV	esi, ebp
ADD	esi, -124
POP	edx
MOV	[esi], eax
ADD	esp, 4
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
MOV	[esi], eax
MOV	esi, ebp
ADD	esi, 8
;MARK	esi, 8
PUSH	ebp
CALL	fp_prime_9		
PUSH	edx
MOV	esi, ebp
ADD	esi, -128
POP	edx
MOV	[esi], eax
ADD	esp, 4
MOV	esi, ebp
ADD	esi, 12
;MARK	esi, 12
PUSH	ebp
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
MOV	[esi], eax
ADD	esp, 8
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
MOV	[esi], eax
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
MOV	[esi], eax
MOV	esi, ebp
ADD	esi, 12
;MARK	esi, 12
PUSH	ebp
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
MOV	[esi], eax
ADD	esp, 8
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
MOV	[esi], eax
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
JMP	Label16
Label15:
Label16:
MOV	esi, ebp
ADD	esi, 8
;MARK	esi, 8
PUSH	ebp
CALL	fp_proc1_2		
ADD	esp, 4
PUSH	esi
MOV	edx, 2
POP	esi
MOV	eax, edx
PUSH	edx
MOV	esi, ebp
ADD	esi, -100
POP	edx
MOV	[esi], eax
Label17:
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
MOV	[esi], eax
Label19:
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
MOV	[esi], eax
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
MOV	[esi], eax
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
MOV	[esi], eax
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
MOV	[esi], eax
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
ADD	esi, -144
POP	edx
MOV	edx, [esi]
POP	esi
MOV	ebx, edx
CMP	eax, ebx
JG	Label20
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
MOV	[esi], eax
JMP	Label19
Label20:
PUSH	esi
MOV	edx, 2
POP	esi
MOV	eax, edx
PUSH	esi
PUSH	edx
MOV	esi, ebp
ADD	esi, -80
POP	edx
MOV	edx, [esi]
POP	esi
MOV	ebx, edx
CMP	eax, ebx
JL	Label18
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
MOV	[esi], eax
JMP	Label17
Label18:
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
fp_proc1_2:
PUSH	ebp
MOV	ebp, esp
PUSH	eax
PUSH	ebx
PUSH	ecx
PUSH	edx
PUSH	esi
PUSH	edi
SUB	esp, 84
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
MOV	[esi], eax
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
MOV	[esi], eax
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
MOV	[esi], eax
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
MOV	edx, 6
POP	esi
MOV	ebx, edx
SUB	edx, edx
IDIV	ebx
PUSH	edx
MOV	esi, ebp
ADD	esi, -56
POP	edx
MOV	[esi], eax
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
MOV	[esi], eax
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
MOV	[esi], eax
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
MOV	[esi], eax
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
ADD	esi, -40
PUSH	esi
MOV	edx, 2
POP	esi
IMUL	edx, 4
ADD	esi, edx
POP	edx
MOV	[esi], eax
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
MOV	[esi], eax
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
MOV	[esi], eax
Label0:
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
MOV	[esi], eax
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
MOV	[esi], eax
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
MOV	[esi], eax
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
MOV	[esi], eax
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
ADD	esi, -68
POP	edx
MOV	edx, [esi]
POP	esi
MOV	ebx, edx
CMP	eax, ebx
JL	Label1
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
MOV	[esi], eax
JMP	Label0
Label1:
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
MOV	[esi], eax
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
JMP	Label3
Label2:
Label3:
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
MOV	[esi], eax
MOV	esi, ebp
ADD	esi, 24
PUSH	[esi - 4]
;MARK	[esi - 4]
PUSH	ebp
PUSH	edx
MOV	esi, ebp
ADD	esi, 8
;MARK	esi, 8
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
JMP	Label5
Label4:
Label5:
POP	edi
POP	esi
POP	edx
POP	ecx
POP	ebx
POP	eax
MOV	esp, ebp
POP	ebp
RET	



NODE : 3
fp_proc2_3:
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
MOV	edx, 0
POP	esi
MOV	eax, edx
PUSH	esi
PUSH	edx
MOV	esi, ebp
ADD	esi, 24
;MARK	esi, 24
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
MOV	[esi], eax
PUSH	esi
PUSH	edx
MOV	esi, ebp
ADD	esi, 24
;MARK	esi, 24
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
MOV	[esi], eax
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
ADD	esi, 24
;MARK	esi, 24
MOV	esi, [esi]
POP	edx
MOV	[esi], eax
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
MOV	[esi], eax
MOV	esi, ebp
ADD	esi, 16
PUSH	[esi - 4]
PUSH	[esi - 8]
;MARK	[esi - 8]
PUSH	ebp
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



NODE : 4
fp_proc3_4:
PUSH	ebp
MOV	ebp, esp
PUSH	eax
PUSH	ebx
PUSH	ecx
PUSH	edx
PUSH	esi
PUSH	edi
SUB	esp, 0
PUSH	esi
MOV	edx, 10
POP	esi
MOV	eax, edx
PUSH	edx
MOV	esi, ebp
ADD	esi, -4
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



NODE : 5
fp_proc2_5:
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



NODE : 6
fp_proc3_6:
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



NODE : 7
fp_fact1_7:
PUSH	ebp
MOV	ebp, esp
PUSH	ebx
PUSH	ecx
PUSH	edx
PUSH	esi
PUSH	edi
SUB	esp, 12
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
PUSH	esi
MOV	edx, 0
POP	esi
MOV	eax, edx
PUSH	edx
MOV	esi, ebp
ADD	esi, 8
POP	edx
MOV	[esi], eax
JMP	Label7
Label6:
Label7:
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
PUSH	esi
MOV	edx, 1
POP	esi
MOV	eax, edx
PUSH	edx
MOV	esi, ebp
ADD	esi, -4
POP	edx
MOV	[esi], eax
JMP	Label9
Label8:
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
MOV	[esi], eax
MOV	esi, ebp
ADD	esi, 16
PUSH	[esi - 4]
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
MOV	[esi], eax
ADD	esp, 8
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
MOV	[esi], eax
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
MOV	[esi], eax
Label9:
MOV	esi, ebp
ADD	esi, 24
PUSH	[esi - 4]
PUSH	edx
MOV	esi, ebp
ADD	esi, 12
;MARK	esi, 12
MOV	esi, [esi]
POP	edx
PUSH	esi
PUSH	edx
MOV	esi, ebp
ADD	esi, 12
;MARK	esi, 12
MOV	esi, [esi]
POP	edx
PUSH	esi
PUSH	edx
MOV	esi, ebp
ADD	esi, 12
;MARK	esi, 12
MOV	esi, [esi]
POP	edx
PUSH	esi
CALL	fp_proc2_5		
ADD	esp, 16
MOV	eax, [ebp - 4]
POP	edi
POP	esi
POP	edx
POP	ecx
POP	ebx
MOV	esp, ebp
POP	ebp
RET	



NODE : 8
fp_fact2_8:
PUSH	ebp
MOV	ebp, esp
PUSH	ebx
PUSH	ecx
PUSH	edx
PUSH	esi
PUSH	edi
SUB	esp, 16
MOV	esi, ebp
ADD	esi, 24
PUSH	[esi - 4]
PUSH	esi
PUSH	edx
MOV	esi, ebp
ADD	esi, 12
;MARK	esi, 12
MOV	esi, [esi]
POP	edx
MOV	edx, [esi]
POP	esi
PUSH	edx
PUSH	esi
PUSH	edx
MOV	esi, ebp
ADD	esi, 12
;MARK	esi, 12
MOV	esi, [esi]
POP	edx
MOV	edx, [esi]
POP	esi
PUSH	edx
PUSH	esi
PUSH	edx
MOV	esi, ebp
ADD	esi, 12
;MARK	esi, 12
MOV	esi, [esi]
POP	edx
MOV	edx, [esi]
POP	esi
PUSH	edx
CALL	fp_proc3_6		
ADD	esp, 16
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
PUSH	esi
MOV	edx, 1
POP	esi
MOV	eax, edx
PUSH	edx
MOV	esi, ebp
ADD	esi, 8
POP	edx
MOV	[esi], eax
JMP	Label11
Label10:
Label11:
PUSH	esi
MOV	edx, 1
POP	esi
MOV	eax, edx
PUSH	edx
MOV	esi, ebp
ADD	esi, -8
POP	edx
MOV	[esi], eax
Label12:
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
MOV	[esi], eax
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
MOV	[esi], eax
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
MOV	[esi], eax
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
MOV	[esi], eax
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
MOV	[esi], eax
MOV	eax, [ebp - 4]
POP	edi
POP	esi
POP	edx
POP	ecx
POP	ebx
MOV	esp, ebp
POP	ebp
RET	



NODE : 9
fp_prime_9:
PUSH	ebp
MOV	ebp, esp
PUSH	ebx
PUSH	ecx
PUSH	edx
PUSH	esi
PUSH	edi
SUB	esp, 0
PUSH	esi
MOV	edx, 7
POP	esi
MOV	eax, edx
PUSH	edx
MOV	esi, ebp
ADD	esi, -4
POP	edx
MOV	[esi], eax
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
