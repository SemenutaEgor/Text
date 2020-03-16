#include <string>
#include "ttext.h"

int main() {
	TText t;
	//std::string textin = "textin.txt";
	t.Read("textin.txt");
	t.Write("textout.txt");
}