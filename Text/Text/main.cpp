//main.cpp

#include <iostream>
#include <string>
#include "ttext.h"

using namespace std;

int main() {
	TText t;
	t.Read("textin.txt");
	t.Write("textout.txt");
	cout << endl << "printing iterator" << endl;
	for (t.Reset(); !t.IsEnd(); t.GoNext()) {
		cout << t.GetLine() << endl;
	}
}