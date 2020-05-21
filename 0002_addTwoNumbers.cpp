struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
	int carry;
	ListNode *node, *result = new ListNode(0);

	carry = 0;
	node = result;

	while (true)
	{
		node->val = carry;

		if (NULL != l1)
		{
			node->val += l1->val;
			l1 = l1->next;
		}

		if (NULL != l2)
		{
			node->val += l2->val;
			l2 = l2->next;
		}

		if (node->val < 10)
			carry = 0;
		else
		{
			carry = 1;
			node->val -= 10;
		}

		if ((NULL == l1) && (NULL == l2))
			break;

		node->next = new ListNode(0);
		node = node->next;
	}

	if(carry)
		node->next = new ListNode(carry);

	return result;
}
