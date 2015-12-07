#include "Asm.h"

char* opcode[32] = {
	"MOV", "PUSH", "POP", "PUSHA", "POPA", "PUSHAD", "POPAD", "XCHG",
	"LEA", "LDS", "LES", "LFS", "LGS", "LSS",
	"LAHF", "SAHF", "PUSHF", "POPF", "PUSHD", "POPD",
	"JMP", "CALL", "RET",
	"ADD", "SUB", "MUL", "DIV", "INC", "DEC", "NEC", "CMP"
};

Asm::Asm(char* label_name)
{
	this->is_label = true;
	strcpy_s(this->label_name, MAXLEN - 1, label_name);
}

Asm::Asm(ASMTYPE type, std::vector<std::string> args)
{
	this->is_label = false;
	this->m_type = type;
	for (int i = 0; i < args.size(); ++i)
		this->m_args.push_back(args.at(i));
}

void Asm::print()
{
	if (this->is_label)
	{
		std::cout << this->label_name << ":" << std::endl;
	}
	else
	{
		printf("%s\t", opcode[this->m_type]);
		for (unsigned int i = 0; i < this->m_args.size(); ++i)
			std::cout << this->m_args.at(i) << "\t";
		std::cout << std::endl;
	}
}

