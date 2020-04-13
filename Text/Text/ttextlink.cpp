//ttextlink.cpp

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include "ttextlink.h"
#include "ttext.h"


void TTextLink::InitMemSystem(int size) {
	MemHeader.pFirst = (TTextLink*) new char[sizeof(TTextLink)*size];
	MemHeader.pFree = MemHeader.pFirst;
	MemHeader.pLast = MemHeader.pFirst + (size - 1);
	TTextLink* pLink = MemHeader.pFirst;

	//memory markup
	for (int i = 0; i < size - 1; i++) {
		pLink->str[0] = '\0';
		pLink->pNext = pLink + 1;
		pLink++;
	}
	pLink->pNext = NULL;
}

void TTextLink::PintFreeLink(void) {
	std::cout << "List of free links" << std::endl;
	int count = 0;
	for (TTextLink* pLink = MemHeader.pFree; pLink != NULL; pLink = pLink->pNext) {
		std::cout << pLink->str << std::endl;
			count++;
	}
	std::cout << count << std::endl;
}

void * TTextLink::operator new(size_t size) {
	TTextLink* pLink = MemHeader.pFree;
	if (MemHeader.pFree) {
		MemHeader.pFree = pLink->pNext;
	}
	return pLink;
}

void TTextLink::operator delete(void * pM) {
	TTextLink* pLink = (TTextLink*)pM;
	pLink->pNext = MemHeader.pFree;
	MemHeader.pFree = pLink;
}

void TTextLink::MemCleaner(TText& txt) {

	for (txt.Reset(); !txt.IsEnd(); txt.GoNext()) {
		std::string tmp = "&&&";
		tmp += txt.GetLine();
		txt.SetLine(tmp);
	}

	//free links list markup
	TTextLink* pLink;
	for (pLink = MemHeader.pFree; pLink != NULL; pLink = pLink->pNext) {
		strcpy(pLink->str, "&&&");
	}

	//garbage collection
	for (pLink = MemHeader.pFirst; pLink <= MemHeader.pLast; pLink++) {
		//text line or free link
		if (std::strstr(pLink->str, "&&&") != NULL) {
			std::strcpy(pLink->str, pLink->str + 3); //unmarking
		}
		else {
			delete pLink; // unaccaunted link to the list of free
		}
	}
}
