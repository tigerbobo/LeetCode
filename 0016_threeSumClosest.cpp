int threeSumClosest(std::vector<int>& nums, int target)
{
	int last, current, result;
	size_t first, second, third;

	std::sort(nums.begin(), nums.end());

	last = nums[0] + nums[1] + nums[2];
	current = nums[nums.size() - 3] + nums[nums.size() - 2] + nums[nums.size() - 1];

	if(abs(last - target) >= abs(current - target))
		result = last;
	else
		result = current;

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

				current = nums[first] + nums[second] + nums[third];
				if (current == target)
					return target;

				if (abs(result - target) > abs(current - target))
					result = current;
			
				if (nums[first] + nums[second] + nums[third] > target)
				{
					third -= 1;
					continue;
				}
				else
				{
					if (third != nums.size() - 1)
					{
						last = nums[first] + nums[second] + nums[third + 1];
						current = nums[first] + nums[second] + nums[third];

						if (abs(result - target) > abs(last - target))
							result = last;

						if (abs(result - target) > abs(current - target))
							result = current;
					}

					break;
				}
			}
		}
	}

	return result;
}
