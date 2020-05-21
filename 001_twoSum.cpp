#include <vector>
#include <unordered_map>

std::vector<int> twoSum(std::vector<int>& nums, int target)
{
	std::vector<int> result;
	std::unordered_map<int, int> map;

	map.clear();
	result.clear();

	for (int i = 0; i < (int)(nums.size()); i++)
	{
		if (map.find(target - nums[i]) == map.end())
			map[nums[i]] = i;
		else
		{
			result.push_back(i);
			result.push_back(map[target - nums[i]]);

			break;
		}
	}

	return result;
}

void test()
{
	std::vector<int> nums, result;

	nums.push_back(3);
	nums.push_back(2);
	nums.push_back(4);
	nums.push_back(5);
	nums.push_back(7);

	result = twoSum(nums, 6);
}
