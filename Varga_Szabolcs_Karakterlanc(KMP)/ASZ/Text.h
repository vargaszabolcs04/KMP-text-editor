#ifndef _TEXT_H_
#define _TEXT_H_

#include<iostream>
#include <string>
#include <vector>

using namespace std;

class Text
{
private:
	string data;
	vector<pair<int, int>> talalt;

public:
	Text();
	Text(string);
	string GetString();
	bool KMP(string);
	void beszurelejere(string);
	void beszurvegere(string);
	void talaltTorol();
	void talaltFelulir(string);
	void talaltBeszur(string);
	void kiirminta();
	void kiir();
};

#endif

