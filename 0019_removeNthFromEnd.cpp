struct ListNode
{
	int val;
	ListNode *next;
	ListNode() : val(0), next(0) {}
	ListNode(int x) : val(x), next(0) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n)
{
	size_t index;
	std::vector<ListNode*> list;
	ListNode *previous, *this_node = head;

	list.clear();

	while (true)
	{
		if (0 == this_node)
			break;

		list.push_back(this_node);
		this_node = this_node->next;
	}

	index = list.size() - size_t(n);
	this_node = list[index];

	if (0 == index)
	{
		head = head->next;
		delete this_node;
	}
	else
	{
		previous = list[index - 1];
		previous->next = this_node->next;
		delete this_node;
	}

	return head;
}
