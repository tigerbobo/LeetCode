int maxArea(std::vector<int>& height)
{
	int temp, result = 0;
	int left = 0, right = (int)(height.size() - 1);

	while (true)
	{
		if (left >= right)
			break;

		temp = min(height[left], height[right]) * (right - left);
		if (temp > result)
			result = temp;

		if (height[left] > height[right])
			right -= 1;
		else
			left += 1;
	}

	return result;
}


int main()
{
	int result;
	std::vector<int> height = { 1,8,6,2,5,4,8,3,7 };

	result = maxArea(height);

	system("pause");
	return 0;
}
