#ifndef BSTREE_H
#define BSTREE_H

#include <vector>
#include <queue>
#include <iomanip>

class BSTree
{
	private:
		class Node
		{
			private:
				int data;
				Node *left;
				Node *right;
				Node *parent;

			public:
				Node(int data, Node *parent);
				Node* getLeft() { return left; }
				Node* getRight() { return right; }
				Node* getParent() { return parent; }
				int getData() { return data; }
				void setLeft(Node* ptr) { left = ptr; }
				void setRight(Node* ptr) { right = ptr; }
				void setParent(Node* ptr) { parent = ptr; }
				void setData(int val) { data = val; }
				bool isLeaf();
		};

		Node *root;

		bool insertRecursive(int val, Node *r);
		bool findRecursive(int val, Node *r);
		bool removeRecursive(int val, Node *r);
		bool removeElement(Node *element);
		bool deleteLeaf(Node *element);
		bool deleteSingleBranch(Node *element);
		bool deleteDoubleBranch(Node *element);
		Node* findNode(int val, Node *r);
		void inOrder(std::vector<int> &list, Node *r);
		void postOrder(Node *r);
		void preOrder(Node *old_root);
		void getNodesAtLevel(Node *r, int level, std::vector<int> &q);
		int height(Node *r);

	public:
		BSTree();
		BSTree(const BSTree &old_tree);
		~BSTree();
		bool empty();
		bool insert(int val);
		bool find(int val);
		void sortedArray(std::vector<int> &list);
		bool remove(int val);
		void printBST();
};

#endif
