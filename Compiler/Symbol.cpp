#include "Symbol.h"
#include <cstring>
#include <cstdio>
#include <iostream>

#define SYMBOLCHECK

static FILE* fp;
static SymbolTK symbolTK;
static POSITION pos;

std::vector<WORD> word_list;
char token_name[][16] = {
	"ARRAYTK", "INTTK", "CHARTK", "CONSTTK", "VARTK", "IFTK", "THENTK", "ELSETK",
	"DOTK", "WHILETK", "FORTK", "TOTK", "DOWNTOTK", "BEGINTK", "ENDTK", "READTK",
	"WRITETK", "PROCTK", "FUNCTK", "COMMATK", "SEMICOLONTK", "LPARENTTK", "RPARENTTK", "LSQRBRACTK",
	"RSQRBRACTK", "COLONTK", "SETTK", "ADDTK", "SUBTK", "MULTK", "DIVTK", "SQUOTETK",
	"DQUOTETK", "SMALLTK", "SMALLEQUTK", "LARGETK", "LARGEEQUTK", "EQUTK", "NEQUTK", "ITK", "IDENTTK", 
	"DOTTK", "OFTK", "ERRTK", "EMPTYTK"
};

Symbol::Symbol(const char* filename)
{
	strcpy_s(this->mfilename, MAXLEN - 1, filename);
}

char Symbol::mgetchar()
{
	char c;
	static int linenum = -1;
	static int colnum = 0;
	static char line[2048];
	static int len = 0;
	if (colnum < len)
	{
		pos.mlineno = linenum;
		pos.mcolno = colnum;
		c = line[colnum];
		colnum++;
#ifdef SymbolDEBUG
		printf("%c", c);
#endif
		return c;
	}
	else if (colnum == len)
	{
		colnum++;
		return '\n';
	}
	else
	{
		if (fgets(line, 2000, fp) != NULL)
		{
			len = strlen(line);
			linenum++;
			colnum = 0;
			pos.mlineno = linenum;
			pos.mcolno = colnum;
			c = line[colnum];
			colnum++;
#ifdef SymbolDEBUG
			printf("%c", c);
#endif
			return c;
		}
		else
		{
#ifdef SymbolDEBUG
			printf("\nREACH END OF FILE.\n");
#endif
			return NULL;
		}
	}
}

void Symbol::mgetsym()
{
#ifndef _MSC_VER
	fp = fopen(this->mfilename, "r");
#else
	int err = fopen_s(&fp, this->mfilename, "r");
#endif
	char c = ' ';
	while (true)
	{
		while (c == ' ' || c == '\n' || c == '\t')
			c = this->mgetchar();
		if (c == NULL)
			break;
		if (isalpha(c))
		{
			POSITION word_pos(pos);
			int l = 0;
			char word[MAXLEN];
			memset(word, 0, sizeof(word));
			word[l] = c;
			c = this->mgetchar();
			while (isalpha(c) || isdigit(c))
			{
				l++;
				word[l] = c;
				c = this->mgetchar();
			}
			word[++l] = '\0';
			if (!strcmp(word, "array"))
				symbolTK = ARRAYTK;
			else if (!strcmp(word, "integer"))
				symbolTK = INTTK;
			else if (!strcmp(word, "char"))
				symbolTK = CHARTK;
			else if (!strcmp(word, "const"))
				symbolTK = CONSTTK;
			else if (!strcmp(word, "var"))
				symbolTK = VARTK;
			else if (!strcmp(word, "if"))
				symbolTK = IFTK;
			else if (!strcmp(word, "then"))
				symbolTK = THENTK;
			else if (!strcmp(word, "else"))
				symbolTK = ELSETK;
			else if (!strcmp(word, "do"))
				symbolTK = DOTK;
			else if (!strcmp(word, "while"))
				symbolTK = WHILETK;
			else if (!strcmp(word, "for"))
				symbolTK = FORTK;
			else if (!strcmp(word, "to"))
				symbolTK = TOTK;
			else if (!strcmp(word, "downto"))
				symbolTK = DOWNTOTK;
			else if (!strcmp(word, "begin"))
				symbolTK = BEGINTK;
			else if (!strcmp(word, "end"))
				symbolTK = ENDTK;
			else if (!strcmp(word, "read"))
				symbolTK = READTK;
			else if (!strcmp(word, "write"))
				symbolTK = WRITETK;
			else if (!strcmp(word, "procedure"))
				symbolTK = PROCTK;
			else if (!strcmp(word, "function"))
				symbolTK = FUNCTK;
			else if (!strcmp(word, "of"))
				symbolTK = OFTK;
			else
				symbolTK = IDENTTK;
			WORD new_word(word_pos, symbolTK, word);
			word_list.push_back(new_word);
		}
		else if (isdigit(c))
		{
			POSITION word_pos(pos);
			int num = c - '0';
			c = this->mgetchar();
			while (isdigit(c))
			{
				num = 10 * num + c - '0';
				c = this->mgetchar();
			}
			symbolTK = ITK;
			WORD new_word(word_pos, symbolTK, num);
			word_list.push_back(new_word);
		}
		else if (c == ',')
		{
			POSITION word_pos(pos);
			c = this->mgetchar();
			symbolTK = COMMATK;
			WORD new_word(word_pos, symbolTK, 0);
			word_list.push_back(new_word);
		}
		else if (c == ';')
		{
			POSITION word_pos(pos);
			c = this->mgetchar();
			symbolTK = SEMICOLONTK;
			WORD new_word(word_pos, symbolTK, 0);
			word_list.push_back(new_word);
		}
		else if (c == '(')
		{
			POSITION word_pos(pos);
			c = this->mgetchar();
			symbolTK = LPARENTTK;
			WORD new_word(word_pos, symbolTK, 0);
			word_list.push_back(new_word);
		}
		else if (c == ')')
		{
			POSITION word_pos(pos);
			c = this->mgetchar();
			symbolTK = RPARENTTK;
			WORD new_word(word_pos, symbolTK, 0);
			word_list.push_back(new_word);
		}
		else if (c == '[')
		{
			POSITION word_pos(pos);
			c = this->mgetchar();
			symbolTK = LSQRBRACTK;
			WORD new_word(word_pos, symbolTK, 0);
			word_list.push_back(new_word);
		}
		else if (c == ']')
		{
			POSITION word_pos(pos);
			c = this->mgetchar();
			symbolTK = RSQRBRACTK;
			WORD new_word(word_pos, symbolTK, 0);
			word_list.push_back(new_word);
		}
		else if (c == ':')
		{
			POSITION word_pos(pos);
			c = this->mgetchar();
			if (c == '=')
			{
				c = this->mgetchar();
				symbolTK = SETTK;
			}
			else
			{
				symbolTK = COLONTK;
			}
			WORD new_word(word_pos, symbolTK, 0);
			word_list.push_back(new_word);
		}
		else if (c == '+')
		{
			POSITION word_pos(pos);
			c = this->mgetchar();
			symbolTK = ADDTK;
			WORD new_word(word_pos, symbolTK, 0);
			word_list.push_back(new_word);
		}
		else if (c == '-')
		{
			POSITION word_pos(pos);
			c = this->mgetchar();
			symbolTK = SUBTK;
			WORD new_word(word_pos, symbolTK, 0);
			word_list.push_back(new_word);
		}
		else if (c == '*')
		{
			POSITION word_pos(pos);
			c = this->mgetchar();
			symbolTK = MULTK;
			WORD new_word(word_pos, symbolTK, 0);
			word_list.push_back(new_word);
		}
		else if (c == '/')
		{
			POSITION word_pos(pos);
			c = this->mgetchar();
			symbolTK = DIVTK;
			WORD new_word(word_pos, symbolTK, 0);
			word_list.push_back(new_word);
		}
		else if (c == '\'')
		{
			POSITION word_pos(pos);
			c = this->mgetchar();
			int value;
			if (isalpha(c) || isdigit(c))
				value = c;
			else
				this->error(word_pos, c, '\'');
			c = this->mgetchar();
			if (c != '\'')
				this->error(word_pos, c, '\'');
			c = this->mgetchar();
			symbolTK = SQUOTETK;
			WORD new_word(word_pos, symbolTK, value);
			word_list.push_back(new_word);
		}
		else if (c == '"')
		{
			POSITION word_pos(pos);
			char value[MAXLEN];
 			bool reach = false, err = false;
			c = this->mgetchar();
			int len;
			for (len = 0; len < MAXLEN - 1; ++len)
			{
				if (c == '"')
				{
					reach = true;
					break;
				}
				else if (c == '\n')
				{
					this->error(word_pos, c);
					err = true;
					reach = true;
					break;
				}
				else
				{
					value[len] = c;
					c = this->mgetchar();
				}
			}
			if (!err && !reach)
				this->error(word_pos, c, '"');
			else if (!err && reach)
			{
				value[len] = '\0';
				symbolTK = DQUOTETK;
				WORD new_word(word_pos, symbolTK, value);
				word_list.push_back(new_word);
			}
			c = this->mgetchar();
		}
		else if (c == '<')
		{
			POSITION word_pos(pos);
			c = this->mgetchar();
			if (c == '=')
			{
				c = this->mgetchar();
				symbolTK = SMALLEQUTK;
			}
			else if (c == '>')
			{
				c = this->mgetchar();
				symbolTK = NEQUTK;
			}
			else
			{
				symbolTK = SMALLTK;
			}
			WORD new_word(word_pos, symbolTK, 0);
			word_list.push_back(new_word);
		}
		else if (c == '>')
		{
			POSITION word_pos(pos);
			c = this->mgetchar();
			if (c == '=')
			{
				c = this->mgetchar();
				symbolTK = LARGEEQUTK;
			}
			else
			{
				symbolTK = LARGETK;
			}
			WORD new_word(word_pos, symbolTK, 0);
			word_list.push_back(new_word);
		}
		else if (c == '=')
		{
			POSITION word_pos(pos);
			c = this->mgetchar();
			symbolTK = EQUTK;
			WORD new_word(word_pos, symbolTK, 0);
			word_list.push_back(new_word);
		}
		else if (c == '.')
		{
			POSITION word_pos(pos);
			c = this->mgetchar();
			symbolTK = DOTTK;
			WORD new_word(word_pos, symbolTK, 0);
			word_list.push_back(new_word);
		}
		else
		{
			POSITION word_pos(pos);
			this->error(pos, c);
			c = this->mgetchar();
		}
	}
	pos.setPosition(-1, -1);
	WORD empty_word(pos, EMPTYTK, 0);
	word_list.push_back(empty_word);
}

void Symbol::error(const POSITION& pos, char& c, char stopc)
{
#ifndef SymbolDEBUG
	printf("ILLIGAL CHAR READED @ (%3d, %3d)\n", pos.mlineno + 1, pos.mcolno + 1);
#else
	char str[16];
	sprintf_s(str, "(%3d, %3d)", 16, pos.mlineno + 1, pos.mcolno + 1);
	symbolTK = ERRTK;
	WORD new_word(pos, symbolTK, str);
	word_list.push_back(new_word);
#endif
	while (c != '\n' && c != '\t' && c != ' ')
	{
		c = this->mgetchar();
		if (c == '\0')
			break;
	}
}

void WORD::print()
{
#ifdef SYMBOLCHECK
	printf("(%d, %d)\t", this->position.mlineno + 1, this->position.mcolno + 1);
	printf("%-12s\t", token_name[this->token]);
	if (this->token == ITK)
		printf("%d", this->value.num);
	else if (this->token == SQUOTETK || this->token == DQUOTETK)
		printf("%s", this->value.content);
	else if (this->token == ERRTK)
		printf("%s", this->value.content);
	printf("\n");
#endif
}
