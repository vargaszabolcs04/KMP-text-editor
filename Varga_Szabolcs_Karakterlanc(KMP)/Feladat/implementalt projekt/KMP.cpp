#include <iostream>
#include "Text.h"
#include <string>

using namespace std;

//a console tartalmanak frissitese es a keresett szo kijelolese
void kiirconsolejelolve(string consolebefore, string consolekerdes, Text pelda)
{
	system("cls");
	cout << consolebefore;
	pelda.kiirminta();
	cout << consolekerdes;
}

//a console tartalmanak frissitese
void kiirconsole(string consolebefore, string consolekerdes, Text pelda)
{
	system("cls");
	cout << consolebefore;
	pelda.kiir();
	cout << consolekerdes;
}

//KMP algoritmus, mintat keres a szovegben
bool kereses(Text& pelda,string& pattern)
{
	getline(cin, pattern);
	return pelda.KMP(pattern);
}

int main()
{
	string consolebefore;
	string consolekerdes;
	string consoleafter;
	string szoveg;
	cout << "Irjon be egy szoveget:" << endl;
	getline(cin, szoveg);
	consolebefore.append("Irjon be egy szoveget:\n");
	Text pelda(szoveg);
	string pattern;
	char v=NULL;
	consolekerdes.append("\nKeresni(k), beszurni(b), torolni(t), vagy felulirni(f) szeretne ? (s->stop) ");
	bool jelolve = false;
	while (v != 's')
	{
		if (jelolve)
		{
			kiirconsolejelolve(consolebefore, consolekerdes, pelda);
		}
		else kiirconsole(consolebefore, consolekerdes, pelda);
		cin >> v;
		cin.get();
		if (v == 'k')
		{
			jelolve = true;
			cout << "Adja meg a keresett mintat:" << endl;
			while (kereses(pelda, pattern) == false)
			{
				cout << "Nem talalhato a szo. Probald ujra. " << endl;
			}

		}
		if (v == 'b')
		{
			char b=NULL;
			cout << "Szoveg elejere(e), vegere(v), vagy keresett szo utan(k) szeretne beszurni?" << endl;
			cin >> b;
			cin.get();
			if (b == 'k')
			{
				if (jelolve)
				{
					cout << "Mit szeretne beszurni?" << endl;
					string beszur;
					getline(cin, beszur);
					pelda.talaltBeszur(beszur);
					jelolve = false;
				}
				else
				{
					cout << "Melyik szo utan szeretne beszurni? " << endl;
					while (kereses(pelda, pattern) == false)
					{
						cout << "Nem talalhato a szo. Probald ujra. " << endl;
					}
					cout << "Mit szeretne beszurni?" << endl;
					string beszur;
					getline(cin, beszur);
					pelda.talaltBeszur(beszur);
					jelolve = false;
				}
			}
			if (b == 'e')
			{
				string uj;
				cout << "A beszurando szoveg:";
				getline(cin, uj);
				pelda.beszurelejere(uj);
			}
			if (b == 'v')
			{
				string uj;
				cout << "A beszurando szoveg:";
				getline(cin, uj);
				pelda.beszurvegere(uj);
			}
		}
		if (v == 't')
		{
			char t=NULL;
			cout << "Teljes szoveget(t), vagy keresett szot(k) szeretne torolni? "; 
			cin >> t;
			cin.get();
			if (t == 'k')
			{
				if (jelolve)
				{
					pelda.talaltTorol();
					jelolve = false;
				}
				else
				{
					cout << "Mit szeretne torolni? " << endl;
					while (kereses(pelda, pattern) == false)
					{
						cout << "Nem talalhato a szo. Probald ujra. " << endl;
					}
					pelda.talaltTorol();
					jelolve = false;
				}
			}
			else
			{
				system("cls");
				cout << "Irjon be egy szoveget:" << endl;
				getline(cin, szoveg);
				pelda = szoveg;
			}
		}
		if (v == 'f')
		{
			if (jelolve)
			{
				cout << "Mivel szeretne felulirni?" << endl;
				string replace;
				getline(cin, replace);
				pelda.talaltFelulir(replace);
				jelolve = false;
			}
			else
			{
				cout << "Mit szeretne felulirni?" << endl;
				while (kereses(pelda, pattern) == false)
				{
					cout << "Nem talalhato a szo. Probald ujra. " << endl;
				}
				cout << "Mivel szeretne felulirni?" << endl;
				string replace;
				getline(cin, replace);
				pelda.talaltFelulir(replace);
				jelolve = false;
			}
		}
	}

}
