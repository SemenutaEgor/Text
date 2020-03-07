#pragma once
#include "ttextlink.h"
#include "tliststack.h"

class TText {
	TTextLink *pFirst, *pCurr;
	TStack<TTextLink> stack;
};