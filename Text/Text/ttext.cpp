#define _CRT_SECURE_NO_WARNINGS
#include "..//Text/ttext.h"
#include "..//Text/ttextlink.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

TText::TText()
{
	pFirst = NULL;
	TStack<TTextLink> stack;
}

void TText::GoFirstLink()
{
	pCurr = pFirst;
	stack.Clear();
}

void TText::GoDownLink() {
	if (!pCurr) throw - 1;
	if (!pCurr->pDown) return;
	stack.Push(pCurr);
	pCurr = pCurr->pDown;
}

void TText::GoNextLink() {
	if (!pCurr) throw - 1;
	if (!pCurr->pNext) return;
	stack.Push(pCurr);
	pCurr = pCurr->pNext;
}

void TText::GoPrevLink()
{
	if (!pCurr) throw - 1;
	if (stack.IsEmpty()) return;
	pCurr = stack.Pop();
}

void TText::SetLine(string astr)
{
	if (!pCurr) throw - 1;
	strcpy_s(pCurr->str, astr.c_str());
}

string TText::GetLine() {
	if (!pCurr) throw - 1;
	return std::string(pCurr->str);
}

void TText::InsNextLine(string astr) {
	if (!pCurr) throw - 1;
	TTextLink *p = new TTextLink(astr.c_str());
	p->pNext = pCurr->pNext;
	pCurr->pNext = p;
}

void TText::InsNextSection(string astr) {
	if (!pCurr) throw - 1;
	TTextLink *p = new TTextLink(astr.c_str());
	p->pDown = pCurr->pNext;
	pCurr->pNext = p;
}

void TText::InsDownLine(string astr) {
	if (!pCurr) throw - 1;
	TTextLink *p = new TTextLink(astr.c_str());
	p->pDown = pCurr->pNext;
	pCurr->pDown = p;
}

void TText::InsDownSection(string astr) {
	if (!pCurr) throw - 1;
	TTextLink *p = new TTextLink(astr.c_str());
	p->pDown = pCurr->pDown;
	pCurr->pDown = p;
}

void TText::DelNext() {
	if (!pCurr) throw - 1;
	if (!pCurr->pNext) return;
	TTextLink* tmp = pCurr->pNext;
	pCurr->pNext = tmp->pNext;
	delete tmp;
}

void TText::DelDown() {
	if (!pCurr) throw - 1;
	if (!pCurr->pNext) return;
	TTextLink* tmp = pCurr->pDown;
	pCurr->pDown = tmp->pDown;
	delete tmp;
}

void TText::Read(std::string fn)
{
	ifstream ifs(fn);
	pFirst = ReadRec(ifs);
}

TTextLink* TText::ReadRec(ifstream& ifs)
{
	TTextLink *pHead, *pRC, *tmp;
	pHead = pRC = NULL;
	char tstr[81];
	while (!ifs.eof())
	{
		ifs.getline(tstr, 80, '\n');
		if (tstr[0] == '}')
			break;
		else
			if (tstr[0] == '{')
				pRC->pDown = ReadRec(ifs);
			else
			{
				tmp = new TTextLink(tstr);
				if (pHead == NULL)
					pHead = pRC = tmp;
				else
				{
					pRC->pNext = tmp;
					pRC = pRC->pNext;
				}
			}
	}
	return pHead;
}

void TText::Write(std::string fn)
{
	ofstream ofs(fn);
	WriteRec(ofs, pFirst);
}

void TText::WriteRec(ofstream& ofs, TTextLink* pWC)
{
	ofs << pWC->str << endl;
	if (pWC->pDown)
	{
		ofs << '{' << endl;
		WriteRec(ofs, pWC->pDown);
		ofs << '}' << endl;
	}
	if (!pWC->pDown)
		WriteRec(ofs, pWC->pNext);

}