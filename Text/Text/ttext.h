#pragma once
#include "ttextlink.h"
#include "tliststack.h"
#include <string>

class TText {
	TTextLink *pFirst;
	TTextLink *pCurr;
	TStack<TTextLink*> stack;
public:
	TText(); //constructor
	void GoFirstLink(); //go to beginning of text
	void GoDownLink(); //go to the lower link
	void GoNextLink(); //go to the next link
	void GoPrevLink(); //go to previous link
	void SetLine(std::string astr); //adding a line to text
	std::string GetLine(); //taking a line from text
	//Structural modification methods
	void InsNextLine(std::string astr); //adding the next line
	void InsNextSection(std::string astr); //adding the next sectoin
	void InsDownLine(std::string astr); //adding the lower line
	void InsDownSection(std::string astr); //adding the lower sectoin
	void DelNext(); //delete  the next link
	void DelDown(); // delete the lower link
};