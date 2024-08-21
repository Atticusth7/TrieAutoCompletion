#ifndef _TRIE_H_
#define _TRIE_H_

#include "TrieNode.h"
#include <algorithm>
#include <string>
#include <cstring>
class Trie {
public:
	TrieNode* root = new TrieNode();

	Trie();
	// Returns true if the trie is empty, false otherwise
	bool isEmpty();


	// Inserts the word into the trie, and returns the status
	// (e.g. fail the operation if the word has any non-alphabetical
	// letter)

	bool insert(std::string word);


	// Removes the word from the trie, and returns the status

	bool remove(std::string word);



	// Returns true if the word is present in the trie, false otherwise

	bool search(std::string word);

	// Displays all the words currently in the trie
	void displayWordList();

	void displayWordList(std::string word);
	// Recursive helper for display
	void print(struct TrieNode* root, char str[], int re);


private:
	//
};
#endif // _TRIE_H_#pragma once
