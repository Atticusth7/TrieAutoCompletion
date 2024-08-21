#include<iostream>
#include <fstream>
using namespace std;
#include "Trie.h"

int main()
{
	Trie *trie = new Trie;
	string words;
	string input;
	fstream inFile;
	inFile.open("Words.txt");
	while (inFile >> words)
	{
		trie->insert(words);
	}
	while (true)
	{
		cin >> input;
		if (trie->search(input))
		{
			cout << input << " was found" << endl;
			trie->displayWordList(input);
		}
		else
		{
			cout << input << " was not found did you mean ";
			trie->displayWordList(input);
			cout << endl;
		}
	}
	return 0;
}