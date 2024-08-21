#include "TrieNode.h"
#include <algorithm>
#include <string>
#include <cstring>
#include <iostream>
#include "Trie.h"
using namespace std;
TrieNode* root = new TrieNode();

Trie::Trie()
{
	TrieNode* root = new TrieNode();
}

// Returns true if the trie is empty, false otherwise
bool Trie::isEmpty()
{
	return (!root->hasChildren());
}

// Inserts the word into the trie, and returns the status
// (e.g. fail the operation if the word has any non-alphabetical
// letter)

bool Trie::insert(string word)
{
	TrieNode* current = root;
	string str = word;
	for (size_t i = 0; i < str.size(); i++)
	{
		if (!isalpha(str.at(i)))
		{
			return false;
		}
		str.at(i) = toupper(str.at(i));
	}
	for (size_t i = 0; i < word.size(); i++)
	{
		if (current->next[(int)str[i] - 65] == nullptr)
		{
			current->next[(int)str[i] - 65] = new TrieNode();
		}
		current = current->next[(int)str[i] - 65];
	}
	current->setAsLeaf();
	return true;
}

// Removes the word from the trie, and returns the status

bool Trie::remove(string word)
{
	TrieNode* current = root;
	string str = word;
	if (!this->search(str))
	{
		return false;
	}
	if (this->isEmpty())
	{
		return false;
	}
	for (size_t i = 0; i < str.size(); i++)
	{
		if (!isalpha(str.at(i)))
		{
			return false;
		}
		str.at(i) = toupper(str.at(i));
	}
	for (size_t i = 0; i < word.size(); i++)
	{
		current = current->next[(int)str[i] - 65];
	}
	current->setAsInteriorNode();
	return true;
}


// Returns true if the word is present in the trie, false otherwise

bool Trie::search(string word)
{
	TrieNode* current = root;
	string str = word;
	if (this->isEmpty())
	{
		return false;
	}
	for (size_t i = 0; i < str.size(); i++)
	{
		if (!isalpha(str.at(i)))
		{
			return false;
		}
		str.at(i) = toupper(str.at(i));
	}
	for (size_t i = 0; i < str.size(); i++) {
		if (!current->next[str[i] - 'A'])
			return false;
		current = current->next[str[i] - 'A'];
	}
	return (current != nullptr && current->isLeaf());
}

// Displays all the words currently in the trie
void Trie::displayWordList()
{
	char str[25];
	print(root, str, 0);
	cout << endl;
}
void Trie::displayWordList(string word)
{
	bool valid = true;
	TrieNode* current = root;
	char str[25];
	for (int i = 0; i < word.length(); i++)
	{
		if (isalpha(word[i]))
		{
		str[i] = toupper(word.at(i));
		current = current->next[toupper(word[i]) - 'A'];
		}
		else
		{
			valid = false;
			cout << "Input must be alpha" << endl;
			break;
		}
	}
	if (valid)
	{
		print(current, str, word.size());
		cout << endl;
	}
}

// Recursive helper for display
void Trie::print(struct TrieNode* root, char str[], int re)
{
	if (root->isLeaf())
	{
		str[re] = '\0';
		cout << str << " ";
	}
	for (int i = 0; i < 27; i++)
	{
		if (root->next[i])
		{
			str[re] = i + 'A';
			print(root->next[i], str, re + 1);
		}
	}
}
