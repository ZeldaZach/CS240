void insert(data)
{
	if (this->root == NULL)
		root = new Node(data, NULL);
	else
		insertNode(data, this->root);
}

void insertNode(int data, Node root)
{
	if (root->value > data)
	{
		if (root->left == NULL)
		{
			root->left = new Node(data, root);
			return;
		}

		insertNode(data, root->left);
	}
	else if (root->value < data)
	{
		if (root->right == NULL)
		{
			root->right = new Node(data, root);
			return;
		}

		insertNode(data, root->right);
	}
	else
	{
		// Return error, this value already in BST
	}
}
