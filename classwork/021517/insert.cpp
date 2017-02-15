/* O(n) for signle linked => O(1) for double linked */
void insert(int d)
{
	Node *new_node = new Node(d);
	Node *tmp = this->tail;

	this->tail->next = new_node; // [OLD_END] => NULL ; [OLD] => [NEW] => NULL
	this->tail = this->tail->next; // [NEW_END] => NULL
	this->tail->prev = tmp;
}
