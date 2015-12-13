

;NODE : 1
PUSH	ebp
MOV	ebp, esp
PUSH	eax
PUSH	ebx
PUSH	ecx
PUSH	edx
PUSH	esi
PUSH	edi
;Assign		SETTK		e		63		
;getTempValue Srart:
PUSH	esi
MOV	edx, 63
POP	esi
;getTempValue End:
MOV	eax, edx
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -32
POP	edx
;getTempAddr End:
MOV	[esi], eax
;Read		inputc
;Read		inputi
;Assign		MULTK		Temp49		e		4
;getTempValue Srart:
PUSH	esi
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -32
POP	edx
;getTempAddr End:
MOV	edx, [esi]
POP	esi
;getTempValue End:
MOV	eax, edx
;getTempValue Srart:
PUSH	esi
MOV	edx, 4
POP	esi
;getTempValue End:
MOV	ebx, edx
IMUL	eax, ebx
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -112
POP	edx
;getTempAddr End:
MOV	[esi], eax
;Assign		MULTK		Temp51		e		2
;getTempValue Srart:
PUSH	esi
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -32
POP	edx
;getTempAddr End:
MOV	edx, [esi]
POP	esi
;getTempValue End:
MOV	eax, edx
;getTempValue Srart:
PUSH	esi
MOV	edx, 2
POP	esi
;getTempValue End:
MOV	ebx, edx
IMUL	eax, ebx
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -116
POP	edx
;getTempAddr End:
MOV	[esi], eax
;Assign		DIVTK		Temp49		Temp49		Temp51
;getTempValue Srart:
PUSH	esi
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -112
POP	edx
;getTempAddr End:
MOV	edx, [esi]
POP	esi
;getTempValue End:
MOV	eax, edx
;getTempValue Srart:
PUSH	esi
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -116
POP	edx
;getTempAddr End:
MOV	edx, [esi]
POP	esi
;getTempValue End:
MOV	ebx, edx
SUB	edx, edx
IDIV	ebx
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -112
POP	edx
;getTempAddr End:
MOV	[esi], eax
;Call		fp_fact1_7		dst=Temp53		argc=1
MOV	esi, ebp
ADD	esi, 8
;MARK	esi, 8
LEA	edi, [ebp - 4]
PUSH	edi
PUSH	12
CALL	fp_fact1_7		
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -120
POP	edx
;getTempAddr End:
MOV	[esi], eax
ADD	esp, 8
;Assign		ADDTK		Temp49		Temp49		Temp53
;getTempValue Srart:
PUSH	esi
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -112
POP	edx
;getTempAddr End:
MOV	edx, [esi]
POP	esi
;getTempValue End:
MOV	eax, edx
;getTempValue Srart:
PUSH	esi
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -120
POP	edx
;getTempAddr End:
MOV	edx, [esi]
POP	esi
;getTempValue End:
MOV	ebx, edx
ADD	eax, ebx
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -112
POP	edx
;getTempAddr End:
MOV	[esi], eax
;Assign		SETTK		result		Temp49		
;getTempValue Srart:
PUSH	esi
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -112
POP	edx
;getTempAddr End:
MOV	edx, [esi]
POP	esi
;getTempValue End:
MOV	eax, edx
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -84
POP	edx
;getTempAddr End:
MOV	[esi], eax
;Call		fp_prime_9		dst=Temp54		argc=0
MOV	esi, ebp
ADD	esi, 8
;MARK	esi, 8
LEA	edi, [ebp - 4]
PUSH	edi
CALL	fp_prime_9		
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -124
POP	edx
;getTempAddr End:
MOV	[esi], eax
ADD	esp, 4
;Assign		SETTK		iprime		Temp54		
;getTempValue Srart:
PUSH	esi
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -124
POP	edx
;getTempAddr End:
MOV	edx, [esi]
POP	esi
;getTempValue End:
MOV	eax, edx
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -88
POP	edx
;getTempAddr End:
MOV	[esi], eax
;Call		fp_prime_9		dst=Temp55		argc=0
MOV	esi, ebp
ADD	esi, 8
;MARK	esi, 8
LEA	edi, [ebp - 4]
PUSH	edi
CALL	fp_prime_9		
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -128
POP	edx
;getTempAddr End:
MOV	[esi], eax
ADD	esp, 4
;Call		fp_fact1_7		dst=Temp56		argc=1
MOV	esi, ebp
ADD	esi, 8
;MARK	esi, 8
LEA	edi, [ebp - 4]
PUSH	edi
;getTempValue Srart:
PUSH	esi
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -128
POP	edx
;getTempAddr End:
MOV	edx, [esi]
POP	esi
;getTempValue End:
PUSH	edx
CALL	fp_fact1_7		
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -132
POP	edx
;getTempAddr End:
MOV	[esi], eax
ADD	esp, 8
;Assign		SETTK		ans1		Temp56		
;getTempValue Srart:
PUSH	esi
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -132
POP	edx
;getTempAddr End:
MOV	edx, [esi]
POP	esi
;getTempValue End:
MOV	eax, edx
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -92
POP	edx
;getTempAddr End:
MOV	[esi], eax
;Assign		ADDTK		Temp58		iprime		0
;getTempValue Srart:
PUSH	esi
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -88
POP	edx
;getTempAddr End:
MOV	edx, [esi]
POP	esi
;getTempValue End:
MOV	eax, edx
;getTempValue Srart:
PUSH	esi
MOV	edx, 0
POP	esi
;getTempValue End:
MOV	ebx, edx
ADD	eax, ebx
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -136
POP	edx
;getTempAddr End:
MOV	[esi], eax
;Call		fp_fact2_8		dst=Temp59		argc=1
MOV	esi, ebp
ADD	esi, 8
;MARK	esi, 8
LEA	edi, [ebp - 4]
PUSH	edi
;getTempValue Srart:
PUSH	esi
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -136
POP	edx
;getTempAddr End:
MOV	edx, [esi]
POP	esi
;getTempValue End:
PUSH	edx
CALL	fp_fact2_8		
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -140
POP	edx
;getTempAddr End:
MOV	[esi], eax
ADD	esp, 8
;Assign		SETTK		ans2		Temp59		
;getTempValue Srart:
PUSH	esi
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -140
POP	edx
;getTempAddr End:
MOV	edx, [esi]
POP	esi
;getTempValue End:
MOV	eax, edx
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -96
POP	edx
;getTempAddr End:
MOV	[esi], eax
;Call		fp_proc1_2		(no ret)	argc=0
MOV	esi, ebp
ADD	esi, 8
;MARK	esi, 8
LEA	edi, [ebp - 4]
PUSH	edi
CALL	fp_proc1_2		
ADD	esp, 4
;Assign		SETTK		i		2		
;getTempValue Srart:
PUSH	esi
MOV	edx, 2
POP	esi
;getTempValue End:
MOV	eax, edx
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -100
POP	edx
;getTempAddr End:
MOV	[esi], eax
;Label:		ondition
Label9:
;Assign		SETTK		j		i		
;getTempValue Srart:
PUSH	esi
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -100
POP	edx
;getTempAddr End:
MOV	edx, [esi]
POP	esi
;getTempValue End:
MOV	eax, edx
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -104
POP	edx
;getTempAddr End:
MOV	[esi], eax
;Label:		dition
Label11:
;Assign		ADDTK		Temp63		0		0
;getTempValue Srart:
PUSH	esi
MOV	edx, 0
POP	esi
;getTempValue End:
MOV	eax, edx
;getTempValue Srart:
PUSH	esi
MOV	edx, 0
POP	esi
;getTempValue End:
MOV	ebx, edx
ADD	eax, ebx
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -144
POP	edx
;getTempAddr End:
MOV	[esi], eax
;Assign		ADDTK		Temp64		i		j
;getTempValue Srart:
PUSH	esi
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -100
POP	edx
;getTempAddr End:
MOV	edx, [esi]
POP	esi
;getTempValue End:
MOV	eax, edx
;getTempValue Srart:
PUSH	esi
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -104
POP	edx
;getTempAddr End:
MOV	edx, [esi]
POP	esi
;getTempValue End:
MOV	ebx, edx
ADD	eax, ebx
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -148
POP	edx
;getTempAddr End:
MOV	[esi], eax
;Assign		SUBTK		Temp65		i		j
;getTempValue Srart:
PUSH	esi
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -100
POP	edx
;getTempAddr End:
MOV	edx, [esi]
POP	esi
;getTempValue End:
MOV	eax, edx
;getTempValue Srart:
PUSH	esi
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -104
POP	edx
;getTempAddr End:
MOV	edx, [esi]
POP	esi
;getTempValue End:
MOV	ebx, edx
SUB	eax, ebx
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -152
POP	edx
;getTempAddr End:
MOV	[esi], eax
;Assign		SETTK		arr[Temp64]		Temp65		
;getTempValue Srart:
PUSH	esi
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -152
POP	edx
;getTempAddr End:
MOV	edx, [esi]
POP	esi
;getTempValue End:
MOV	eax, edx
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -72
;getTempValue Srart:
PUSH	esi
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -148
POP	edx
;getTempAddr End:
MOV	edx, [esi]
POP	esi
;getTempValue End:
IMUL	edx, 4
ADD	esi, edx
POP	edx
;getTempAddr End:
MOV	[esi], eax
;LARGETK		Condition		LARGETK		i		Temp63		ition
;getTempValue Srart:
PUSH	esi
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -100
POP	edx
;getTempAddr End:
MOV	edx, [esi]
POP	esi
;getTempValue End:
MOV	eax, edx
;getTempValue Srart:
PUSH	esi
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -144
POP	edx
;getTempAddr End:
MOV	edx, [esi]
POP	esi
;getTempValue End:
MOV	ebx, edx
CMP	eax, ebx
JG	Label12
;Assign		SUBTK		j		j		1
;getTempValue Srart:
PUSH	esi
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -104
POP	edx
;getTempAddr End:
MOV	edx, [esi]
POP	esi
;getTempValue End:
MOV	eax, edx
;getTempValue Srart:
PUSH	esi
MOV	edx, 1
POP	esi
;getTempValue End:
MOV	ebx, edx
SUB	eax, ebx
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -104
POP	edx
;getTempAddr End:
MOV	[esi], eax
;Goto:		dition
JMP	Label11
;Label:		ition
Label12:
;SMALLTK		Condition		SMALLTK		2		inputi		ndition
;getTempValue Srart:
PUSH	esi
MOV	edx, 2
POP	esi
;getTempValue End:
MOV	eax, edx
;getTempValue Srart:
PUSH	esi
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -80
POP	edx
;getTempAddr End:
MOV	edx, [esi]
POP	esi
;getTempValue End:
MOV	ebx, edx
CMP	eax, ebx
JL	Label10
;Assign		ADDTK		i		i		1
;getTempValue Srart:
PUSH	esi
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -100
POP	edx
;getTempAddr End:
MOV	edx, [esi]
POP	esi
;getTempValue End:
MOV	eax, edx
;getTempValue Srart:
PUSH	esi
MOV	edx, 1
POP	esi
;getTempValue End:
MOV	ebx, edx
ADD	eax, ebx
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -100
POP	edx
;getTempAddr End:
MOV	[esi], eax
;Goto:		ondition
JMP	Label9
;Label:		ndition
Label10:
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
;FP:(2)		fp_proc1_2
fp_proc1_2:
PUSH	ebp
MOV	ebp, esp
PUSH	eax
PUSH	ebx
PUSH	ecx
PUSH	edx
PUSH	esi
PUSH	edi
SUB	esp, 80
;Assign		SUBTK		Temp6		0		1
;getTempValue Srart:
PUSH	esi
MOV	edx, 0
POP	esi
;getTempValue End:
MOV	eax, edx
;getTempValue Srart:
PUSH	esi
MOV	edx, 1
POP	esi
;getTempValue End:
MOV	ebx, edx
SUB	eax, ebx
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -52
POP	edx
;getTempAddr End:
MOV	[esi], eax
;Assign		SUBTK		Temp6		0		Temp6
;getTempValue Srart:
PUSH	esi
MOV	edx, 0
POP	esi
;getTempValue End:
MOV	eax, edx
;getTempValue Srart:
PUSH	esi
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -52
POP	edx
;getTempAddr End:
MOV	edx, [esi]
POP	esi
;getTempValue End:
MOV	ebx, edx
SUB	eax, ebx
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -52
POP	edx
;getTempAddr End:
MOV	[esi], eax
;Assign		SETTK		t[0]		Temp6		
;getTempValue Srart:
PUSH	esi
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -52
POP	edx
;getTempAddr End:
MOV	edx, [esi]
POP	esi
;getTempValue End:
MOV	eax, edx
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -40
;getTempValue Srart:
PUSH	esi
MOV	edx, 0
POP	esi
;getTempValue End:
IMUL	edx, 4
ADD	esi, edx
POP	edx
;getTempAddr End:
MOV	[esi], eax
;Assign		MULTK		Temp11		18		3
;getTempValue Srart:
PUSH	esi
MOV	edx, 18
POP	esi
;getTempValue End:
MOV	eax, edx
;getTempValue Srart:
PUSH	esi
MOV	edx, 3
POP	esi
;getTempValue End:
MOV	ebx, edx
IMUL	eax, ebx
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -56
POP	edx
;getTempAddr End:
MOV	[esi], eax
;Assign		DIVTK		Temp11		Temp11		6
;getTempValue Srart:
PUSH	esi
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -56
POP	edx
;getTempAddr End:
MOV	edx, [esi]
POP	esi
;getTempValue End:
MOV	eax, edx
;getTempValue Srart:
PUSH	esi
MOV	edx, 6
POP	esi
;getTempValue End:
MOV	ebx, edx
SUB	edx, edx
IDIV	ebx
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -56
POP	edx
;getTempAddr End:
MOV	[esi], eax
;Assign		SUBTK		Temp11		10		Temp11
;getTempValue Srart:
PUSH	esi
MOV	edx, 10
POP	esi
;getTempValue End:
MOV	eax, edx
;getTempValue Srart:
PUSH	esi
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -56
POP	edx
;getTempAddr End:
MOV	edx, [esi]
POP	esi
;getTempValue End:
MOV	ebx, edx
SUB	eax, ebx
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -56
POP	edx
;getTempAddr End:
MOV	[esi], eax
;Assign		SETTK		t[1]		Temp11		
;getTempValue Srart:
PUSH	esi
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -56
POP	edx
;getTempAddr End:
MOV	edx, [esi]
POP	esi
;getTempValue End:
MOV	eax, edx
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -40
;getTempValue Srart:
PUSH	esi
MOV	edx, 1
POP	esi
;getTempValue End:
IMUL	edx, 4
ADD	esi, edx
POP	edx
;getTempAddr End:
MOV	[esi], eax
;Assign		SUBTK		Temp16		2		0
;getTempValue Srart:
PUSH	esi
MOV	edx, 2
POP	esi
;getTempValue End:
MOV	eax, edx
;getTempValue Srart:
PUSH	esi
MOV	edx, 0
POP	esi
;getTempValue End:
MOV	ebx, edx
SUB	eax, ebx
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -60
POP	edx
;getTempAddr End:
MOV	[esi], eax
;Assign		SUBTK		Temp16		Temp16		0
;getTempValue Srart:
PUSH	esi
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -60
POP	edx
;getTempAddr End:
MOV	edx, [esi]
POP	esi
;getTempValue End:
MOV	eax, edx
;getTempValue Srart:
PUSH	esi
MOV	edx, 0
POP	esi
;getTempValue End:
MOV	ebx, edx
SUB	eax, ebx
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -60
POP	edx
;getTempAddr End:
MOV	[esi], eax
;Assign		SETTK		t[2]		Temp16		
;getTempValue Srart:
PUSH	esi
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -60
POP	edx
;getTempAddr End:
MOV	edx, [esi]
POP	esi
;getTempValue End:
MOV	eax, edx
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -40
;getTempValue Srart:
PUSH	esi
MOV	edx, 2
POP	esi
;getTempValue End:
IMUL	edx, 4
ADD	esi, edx
POP	edx
;getTempAddr End:
MOV	[esi], eax
;Assign		DIVTK		Temp20		6		2
;getTempValue Srart:
PUSH	esi
MOV	edx, 6
POP	esi
;getTempValue End:
MOV	eax, edx
;getTempValue Srart:
PUSH	esi
MOV	edx, 2
POP	esi
;getTempValue End:
MOV	ebx, edx
SUB	edx, edx
IDIV	ebx
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -64
POP	edx
;getTempAddr End:
MOV	[esi], eax
;Assign		SETTK		i		Temp20		
;getTempValue Srart:
PUSH	esi
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -64
POP	edx
;getTempAddr End:
MOV	edx, [esi]
POP	esi
;getTempValue End:
MOV	eax, edx
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -44
POP	edx
;getTempAddr End:
MOV	[esi], eax
;Label:		Label
Label0:
;Assign		ADDTK		Temp23		2		4
;getTempValue Srart:
PUSH	esi
MOV	edx, 2
POP	esi
;getTempValue End:
MOV	eax, edx
;getTempValue Srart:
PUSH	esi
MOV	edx, 4
POP	esi
;getTempValue End:
MOV	ebx, edx
ADD	eax, ebx
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -68
POP	edx
;getTempAddr End:
MOV	[esi], eax
;Assign		SUBTK		Temp25		i		1
;getTempValue Srart:
PUSH	esi
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -44
POP	edx
;getTempAddr End:
MOV	edx, [esi]
POP	esi
;getTempValue End:
MOV	eax, edx
;getTempValue Srart:
PUSH	esi
MOV	edx, 1
POP	esi
;getTempValue End:
MOV	ebx, edx
SUB	eax, ebx
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -72
POP	edx
;getTempAddr End:
MOV	[esi], eax
;Assign		SUBTK		Temp27		i		2
;getTempValue Srart:
PUSH	esi
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -44
POP	edx
;getTempAddr End:
MOV	edx, [esi]
POP	esi
;getTempValue End:
MOV	eax, edx
;getTempValue Srart:
PUSH	esi
MOV	edx, 2
POP	esi
;getTempValue End:
MOV	ebx, edx
SUB	eax, ebx
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -76
POP	edx
;getTempAddr End:
MOV	[esi], eax
;Assign		ADDTK		Temp28		t[Temp25]		t[Temp27]
;getTempValue Srart:
PUSH	esi
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -40
;getTempValue Srart:
PUSH	esi
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -72
POP	edx
;getTempAddr End:
MOV	edx, [esi]
POP	esi
;getTempValue End:
IMUL	edx, 4
ADD	esi, edx
POP	edx
;getTempAddr End:
MOV	edx, [esi]
POP	esi
;getTempValue End:
MOV	eax, edx
;getTempValue Srart:
PUSH	esi
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -40
;getTempValue Srart:
PUSH	esi
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -76
POP	edx
;getTempAddr End:
MOV	edx, [esi]
POP	esi
;getTempValue End:
IMUL	edx, 4
ADD	esi, edx
POP	edx
;getTempAddr End:
MOV	edx, [esi]
POP	esi
;getTempValue End:
MOV	ebx, edx
ADD	eax, ebx
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -80
POP	edx
;getTempAddr End:
MOV	[esi], eax
;Assign		SETTK		t[i]		Temp28		
;getTempValue Srart:
PUSH	esi
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -80
POP	edx
;getTempAddr End:
MOV	edx, [esi]
POP	esi
;getTempValue End:
MOV	eax, edx
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -40
;getTempValue Srart:
PUSH	esi
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -44
POP	edx
;getTempAddr End:
MOV	edx, [esi]
POP	esi
;getTempValue End:
IMUL	edx, 4
ADD	esi, edx
POP	edx
;getTempAddr End:
MOV	[esi], eax
;SMALLTK		Condition		SMALLTK		Temp20		Temp23		abel
;getTempValue Srart:
PUSH	esi
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -64
POP	edx
;getTempAddr End:
MOV	edx, [esi]
POP	esi
;getTempValue End:
MOV	eax, edx
;getTempValue Srart:
PUSH	esi
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -68
POP	edx
;getTempAddr End:
MOV	edx, [esi]
POP	esi
;getTempValue End:
MOV	ebx, edx
CMP	eax, ebx
JL	Label1
;Assign		ADDTK		i		i		1
;getTempValue Srart:
PUSH	esi
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -44
POP	edx
;getTempAddr End:
MOV	edx, [esi]
POP	esi
;getTempValue End:
MOV	eax, edx
;getTempValue Srart:
PUSH	esi
MOV	edx, 1
POP	esi
;getTempValue End:
MOV	ebx, edx
ADD	eax, ebx
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -44
POP	edx
;getTempAddr End:
MOV	[esi], eax
;Goto:		Label
JMP	Label0
;Label:		abel
Label1:
;Assign		SETTK		tmp		t[2]		
;getTempValue Srart:
PUSH	esi
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -40
;getTempValue Srart:
PUSH	esi
MOV	edx, 2
POP	esi
;getTempValue End:
IMUL	edx, 4
ADD	esi, edx
POP	edx
;getTempAddr End:
MOV	edx, [esi]
POP	esi
;getTempValue End:
MOV	eax, edx
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -48
POP	edx
;getTempAddr End:
MOV	[esi], eax
;Call		fp_proc2_3		(no ret)	argc=3
MOV	esi, ebp
ADD	esi, 12
PUSH	[esi - 4]
;MARK	[esi - 4]
LEA	edi, [ebp - 4]
PUSH	edi
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
;add display offset to esi:
ADD	esi, 8
;display is to esi:
MOV	esi, [esi]
POP	edx
;getTempAddr End:
PUSH	esi
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -40
;getTempValue Srart:
PUSH	esi
MOV	edx, 1
POP	esi
;getTempValue End:
IMUL	edx, 4
ADD	esi, edx
POP	edx
;getTempAddr End:
PUSH	esi
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -40
;getTempValue Srart:
PUSH	esi
MOV	edx, 2
POP	esi
;getTempValue End:
IMUL	edx, 4
ADD	esi, edx
POP	edx
;getTempAddr End:
PUSH	esi
CALL	fp_proc2_3		
ADD	esp, 20
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
;FP:(3)		fp_proc2_3
fp_proc2_3:
PUSH	ebp
MOV	ebp, esp
PUSH	eax
PUSH	ebx
PUSH	ecx
PUSH	edx
PUSH	esi
PUSH	edi
SUB	esp, 4
;Assign		SUBTK		Temp3		0		b1
;getTempValue Srart:
PUSH	esi
MOV	edx, 0
POP	esi
;getTempValue End:
MOV	eax, edx
;getTempValue Srart:
PUSH	esi
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
;add display offset to esi:
ADD	esi, 24
;display is to esi:
MOV	esi, [esi]
POP	edx
;getTempAddr End:
MOV	edx, [esi]
POP	esi
;getTempValue End:
MOV	ebx, edx
SUB	eax, ebx
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -4
POP	edx
;getTempAddr End:
MOV	[esi], eax
;Assign		ADDTK		Temp3		a2		Temp3
;getTempValue Srart:
PUSH	esi
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
;add display offset to esi:
ADD	esi, 24
;display is to esi:
MOV	esi, [esi]
POP	edx
;getTempAddr End:
MOV	edx, [esi]
POP	esi
;getTempValue End:
MOV	eax, edx
;getTempValue Srart:
PUSH	esi
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -4
POP	edx
;getTempAddr End:
MOV	edx, [esi]
POP	esi
;getTempValue End:
MOV	ebx, edx
ADD	eax, ebx
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -4
POP	edx
;getTempAddr End:
MOV	[esi], eax
;Assign		SETTK		a2		Temp3		
;getTempValue Srart:
PUSH	esi
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -4
POP	edx
;getTempAddr End:
MOV	edx, [esi]
POP	esi
;getTempValue End:
MOV	eax, edx
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
;add display offset to esi:
ADD	esi, 24
;display is to esi:
MOV	esi, [esi]
POP	edx
;getTempAddr End:
MOV	[esi], eax
;Call		fp_proc3_4		(no ret)	argc=0
MOV	esi, ebp
ADD	esi, 28
PUSH	[esi - 4]
PUSH	[esi - 8]
;MARK	[esi - 8]
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



;NODE : 4
;FP:(4)		fp_proc3_4
fp_proc3_4:
PUSH	ebp
MOV	ebp, esp
PUSH	eax
PUSH	ebx
PUSH	ecx
PUSH	edx
PUSH	esi
PUSH	edi
SUB	esp, 4
;Assign		SETTK		tmp		10		
;getTempValue Srart:
PUSH	esi
MOV	edx, 10
POP	esi
;getTempValue End:
MOV	eax, edx
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -4
POP	edx
;getTempAddr End:
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



;NODE : 5
;FP:(5)		fp_proc2_5
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



;NODE : 6
;FP:(6)		fp_proc3_6
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



;NODE : 7
;FP:(7)		fp_fact1_7
fp_fact1_7:
PUSH	ebp
MOV	ebp, esp
PUSH	ebx
PUSH	ecx
PUSH	edx
PUSH	esi
PUSH	edi
SUB	esp, 12
;Label:LARGEEQUTK		Condition		LARGEEQUTK		0		0		bel
;getTempValue Srart:
PUSH	esi
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, 8
POP	edx
;getTempAddr End:
MOV	edx, [esi]
POP	esi
;getTempValue End:
MOV	eax, edx
;getTempValue Srart:
PUSH	esi
MOV	edx, 0
POP	esi
;getTempValue End:
MOV	ebx, edx
CMP	eax, ebx
JNL	Label2
;Assign		SETTK		0		0		
;getTempValue Srart:
PUSH	esi
MOV	edx, 0
POP	esi
;getTempValue End:
MOV	eax, edx
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, 8
POP	edx
;getTempAddr End:
MOV	[esi], eax
;Goto:		el
JMP	Label3
;Label:		bel
Label2:
;Label:		el
Label3:
;bel:NEQUTK		Condition		NEQUTK		0		0		l
;getTempValue Srart:
PUSH	esi
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, 8
POP	edx
;getTempAddr End:
MOV	edx, [esi]
POP	esi
;getTempValue End:
MOV	eax, edx
;getTempValue Srart:
PUSH	esi
MOV	edx, 0
POP	esi
;getTempValue End:
MOV	ebx, edx
CMP	eax, ebx
JNE	Label4
;Assign		SETTK		fact1		1		
;getTempValue Srart:
PUSH	esi
MOV	edx, 1
POP	esi
;getTempValue End:
MOV	eax, edx
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -4
POP	edx
;getTempAddr End:
MOV	[esi], eax
;Goto:		
JMP	Label5
;Label:		l
Label4:
;Assign		SUBTK		Temp37		0		1
;getTempValue Srart:
PUSH	esi
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, 8
POP	edx
;getTempAddr End:
MOV	edx, [esi]
POP	esi
;getTempValue End:
MOV	eax, edx
;getTempValue Srart:
PUSH	esi
MOV	edx, 1
POP	esi
;getTempValue End:
MOV	ebx, edx
SUB	eax, ebx
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -8
POP	edx
;getTempAddr End:
MOV	[esi], eax
;Call		fp_fact1_7		dst=Temp38		argc=1
MOV	esi, ebp
ADD	esi, 16
PUSH	[esi - 4]
;getTempValue Srart:
PUSH	esi
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -8
POP	edx
;getTempAddr End:
MOV	edx, [esi]
POP	esi
;getTempValue End:
PUSH	edx
CALL	fp_fact1_7		
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -12
POP	edx
;getTempAddr End:
MOV	[esi], eax
ADD	esp, 8
;Assign		MULTK		Temp38		Temp38		0
;getTempValue Srart:
PUSH	esi
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -12
POP	edx
;getTempAddr End:
MOV	edx, [esi]
POP	esi
;getTempValue End:
MOV	eax, edx
;getTempValue Srart:
PUSH	esi
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, 8
POP	edx
;getTempAddr End:
MOV	edx, [esi]
POP	esi
;getTempValue End:
MOV	ebx, edx
IMUL	eax, ebx
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -12
POP	edx
;getTempAddr End:
MOV	[esi], eax
;Assign		SETTK		fact1		Temp38		
;getTempValue Srart:
PUSH	esi
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -12
POP	edx
;getTempAddr End:
MOV	edx, [esi]
POP	esi
;getTempValue End:
MOV	eax, edx
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -4
POP	edx
;getTempAddr End:
MOV	[esi], eax
;Label:		
Label5:
;Call		fp_proc2_5		(no ret)	argc=3
MOV	esi, ebp
ADD	esi, 16
PUSH	[esi - 4]
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
;add display offset to esi:
ADD	esi, 12
;display is to esi:
MOV	esi, [esi]
POP	edx
;getTempAddr End:
PUSH	esi
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
;add display offset to esi:
ADD	esi, 12
;display is to esi:
MOV	esi, [esi]
POP	edx
;getTempAddr End:
PUSH	esi
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
;add display offset to esi:
ADD	esi, 12
;display is to esi:
MOV	esi, [esi]
POP	edx
;getTempAddr End:
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



;NODE : 8
;FP:(8)		fp_fact2_8
fp_fact2_8:
PUSH	ebp
MOV	ebp, esp
PUSH	ebx
PUSH	ecx
PUSH	edx
PUSH	esi
PUSH	edi
SUB	esp, 16
;Call		fp_proc3_6		(no ret)	argc=3
MOV	esi, ebp
ADD	esi, 16
PUSH	[esi - 4]
;getTempValue Srart:
PUSH	esi
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
;add display offset to esi:
ADD	esi, 12
;display is to esi:
MOV	esi, [esi]
POP	edx
;getTempAddr End:
MOV	edx, [esi]
POP	esi
;getTempValue End:
PUSH	edx
;getTempValue Srart:
PUSH	esi
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
;add display offset to esi:
ADD	esi, 12
;display is to esi:
MOV	esi, [esi]
POP	edx
;getTempAddr End:
MOV	edx, [esi]
POP	esi
;getTempValue End:
PUSH	edx
;getTempValue Srart:
PUSH	esi
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
;add display offset to esi:
ADD	esi, 12
;display is to esi:
MOV	esi, [esi]
POP	edx
;getTempAddr End:
MOV	edx, [esi]
POP	esi
;getTempValue End:
PUSH	edx
CALL	fp_proc3_6		
ADD	esp, 16
;LARGETK		Condition		LARGETK		0		1		
;getTempValue Srart:
PUSH	esi
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, 8
POP	edx
;getTempAddr End:
MOV	edx, [esi]
POP	esi
;getTempValue End:
MOV	eax, edx
;getTempValue Srart:
PUSH	esi
MOV	edx, 1
POP	esi
;getTempValue End:
MOV	ebx, edx
CMP	eax, ebx
JG	Label6
;Assign		SETTK		0		1		
;getTempValue Srart:
PUSH	esi
MOV	edx, 1
POP	esi
;getTempValue End:
MOV	eax, edx
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, 8
POP	edx
;getTempAddr End:
MOV	[esi], eax
;Goto:		
JMP	Label7
;Label:		
Label6:
;Label:		
Label7:
;Assign		SETTK		temp		1		
;getTempValue Srart:
PUSH	esi
MOV	edx, 1
POP	esi
;getTempValue End:
MOV	eax, edx
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -8
POP	edx
;getTempAddr End:
MOV	[esi], eax
;Label:		Condition
Label8:
;Assign		MULTK		Temp42		temp		0
;getTempValue Srart:
PUSH	esi
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -8
POP	edx
;getTempAddr End:
MOV	edx, [esi]
POP	esi
;getTempValue End:
MOV	eax, edx
;getTempValue Srart:
PUSH	esi
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, 8
POP	edx
;getTempAddr End:
MOV	edx, [esi]
POP	esi
;getTempValue End:
MOV	ebx, edx
IMUL	eax, ebx
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -12
POP	edx
;getTempAddr End:
MOV	[esi], eax
;Assign		SETTK		temp		Temp42		
;getTempValue Srart:
PUSH	esi
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -12
POP	edx
;getTempAddr End:
MOV	edx, [esi]
POP	esi
;getTempValue End:
MOV	eax, edx
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -8
POP	edx
;getTempAddr End:
MOV	[esi], eax
;Assign		SUBTK		Temp44		0		1
;getTempValue Srart:
PUSH	esi
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, 8
POP	edx
;getTempAddr End:
MOV	edx, [esi]
POP	esi
;getTempValue End:
MOV	eax, edx
;getTempValue Srart:
PUSH	esi
MOV	edx, 1
POP	esi
;getTempValue End:
MOV	ebx, edx
SUB	eax, ebx
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -16
POP	edx
;getTempAddr End:
MOV	[esi], eax
;Assign		SETTK		0		Temp44		
;getTempValue Srart:
PUSH	esi
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -16
POP	edx
;getTempAddr End:
MOV	edx, [esi]
POP	esi
;getTempValue End:
MOV	eax, edx
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, 8
POP	edx
;getTempAddr End:
MOV	[esi], eax
;Label:LARGEEQUTK		Condition		LARGEEQUTK		0		1		Condition
;getTempValue Srart:
PUSH	esi
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, 8
POP	edx
;getTempAddr End:
MOV	edx, [esi]
POP	esi
;getTempValue End:
MOV	eax, edx
;getTempValue Srart:
PUSH	esi
MOV	edx, 1
POP	esi
;getTempValue End:
MOV	ebx, edx
CMP	eax, ebx
JNL	Label8
;Assign		SETTK		fact2		temp		
;getTempValue Srart:
PUSH	esi
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -8
POP	edx
;getTempAddr End:
MOV	edx, [esi]
POP	esi
;getTempValue End:
MOV	eax, edx
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -4
POP	edx
;getTempAddr End:
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



;NODE : 9
;FP:(9)		fp_prime_9
fp_prime_9:
PUSH	ebp
MOV	ebp, esp
PUSH	ebx
PUSH	ecx
PUSH	edx
PUSH	esi
PUSH	edi
SUB	esp, 4
;Assign		SETTK		prime		7		
;getTempValue Srart:
PUSH	esi
MOV	edx, 7
POP	esi
;getTempValue End:
MOV	eax, edx
;getTempAddr Srart:
PUSH	edx
MOV	esi, ebp
ADD	esi, -4
POP	edx
;getTempAddr End:
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
