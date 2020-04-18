//ttext.h

#ifndef _ttext_h_
#define _ttext_h_

#include "ttextlink.h"
#include "tstack.h"
#include <string>

class TText 
{
	TTextLink *pFirst;
	TTextLink *pCurr;
	TStack<TTextLink*> stack;

public:

	TText(); //constructor
	void GoFirstLink(); //go to beginning of text
	void GoDownLink(); //go to the down link
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
	void DelDownLine(); // delete the down link

	//Reaind and writing methods

	void Read(std::string fn); //read file
	TTextLink* ReadRec(std::ifstream& ifs); //readig lines from a file
	void Write(std::string fn); //write to file
	void WriteRec(std::ofstream& ofs, TTextLink* pWC); // recursive writing function
	void ConsolePrint(); //write to console
	void ConsolePrintRec(TTextLink* pWC); // recursive printing function to console

	//Text navigetion methods

	int Reset(); //set to first link
	int IsEnd(); //end check
	int GoNext(); // skip to the next link
};
#endif;