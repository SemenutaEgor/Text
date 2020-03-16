#include <string>
#include "ttext.h"

int main() {
	TText t;
	t.Read("textin.txt");
	t.Write("textout.txt");
}