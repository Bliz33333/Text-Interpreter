//============================================================================
// Name        : Text-Interpreter.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
using namespace std;

string trim(string s)
{
	string trimmed = s;

	while (trimmed.substr(0, 1) == " ")
	{
		trimmed = trimmed.substr(1, trimmed.size() - 1);
	}

	while (trimmed.substr(trimmed.size() - 1, 1) == " ")
	{
		trimmed = trimmed.substr(0, trimmed.size() - 1);
	}

	return trimmed;
}

int main()
{
	ifstream infile;
	string line;
	string allLines;
	int count = 1;
	string storage;

	infile.open("heroides1.txt", ios::out);

	if (infile.is_open())
	{
		while (getline(infile, line))
		{
//			cout << line << '\n';
			switch (count)
			{
				case 1:
					count++;
					line = trim(line);
					allLines += (line + "\n");
					break;
				case 2:
					count++;
					line = trim(line);
					storage = line;
					break;
				case 3:
					count++;
					line = trim(line);
					allLines += (line + "\n");
					break;
				case 4:
					count = 1;
					line = trim(line);
					allLines += (storage + "\n");
					allLines += ("\t" + line + "\n" + "\n");
					break;
			}
		}
		infile.close();
	}
	cout << allLines;

	ofstream outfile("Heroides1Formatted.txt");
	outfile << allLines;
	outfile.close();

	return 0;
}
