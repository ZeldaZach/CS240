#include "BSTree.h"
#include <vector>
#include <queue>
#include <cstddef>
#include <iostream>
#include <iomanip>

using namespace std;

BSTree::BSTree() : root(nullptr)
{
}

BSTree::BSTree(const BSTree &old_tree) : root(nullptr)
{
	preOrder(old_tree.root);
}

BSTree::~BSTree()
{
	postOrder(this->root);
}

bool BSTree::empty()
{
	return (this->root == nullptr);
}

bool BSTree::insert(int val)
{
	if (root == nullptr)
	{
		this->root = new Node(val, nullptr);
		return true;
	}

	return insertRecursive(val, this->root);
}

bool BSTree::insertRecursive(int val, Node *r)
{
	if (r->getData() > val)
	{
		if (r->getLeft() == nullptr)
		{
			r->setLeft(new Node(val, r));
			return true;
		}

		return insertRecursive(val, r->getLeft());
	}
	else if (r->getData() < val)
	{
		if (r->getRight() == nullptr)
		{
			r->setRight(new Node(val, r));
			return true;
		}

		return insertRecursive(val, r->getRight());
	}
	else
	{
		return false;
	}
}

bool BSTree::find(int val)
{
	if (this->root == nullptr)
		return false;

	return findRecursive(val, this->root);
}

bool BSTree::findRecursive(int val, Node *r)
{
	if (r->getData() > val)
	{
		if (r->getLeft() == nullptr)
			return false;

		return findRecursive(val, r->getLeft());
	}
	else if (r->getData() < val)
	{
		if (r->getRight() == nullptr)
			return false;

		return findRecursive(val, r->getRight());
	}

	return true;
}

void BSTree::sortedArray(std::vector<int> &list)
{
	inOrder(list, this->root);
}

bool BSTree::remove(int val)
{
	if (this->root == nullptr)
		return false;
	
	Node *element = findNode(val, this->root);
	return removeElement(element);
}

bool BSTree::deleteLeaf(Node *element)
{
	if (element == nullptr)
		return false;

	if (element == this->root)
	{
		this->root = nullptr;
	}
	else
	{
		Node *p = element->getParent();
		(p->getLeft() == element) ? p->setLeft(nullptr) : p->setRight(nullptr);
	}

	delete element;
	return true;
}

bool BSTree::deleteSingleBranch(Node *element)
{
	if (element == nullptr)
		return false;
	
	Node *p = element->getParent();
	if (p == nullptr) // Root
	{
		return deleteDoubleBranch(element);
	}
	else if (p->getLeft() == element && element->getLeft() != nullptr)
	{
		p->setLeft(element->getLeft());
		element->getLeft()->setParent(p);
	}
	else if (p->getLeft() == element && element->getRight() != nullptr)
	{
		p->setLeft(element->getRight());
		element->getRight()->setParent(p);
	}
	else if (p->getRight() == element && element->getLeft() != nullptr)
	{
		p->setRight(element->getLeft());
		element->getLeft()->setParent(p);
	}
	else if (p->getRight() == element && element->getRight() != nullptr)
	{
		p->setRight(element->getRight());
		element->getRight()->setParent(p);
	}

	delete element;
	return true;
}

bool BSTree::deleteDoubleBranch(Node *element)
{
	if (element == nullptr)
		return false;

	Node *tmp = element->getRight();
	
	if (tmp == nullptr)
	{
		tmp = element->getLeft();
		while (tmp->getRight() != nullptr)
			tmp = tmp->getRight();
	}
	else
	{
		while (tmp->getLeft() != nullptr)
			tmp = tmp->getLeft();
	}

	element->setData(tmp->getData());

	return (tmp->isLeaf()) ? deleteLeaf(tmp) : deleteSingleBranch(tmp);
}

bool BSTree::removeElement(Node *element)
{
	if (element == nullptr)
		return false;
	
	if (element->getLeft() == nullptr && element->getRight() == nullptr)
		return deleteLeaf(element);
	else if (element->getLeft() != nullptr ^ element->getRight() != nullptr)
		return deleteSingleBranch(element);
	else
		return deleteDoubleBranch(element);
}

BSTree::Node* BSTree::findNode(int val, Node *r)
{
	if (r->getData() > val)
	{
		if (r->getLeft() == nullptr)
			return nullptr;

		return findNode(val, r->getLeft());
	}
	else if (r->getData() < val)
	{
		if (r->getRight() == nullptr)
			return nullptr;

		return findNode(val, r->getRight());
	}
	else
	{
		return r;
	}
}

void BSTree::preOrder(Node *r)
{
	if (r == nullptr)
		return;

	insert(r->getData());
	preOrder(r->getLeft());
	preOrder(r->getRight());
}

void BSTree::inOrder(std::vector<int> &list, Node *r)
{
	if (r == nullptr)
		return;

	inOrder(list, r->getLeft());
	list.push_back(r->getData());
	inOrder(list, r->getRight());
}

void BSTree::postOrder(Node *r)
{
	if (r == nullptr)
		return;

	postOrder(r->getLeft());
	postOrder(r->getRight());
	this->remove(r->getData());
}

int BSTree::height(Node *r)
{
	if (r == nullptr)
		return -1;
	
	int left = height(r->getLeft());
	int right = height(r->getRight());
	
	if (left > right)
		return left+1;
	else
		return right+1;
}

void BSTree::printBST()
{
	
}


BSTree::Node::Node(int data, Node *parent) : data(data), parent(parent), left(nullptr), right(nullptr)
{
}

bool BSTree::Node::isLeaf()
{
	return (getLeft() == nullptr && getRight() == nullptr);
}
