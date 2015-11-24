#ifndef MEMORY_H
#define MEMORY_H

typedef int ADDR;

//Singleton class Memory
class Memory
{
private:
	const static ADDR MEMTOP = 0xffffffff - 0xffff;
	static ADDR ptr;
	static Memory* memory;
	Memory() { this->ptr = 0; }
public:
	Memory* getInstance()
	{
		return this->memory;
	}
	public ADDR 
};

#endif