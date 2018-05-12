// String.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "MyString.h"
#include <conio.h>
#include <stdio.h>


int main()
{
	MyString *str = new MyString("Nguyen va An");
	str->writeline();
	MyString *str1 = new MyString("Nguyen va An");
	str1->writeline();
	MyString *str2 = str->createCopy();
	str2->writeline();
	MyString *str3 = str->reverse();
	str3->writeline();
	MyString *str4 = str3->padLeft('x', 5);
	str4->writeline();
	MyString *str5 = str4->padRight('y', 9);
	str5->writeline();
	MyString *str6 = str4->concat(str5);
	str6->writeline();
	char *s = "an";
	int index = str->indexOf(str2);
	printf("IndexOf: %d", index);

	delete str;
	delete str1;

	getchar();
    return 0;
}

