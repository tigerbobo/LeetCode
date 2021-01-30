struct ListNode
{
	int val;
	ListNode *next;
	ListNode() : val(0), next(0) {}
	ListNode(int x) : val(x), next(0) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void quicksort(std::vector<ListNode*> &list, int low, int hight)
{
	ListNode *temp;
	bool flag = true;
	int val = list[low]->val, low_temp = low, hight_temp = hight;

	while (true)
	{
		if (low == hight)
			break;

		if ((true == flag) && (list[hight]->val >= val))
		{
			hight -= 1;
			continue;
		}
		
		if ((false == flag) && (list[low]->val <= val))
		{
			low += 1;
			continue;
		}

		temp = list[low];
		list[low] = list[hight];
		list[hight] = temp;

		flag = !flag;
	}

	low -= 1;
	hight += 1;
	if (low_temp < low)
		quicksort(list, low_temp, low);

	if (hight < hight_temp)
		quicksort(list, hight, hight_temp);
}

ListNode* mergeKLists(std::vector<ListNode*>& lists)
{
	ListNode *temp = NULL, *result = NULL;
	std::vector<ListNode*> list;

	list.clear();
	for (size_t i = 0; i < lists.size(); i++)
	{
		while (true)
		{
			if (NULL == lists[i])
				break;
			
			list.push_back(lists[i]);
			lists[i] = lists[i]->next;
		}
	}

	if (0 == list.size())
		return NULL;

	quicksort(list, 0, (int)(list.size() - 1));

	for (size_t i = 0; i < list.size(); i++)
	{
		if (NULL == result)
		{
			temp = list[i];
			result = list[i];
			continue;
		}

		temp->next = list[i];
		temp = temp->next;
	}

	temp->next = NULL;

	return result;
}
