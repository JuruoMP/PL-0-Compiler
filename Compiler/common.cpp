#include <iostream>
#include "common.h"

std::string int2string(int num)
{
	char value[256];
	sprintf_s(value, 256 - 1, "%d", num);
	std::string str = value;
	return str;
}