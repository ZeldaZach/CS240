#ifndef TRIE_H
#define TRIE_H

<template class R, class S, class T>
class Node {
	R key; // Key note
	S value; // Stored value
	T children[]; // Vector, Array, List, etc
};

int main()
{
	Node<int, Person> n;
	n.key = (int)KEY;
	n.value = (Person)val;

	return 0;
}

#endif
