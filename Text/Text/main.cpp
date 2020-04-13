//main.cpp

#include <conio.h>
#include <iostream>
#include <string>
#include "ttext.h"

#define ESC 0x1B
/*#define DOWN 0x28
#define RIGHT 0x27
#define LEFT 0x25
#define DELETE 0x2E*/

#define print 0
using namespace std;

TTextMem TTextLink::MemHeader;

void TextMenu(TText &txt) {
	string st;
	//char com;
	string com;

	do {
		cout << "enter 'help' to see a list of commands" << endl;
		//cout << "Now in " << txt.GetLine() << endl;
		cin >> com;
		//com = _getch();
		if (com == "exit") {
			//break;
		}
		if (com == "print") {
			txt.ConsolePrint();
			/*cout << endl << "printing iterator" << endl;
			for (txt.Reset(); !txt.IsEnd(); txt.GoNext()) {
				cout << txt.GetLine() << endl;
			}*/
			//break;
		}
		if (com == "printit") {
			//txt.ConsolePrint();
			cout << endl << "printing iterator" << endl;
			for (txt.Reset(); !txt.IsEnd(); txt.GoNext()) {
				cout << txt.GetLine() << endl;
			}
			//break;
		}
		if (com == "first") {
			txt.GoFirstLink();
			cout << "Now in " << txt.GetLine() << endl;
			//break;
		}
		if (com == "down") {
			txt.GoDownLink();
			cout << "Now in " << txt.GetLine() << endl;
			//break;
		}
		if (com == "next") {
			txt.GoNextLink();
			cout << "Now in " << txt.GetLine() << endl;
			//break;
		}
		if (com == "prev") {
			txt.GoPrevLink();
			cout << "Now in " << txt.GetLine() << endl;
			//break;
		}
		if (com == "deleted") {
			txt.DelDownLine();
			cout << "Now in " << txt.GetLine() << endl;
			//break;
		}
		if (com == "deleten") {
			txt.DelNext();
			cout << "Now in " << txt.GetLine() << endl;
			//break;
		}
		if (com == "insertdl") {
			cout << "enter string..." << endl;
			cin >> st;
			txt.InsDownLine(st);
		}
		if (com == "insertds") {
			cout << "enter string..." << endl;
			cin >> st;
			txt.InsDownSection(st);
		}
		if (com == "insertnl") {
			cout << "enter string..." << endl;
			cin >> st;
			txt.InsNextLine(st);
		}
		if (com == "insertns") {
			cout << "enter string..." << endl;
			cin >> st;
			txt.InsNextSection(st);
		}
		if (com == "free") {
			//TTextLink::MemCleaner(txt);
			TTextLink::PintFreeLink();
		}
		if (com == "help") {
			cout << "print - printing text with indentations" << endl;
			cout << "printit - printing text with iterator" << endl;
			cout << "first - go to beginning of text" << endl;
			cout << "next - go to the next link" << endl;
			cout << "down - go to the down link" << endl;
			cout << "prev - go to previous link" << endl;
			cout << "deleted - delete the down link" << endl;
			cout << "deleten - delete  the next link" << endl;
			cout << "insertdl - adding the down line" << endl;
			cout << "insertds - adding the down sectoin" << endl;
			cout << "insertnl - adding the next line" << endl;
			cout << "insertns - adding the next sectoin" << endl;
			cout << "free - show free memory" << endl;
			cout << "exit - exit" << endl;
			//break;
		}
		/*switch (comc) {
		case print:
			txt.ConsolePrint();
			break;
		case "first":
			txt.GoFirstLink();
			cout << "Now in " << txt.GetLine() << endl;
			break;
		case "down":
			txt.GoDownLink();
			cout << "Now in " << txt.GetLine() << endl;
			break;
		case 'n':
			txt.GoNextLink();
			cout << "Now in " << txt.GetLine() << endl;
			break;
		case 'q':
			txt.GoPrevLink();
			cout << "Now in " << txt.GetLine() << endl;
			break;
		case 'u':
			txt.DelDown();
			break;
		}*/
	} while (com != "exit");
}

int main() {
	TTextLink::InitMemSystem(100);
	TText t;
	t.Read("textin.txt");
	t.Write("textout.txt");
	/*t.ConsolePrint();
	cout << endl << "printing iterator" << endl;
	for (t.Reset(); !t.IsEnd(); t.GoNext()) {
		cout << t.GetLine() << endl;
	}
	t.ConsolePrint();*/
	TextMenu(t);

	TTextLink::MemCleaner(t);
	TTextLink::PintFreeLink();
}