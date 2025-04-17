#include "Text.h"
#include<stdio.h>



Text::Text()
{
	this->data = nullptr;
}

Text::Text(string input)
{
	this->data=input;
}

//a szoveg tartalma
string Text::GetString()
{
	return this->data;
}

//KMP algoritmus
bool Text::KMP(string keresett)
{
	talalt.clear();
	//Prefix-szufix tabla keszitese a keresett mintanak
	vector<int> tabla(keresett.size(), 0);
	for (int i = 1; i < keresett.size(); i++)
	{
		if (keresett[tabla[i - 1]] == keresett[i])
		{
			tabla[i] = tabla[i - 1] + 1;
		}
		else tabla[i] = 0;
	}
	int i = 0,j=0;
	while (this->data.size() - i >= keresett.size() - j)
	{
		if (this->data[i] == keresett[j])
		{
			i++;
			j++;
		}

		if (j == keresett.size())
		{
			talalt.push_back(make_pair(i-keresett.size(), i-1));
			j = tabla[j - 1];
		}
		else if (i < this->data.size() && this->data[i] != keresett[j])
		{
			if (j != 0)
				j = tabla[j - 1];
			else
				i = i + 1;
		}
	}
	if (talalt.size() == 0)
	{
		return false;
	}
	return true;
}

//beszuras a szoveg elejere
void Text::beszurelejere(string uj)
{
	string szoveg = uj;
	szoveg.append(this->data);
	this->data = szoveg;
}

//beszuras a szoveg vegere
void Text::beszurvegere(string uj)
{
	string szoveg = this->data;
	szoveg.append(uj);
	this->data = szoveg;
}

//a keresett szavakat torli
void Text::talaltTorol()
{
	int szohossz = talalt[0].second - talalt[0].first+1;
	for (int i = 0; i < talalt.size(); i++)
	{
		this->data.erase(talalt[i].first-i*szohossz,szohossz);
	}
}

//a keresett szavakat felulirja
void Text::talaltFelulir(string replace)
{
	int szohossz = talalt[0].second - talalt[0].first + 1;
	for (int i = talalt.size()-1; i >= 0; i--)
	{
		this->data.replace(talalt[i].first,szohossz,replace);
	}
}

//a keresett szavak utan beszuras
void Text::talaltBeszur(string beszur)
{
	int szohossz = talalt[0].second - talalt[0].first+1;
	for (int i = talalt.size() - 1; i >= 0; i--)
	{
		int insert_pos = talalt[i].first + szohossz;
		this->data.insert(insert_pos, beszur);
	}
}

//kiiras a keresett szavak kijelolesevel
void Text::kiirminta()
{
	if (talalt.size() != 0)
	{
		const std::string GREEN = "\033[32m";
		const std::string RESET = "\033[0m";
		int k = 0;
		for (int i = 0; i < talalt.size(); i++)
		{
			cout << this->data.substr(k, talalt[i].first - k);
			k = talalt[i].first;
			cout << GREEN << this->data.substr(k, talalt[i].second - talalt[i].first + 1) << RESET;
			k += (talalt[i].second - talalt[i].first + 1);
		}
		cout << this->data.substr(k) << endl;
	}
	else cout << this->data << endl;
}

//jeloles nelkuli kiiras
void Text::kiir()
{
	cout << this->data << endl;
}
