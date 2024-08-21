#include "TrieNode.h"
const static int CHAR_SIZE = 27;
TrieNode:: TrieNode()
{
	for (int i = 0; i < CHAR_SIZE; i++)
	{
		next[i] = nullptr;
	}
}
// Returns true if the TrieNode has any children
// (i.e. any of the A-Z pointers are not null)
bool TrieNode :: hasChildren()
{
	TrieNode* current = this;
	for (int i = 0; i < CHAR_SIZE - 1; i++)
	{
		if (next[i]
			)
			return true;
	}
	return false;
}
// Set the '$' pointer to a valid non-null address
void TrieNode :: setAsLeaf()
{
	next[CHAR_SIZE - 1] = new TrieNode();
}
// Set the '$' pointer to null
void TrieNode :: setAsInteriorNode()
{
	next[CHAR_SIZE - 1] = nullptr;
}
// Returns true if the '$' pointer is not-null
bool TrieNode :: isLeaf()
{
	return(next[CHAR_SIZE - 1] != nullptr);
}
//
TrieNode* next[CHAR_SIZE];