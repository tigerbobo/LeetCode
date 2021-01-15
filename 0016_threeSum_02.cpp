std::vector<std::vector<int>> threeSum(std::vector<int>& nums)
{
	size_t first, second, third;
	std::vector<int> group;
	std::vector<std::vector<int>> result;

	result.clear();

	std::sort(nums.begin(), nums.end());

	for (first = 0; first < nums.size(); first++)
	{
		if ((first > 0) && (nums[first - 1] == nums[first]))
			continue;

		third = nums.size() - 1;

		for (second = first + 1; second < nums.size(); second++)
		{
			if ((second > first + 1) && (nums[second - 1] == nums[second]))
				continue;

			while (true)
			{
				if (second >= third)
					break;

				if (nums[first] + nums[second] + nums[third] > 0)
				{
					third -= 1;
					continue;
				}
				else if (nums[first] + nums[second] + nums[third] == 0)
				{
					result.push_back({ nums[first], nums[second], nums[third] });
					break;
				}
				else
					break;
			}
		}
	}

	return result;
}
