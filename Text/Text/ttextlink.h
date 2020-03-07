#pragma once
#include <string>

class TTextLink {
public:
	TTextLink *pNext, *pDown;
	char str[81];
	//Конструктор
	TTextLink(const char *c = NULL, TTextLink *pn = NULL, TTextLink *pd = NULL) {
		pNext = pn;
		pDown = pd;
		if (c == NULL)
			str[0] = '\0';
		else
			strcpy(str, c);
	}
};