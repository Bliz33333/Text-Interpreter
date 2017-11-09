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

	while (trimmed.substr(0, 1) == " " || trimmed.substr(0, 1) == "1"
			|| trimmed.substr(0, 1) == "2" || trimmed.substr(0, 1) == "3"
			|| trimmed.substr(0, 1) == "4" || trimmed.substr(0, 1) == "5"
			|| trimmed.substr(0, 1) == "6" || trimmed.substr(0, 1) == "7"
			|| trimmed.substr(0, 1) == "8" || trimmed.substr(0, 1) == "9"
			|| trimmed.substr(0, 1) == "0")
	{
		trimmed = trimmed.substr(1, trimmed.size() - 1);
	}

	while (trimmed.substr(trimmed.size() - 1, 1) == " "
			|| trimmed.substr(trimmed.size() - 1, 1) == "1"
			|| trimmed.substr(trimmed.size() - 1, 1) == "2"
			|| trimmed.substr(trimmed.size() - 1, 1) == "3"
			|| trimmed.substr(trimmed.size() - 1, 1) == "4"
			|| trimmed.substr(trimmed.size() - 1, 1) == "5"
			|| trimmed.substr(trimmed.size() - 1, 1) == "6"
			|| trimmed.substr(trimmed.size() - 1, 1) == "7"
			|| trimmed.substr(trimmed.size() - 1, 1) == "8"
			|| trimmed.substr(trimmed.size() - 1, 1) == "9"
			|| trimmed.substr(trimmed.size() - 1, 1) == "0")
	{
		trimmed = trimmed.substr(0, trimmed.size() - 1);
	}

	return trimmed;
}

void couplet(string author, string title, string raw)
{
	ifstream infile;
	string line;
	string allLines;
	int count = 1;
	string storage;

	infile.open(title + ".txt", ios::out);

	if (infile.is_open())
	{
		while (getline(infile, line))
		{
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

	ofstream outfile(title + "Formatted.txt");
	outfile << title + "\n";
	outfile << author + "\n";
	outfile << "Eligiac Couplet" + "\n";
	outfile << allLines;
	outfile.close();
}

int main()
{
	return 0;
}
