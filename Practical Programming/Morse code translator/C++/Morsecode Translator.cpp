// Morsecode Translator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
using namespace std;

// Defining some constants
int unit = 100;
int frequency = 1000;

char alphabet[26]		= {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
vector <vector <int> > alphabetValue = { 
{1,0,3,0,0,0},
{3,0,1,0,1,0,1,0,0,0},
{3,0,1,0,3,0,1,0,0,0},
{3,0,1,0,1,0,0,0},
{1,0,0,0},
{1,0,1,0,3,0,1,0,0,0},
{3,0,3,0,1,0,0,0},
{1,0,1,0,1,0,1,0,0,0},
{1,0,1,0,0,0},
{1,0,3,0,3,0,3,0,0,0},
{3,0,1,0,3,0,0,0},
{1,0,3,0,1,0,1,0,0,0},
{3,0,3,0,0,0},
{3,0,1,0,0,0},
{3,0,3,0,3,0,0,0},
{1,0,3,0,3,0,1,0,0,0},
{3,0,3,0,1,0,3,0,0,0},
{1,0,3,0,1,0,0,0},
{1,0,1,0,1,0,0,0},
{3,0,0,0},
{1,0,1,0,3,0,0,0},
{1,0,1,0,1,0,3,0,0,0},
{1,0,3,0,3,0,0,0},
{3,0,1,0,1,0,3,0,0,0},
{3,0,1,0,3,0,3,0,0,0},
{3,0,3,0,1,0,1,0,0,0} };

int searchAlphabet(char character) {
	for (int alphaIndex = 0; alphaIndex < sizeof(alphabet) / sizeof(char); alphaIndex++) {
		if (alphabet[alphaIndex] == character) {
			return alphaIndex;
		}
	}
}

int main()
{
	while (true) {
		cout << "Heyo, type in something to translate to morse code!\n";
		string input;
		cin >> input;
		for (char & c : input)
		{
			int alphaIndex = searchAlphabet(c);

			for (int i = 0; i < alphabetValue[alphaIndex].size(); i++) {
				if (alphabetValue[alphaIndex][i] == 0) {
					Sleep(unit * 3);
				}
				else {
					//Beep(1000, (unit * alphabetValue[alphaIndex][i]));
					toot(frequency, (unit * alphabetValue[alphaIndex][i]));
				}
			}
		}
	}
	return 0;
}