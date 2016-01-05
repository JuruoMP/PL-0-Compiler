#ifndef ASM_H
#define ASM_H

#include <vector>
#include <string>
#include <iostream>
#include "SymbolTable.h"
#include "Symbol.h"

enum ASMTYPE
{
	ASMMOV,
	ASMPUSH,
	ASMPOP,
	ASMPUSHA,
	ASMPOPA,
	ASMPUSHAD,
	ASMPOPAD,
	ASMXCHG,

	ASMLEA,
	ASMLDS,
	ASMLES,
	ASMLFS,
	ASMLGS,
	ASMLSS,

	ASMLAHF,
	ASMSAHF,
	ASMPUSHF,
	ASMPOPF,
	ASMPUSHD,
	ASMPOPD,

	ASMJMP,
	ASMCALL,
	ASMRET,

	ASMADD,
	ASMSUB,
	ASMMUL,
	ASMDIV,
	ASMINC,
	ASMDEC,
	ASMNEC,
	ASMCDQ,
	
	ASMCMP,
	ASMJE,//jump equal
	ASMJNE,//jump not equal
	ASMJL,//jump less
	ASMJNL,//jump not less
	ASMJG,//jump greater
	ASMJNG,//jump not greater

	ASMMARK,
	ASMORIGIN
	
};

extern char* opcode[64];

enum REGISTER
{
	EAX,
	EBX,
	ECX,
	EDX,
	ESI,
	EDI,
	ESP,//bottom of stack frame
	EBP,//top of stack frame
};

class Asm
{
public:
	bool is_label;
	char label_name[MAXLEN];
	ASMTYPE m_type;
	std::vector<std::string> m_args;
	Asm(char* label_name);
	Asm(ASMTYPE type, std::vector<std::string> args);
	bool reg_same(std::string reg);
#ifdef _DEBUG
	bool is_str;
	std::string str;
	Asm(std::string str);
#endif
	void print();
};

#endif
