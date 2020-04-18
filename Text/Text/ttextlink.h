//ttextlink.h

#ifndef _ttextlink_h_
#define _ttextlink_h_

#include <string>

#define TTextLineLength 80
#define MemSize 100

class TText;
class TTextLink;

typedef char TStr[TTextLineLength];

struct TTextMem {
	TTextLink* pFirst; //pointer to the first link
	TTextLink* pLast; //pointer to the last link
	TTextLink* pFree; //pointer to the free link
	friend class TTextLink;
};

//value object class for lines of text
class TTextLink {

protected:
	TTextLink *pNext, *pDown;
	static TTextMem MemHeader; //memory management system
	friend class TText;
public:

	TStr str;
	int recD;
	static void InitMemSystem(int size = MemSize); //memory initialization
	static void PintFreeLink(void); //printing of free links
	void* operator new (size_t size); //link allocation
	void operator delete (void* pM); //link release
	static void MemCleaner(TText& txt); //garbage collection

	//Constructor
	TTextLink(const TStr c = NULL, TTextLink *pn = NULL, TTextLink *pd = NULL) {
		recD = 0;
		pNext = pn;
		pDown = pd;
		if (c == NULL)
			str[0] = '\0';
		else
			strcpy_s(str, c);
	}

	//Destructor
	~TTextLink() {
		///
	}
};
#endif