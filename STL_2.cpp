#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;
#include "Dictionary.h"

int main()
{
	Dictionary dict;

	/*dict.Read("data.txt");
	dict.Print();*/

	dict.Add("Hello", "privet");
	dict.Add("Goodbye", "poka");
	dict.Add("Honorificabilitudinitatibus", "dostoinyi chesti");

	dict.Print();

	dict.Edit("Hello", "Adios", "arividerchi");

	cout << endl;
	dict.Search("Honorificabilitudinitatibus");
	cout << endl;

	dict.Print();

	dict.Save("data.txt");
}

