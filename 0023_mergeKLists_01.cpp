struct ListNode
{
	int val;
	ListNode *next;
	ListNode() : val(0), next(0) {}
	ListNode(int x) : val(x), next(0) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeKLists(std::vector<ListNode*>& lists)
{
	int val = 0, index = 0;
	ListNode *temp = NULL, *result = NULL;

	while (true)
	{
		index = -1;

		for (int i = 0; i < (int)(lists.size()); i++)
		{
			if (NULL == lists[i])
				continue;

			if (temp && (temp->val == lists[i]->val))
			{
				index = i;
				break;
			}

			if ((-1 == index) || (lists[i]->val < val))
			{
				index = i;
				val = lists[i]->val;

				continue;
			}
		}

		if (-1 == index)
			break;

		if (NULL == result)
		{
			result = lists[index];
			temp = lists[index];
		}
		else
		{
			temp->next = lists[index];
			temp = temp->next;
		}

		lists[index] = lists[index]->next;
	}

	return result;
}
