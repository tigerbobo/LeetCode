struct ListNode
{
	int val;
	ListNode *next;
	ListNode() : val(0), next(0) {}
	ListNode(int x) : val(x), next(0) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
	ListNode *temp, *temp1, *temp2;

	if (NULL == l1)
		return l2;

	if (NULL == l2)
		return l1;

	if (l1->val > l2->val)
	{
		temp1 = l1;
		l1 = l2;
		l2 = temp1;
	}

	temp1 = l1;
	temp2 = l2;

	while (temp1 && temp2)
	{
		if (NULL == temp1->next)
			break;

		if (temp1->next->val < temp2->val)
		{
			temp1 = temp1->next;
			continue;
		}

		temp = temp1->next;

		temp1->next = temp2;
		temp1 = temp1->next;

		temp2 = temp2->next;
		temp1->next = temp;
	}

	if (temp2)
		temp1->next = temp2;

	return l1;
}
