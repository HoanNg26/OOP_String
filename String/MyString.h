#pragma once

class MyString
{
private:
	char *s;
	int n;
public:
	MyString();
	MyString(int size);
	MyString(int size, char c);
	MyString(const char *s);
	MyString::MyString(const char ss[], int nn);
	MyString(const MyString *str);
	~MyString();

public:
	int isEmpty();
	int getLength();
	int indexOf(char c);
	int indexOf(char *ar);
	int indexOf(char ar[],int nn);
	int indexOf(MyString *str);

	char charOf(int index);

	MyString * createCopy();
	MyString * toUpper();
	MyString * toLower();
	MyString * reverse();
	MyString * concat(const MyString *str);
	MyString * padLeft(char c, int repeated);
	MyString * padRight(char c, int repeated);
	char  * toChars();

	// for testing
	void write();
	void writeline(
);
};

