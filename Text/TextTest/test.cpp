#include "pch.h"
#include "../Text/ttext.h"
#include "../Text/ttextlink.h"
#include <string>

using namespace std;

TEST(TextTest, can_create_text)
{
	ASSERT_NO_THROW(TText t);
}

TEST(TextTest, can_add_string_into_current_position)
{
	TText t;
	string istr = "test string";
	//t.SetLine(istr);
	//t.InsNextLine(istr);
	ASSERT_NO_THROW(t.InsNextLine(istr));
}