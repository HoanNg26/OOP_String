#include "stdafx.h"
#include "MyString.h"
#include <string.h>
#include <stdio.h>
#include <ctype.h>

MyString::MyString()
{
	s = NULL;
	n = 0;
}
MyString::MyString(int size)
{
	if (n < 1) {
		s = NULL;
		n = 0;
		return;
	}
	n = size;
	s = new char[n];
	memset(s, '\0', n);
}
MyString::MyString(int size, char c)
{
	if (n < 1) {
		s = NULL;
		n = 0;
		return;
	}
	n = size;
	s = new char[n];
	memset(s, c, n);
}
MyString::MyString(const char *ss)
{
	n = strlen(ss);
	if (n < 1){
		s = NULL;
		n = 0;
		return;
	}
	s = new char[n];
	memcpy(s, ss, n);
}
MyString::MyString(const char ss[], int nn)
{
	n = nn;
	if (n < 1) {
		s = NULL;
		n = 0;
		return;
	}
	s = new char[n];
	memcpy(s, ss, n);
}
MyString::MyString(const MyString *str)
{
	n = str->n;
	if (n < 1) {
		s = NULL;
		n = 0;
		return;
	}
	s = new char[n];
	memcpy(s, str->s, n);
}
MyString::~MyString()
{
	if (s != NULL)
		delete s;
	n = 0;
}

int MyString::isEmpty()
{
	if (n == 0)
		return 1;
	return 0;
}

int MyString::getLength()
{
	return n;
}

int MyString::indexOf(char c)
{
	if (n < 1)
		return -1; // not found
	for (int i = 0; i < n; i++)
		if (s[i] == c)
			return i; // found, return the first index
	return -1; // not found
}

int MyString::indexOf(char * ar)
{
	if (ar == NULL)
		return  -1; // not found
	int nn = strlen(ar);
	if (nn < 1)
		return -1; // not found
	if (nn > n)
		return -1; //not found
	//find first index
	int firstIndex = indexOf(ar[0]);
	if (firstIndex < 0)
		return -1;//not found
	do {
		if (n - firstIndex < nn)
			return -1; //not found
		int cmp = memcmp(&(this->s[firstIndex]), ar, nn);
		if (cmp == 0)
			return firstIndex; //FOUND
		firstIndex++;
	} while (true);

	return -1; //not found
}

int MyString::indexOf(char ar[], int nn)
{
	if (ar == NULL)
		return  -1; // not found
	if (nn < 1)
		return -1; // not found
	if (nn > n)
		return -1; //not found
				   //find first index
	int firstIndex = indexOf(ar[0]);
	if (firstIndex < 0)
		return -1;//not found
	do {
		if (n - firstIndex < nn)
			return -1; //not found
		int cmp = memcmp(&(this->s[firstIndex]), ar, nn);
		if (cmp == 0)
			return firstIndex; //FOUND
		firstIndex++;
	} while (true);

	return -1; //not found
}

int MyString::indexOf(MyString * str)
{
	return indexOf(str->s,str->n);
}

char MyString::charOf(int index)
{
	if (index >= n)
		return '\0';
	return s[index];
}

MyString * MyString::createCopy()
{
	MyString *str = new MyString(this);
	return str;
}

MyString * MyString::toUpper()
{
	MyString *str = createCopy();
	for (int i = 0; i < str->n; i++)
		str->s[i] = toupper(str->s[i]);
	return str;
}

MyString * MyString::toLower()
{
	MyString *str = createCopy();
	for (int i = 0; i < str->n; i++)
		str->s[i] = tolower(str->s[i]);
	return str;
}

MyString * MyString::reverse()
{
	MyString *str = createCopy();
	char tmp;
	for (int i = 0; i < str->n / 2; i++){
		tmp = str->s[i];
		str->s[i] = str->s[n - i - 1];
		str->s[n - i - 1] = tmp;
	}
	return str;
}

MyString * MyString::concat(const MyString * str)
{
	if (str->n < 1)
		return createCopy();
	if (this->n < 1)
		return new MyString(str);
	char *dest = new char[this->n + str->n];
	memcpy(dest, this->s, this->n);
	memcpy(&(dest[n]), str->s, str->n);
	return new MyString(dest, this->n + str->n);
}

MyString * MyString::padLeft(char c, int repeated)
{
	if (repeated < 1)
		return createCopy();
	if (this->n < 1)
		return new MyString(repeated, c);
	char *dest = new char[this->n + repeated];
	memset(dest, c, repeated);
	memcpy(&(dest[repeated]), this->s, this->n);
	return new MyString(dest, this->n + repeated);
}

MyString * MyString::padRight(char c, int repeated)
{
	if (repeated < 1)
		return createCopy();
	if (this->n < 1)
		return new MyString(repeated, c);
	char *dest = new char[this->n + repeated];
	
	memcpy(dest, this->s, this->n);
	memset(&(dest[this->n]), c, repeated);
	return new MyString(dest, this->n + repeated);
}

char * MyString::toChars()
{
	if (n < 1)
		return NULL;
	char *dest = new char[n + 1];
	memcpy(dest, s, n);
	dest[n] = '\0';
	return dest;
}

void MyString::write()
{
	if (n < 1)
		return;
	char *dest = new char[n+1];
	memcpy(dest, s, n);
	dest[n] = '\0';
	printf("%s", dest);
	delete dest;
	dest = NULL;
}

void MyString::writeline()
{
	if (n < 1) {
		return;
		printf("\n");
	}
	char *dest = new char[n + 1];
	memcpy(dest, s, n);
	dest[n] = '\0';
	printf("%s\n", dest);
	delete dest;
	dest = NULL;
}
