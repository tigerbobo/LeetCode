std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target)
{
	size_t first, second, third, fourth;
	std::vector<std::vector<int>> result;

	result.clear();

	std::sort(nums.begin(), nums.end());

	for (first = 0; first < nums.size(); first++)
	{
		if ((first > 0) && (nums[first] == nums[first - 1]))
			continue;

		for (second = first + 1; second < nums.size(); second++)
		{
			fourth = nums.size() - 1;

			if ((second > first + 1) && (nums[second] == nums[second - 1]))
				continue;

			for (third = second + 1; third < nums.size(); third++)
			{
				if ((third > second + 1) && (nums[third] == nums[third - 1]))
					continue;

				while (((nums[first] + nums[second] + nums[third] + nums[fourth]) > target) && (fourth > third))
					fourth -= 1;

				if (fourth <= third)
					break;

				if ((nums[first] + nums[second] + nums[third] + nums[fourth]) == target)
				{
					result.push_back({ nums[first], nums[second], nums[third], nums[fourth] });
					continue;
				}
				else
					continue;
			}
		}
	}

	return result;
}
