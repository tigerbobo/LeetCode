size_t get_num(std::vector<int>& nums, size_t start, size_t stop, int num)
{
	size_t index = (start + stop) / 2;

	if (start > stop)
		return -1;

	if (nums[index] == num)
		return index;

	if (start == stop)
		return -1;

	if (nums[index] > num)
		return get_num(nums, start, index - 1, num);

	if (nums[index] < num)
		return get_num(nums, index + 1, stop, num);

	return -1;
}

// 4614.9191783754932 millisecond
std::vector<std::vector<int>> threeSum(std::vector<int>& nums)
{
	int sum = 0;
	size_t index;
	std::vector<int> group;
	std::map<std::vector<int>, int> map;
	std::vector<std::vector<int>> result;

	result.clear();

	std::sort(nums.begin(), nums.end());

	for (size_t i = 0; i < nums.size(); i++)
	{
		for (size_t j = i + 1; j < nums.size(); j++)
		{
			sum = nums[i] + nums[j];

			index = get_num(nums, j + 1, nums.size() - 1, 0 - sum);
			if (-1 != index)
			{
				group.clear();
				group.push_back(nums[i]);
				group.push_back(nums[j]);
				group.push_back(nums[index]);

				if (map.find(group) == map.end())
				{
					map[group] = 0;
					result.push_back(group);
				}

				continue;
			}
		}
	}

	return result;
}
