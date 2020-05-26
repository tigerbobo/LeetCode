#include <vector>
#include <algorithm>

double get_min(int num1, int num2, int num_max)
{
	if (num1 == num_max)
		return (double)(num2);

	if (num2 == num_max)
		return (double)(num1);

	return min(num1, num2);
}

double get_min(std::vector<int>& nums1, std::vector<int>& nums2, int offset1, int offset2, int num_min, int num_max)
{
	std::vector<int> nums;
	int left, right, total;
	int num1, num2, num3, num4;

	num1 = num2 = num3 = num4 = num_max;

	total = (int)(nums1.size());
	left = offset1 + 1;
	right = total - left;

	if (right > 0)
		num1 = nums1[offset1 + 1];

	if (right > 1)
		num2 = nums1[offset1 + 2];

	total = (int)(nums2.size());
	left = offset2 + 1;
	right = total - left;

	if (right > 0)
		num3 = nums2[offset2 + 1];

	if (right > 1)
		num4 = nums2[offset2 + 2];

	nums.push_back(num1);
	nums.push_back(num2);
	nums.push_back(num3);
	nums.push_back(num4);

	std::sort(nums.begin(), nums.end());

	return (double)(nums[0] + nums[1]) / 2.0;
}

double get_max(int num1, int num2, int num_min)
{
	if (num1 == num_min)
		return (double)(num2);

	if (num2 == num_min)
		return (double)(num1);

	return max(num1, num2);
}

double get_max(std::vector<int>& nums1, std::vector<int>& nums2, int offset1, int offset2, int num_min, int num_max)
{
	std::vector<int> nums;
	int left, right, total;
	int num1, num2, num3, num4;

	num1 = num2 = num3 = num4 = num_min;

	total = (int)(nums1.size());
	left = offset1 + 1;
	right = total - left;

	if (right > 0)
		num1 = nums1[offset1];

	if (right > 1)
		num2 = nums1[offset1 - 1];

	total = (int)(nums2.size());
	left = offset2 + 1;
	right = total - left;

	if (right > 0)
		num3 = nums2[offset2];

	if (right > 1)
		num4 = nums2[offset2 - 1];

	nums.push_back(num1);
	nums.push_back(num2);
	nums.push_back(num3);
	nums.push_back(num4);

	std::sort(nums.begin(), nums.end());

	return (double)(nums[2] + nums[3]) / 2.0;
}

double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2)
{
	int num_min, num_max;
	int offset1, offset2;
	int left, right, total;
	int left1, left2, right1, right2;

	if (0 == nums1.size())
	{
		nums1.insert(nums1.begin(), nums2[0] - 1);
		nums1.insert(nums1.end(), nums2[nums2.size() - 1] + 1);
	}

	if (0 == nums2.size())
	{
		nums2.insert(nums2.begin(), nums1[0] - 1);
		nums2.insert(nums2.end(), nums1[nums1.size() - 1] + 1);
	}

	num_min = min(*(nums1.begin()), *(nums2.begin())) - 1;
	num_max = max(*(nums1.end() - 1), *(nums2.end() - 1)) + 1;

	nums1.insert(nums1.begin(), num_min);
	nums1.insert(nums1.end(), num_max);

	nums2.insert(nums2.begin(), num_min);
	nums2.insert(nums2.end(), num_max);

	offset1 = (int)(nums1.size()) / 2 - 1;
	offset2 = (int)(nums2.size()) / 2 - 1;

	while (true)
	{
		left1 = nums1[offset1];
		right1 = nums1[offset1 + 1];

		left2 = nums2[offset2];
		right2 = nums2[offset2 + 1];

		if (left1 > right2)
		{
			offset1 -= 1;
			offset2 += 1;
		}
		else if (left2 > right1)
		{
			offset1 += 1;
			offset2 -= 1;
		}
		else
			break;
	}

	total = (int)(nums1.size() + nums2.size());
	left = offset1 + offset2 + 2;
	right = total - left;

	if (0 == total % 2)
	{
		if (left == right)
			return (double)(max(nums1[offset1], nums2[offset2]) + min(nums1[offset1 + 1], nums2[offset2 + 1])) / 2.0;
		else if (left < right)
			return get_min(nums1, nums2, offset1, offset2, num_min, num_max);
		else
			return get_max(nums1, nums2, offset1, offset2, num_min, num_max);
	}
	else
	{
		if (left < right)
			return get_min(nums1[offset1 + 1], nums2[offset2 + 1], num_max);
		else
			return get_max(nums1[offset1], nums2[offset2], num_min);
	}
}
