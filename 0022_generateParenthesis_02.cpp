void parenthesis(std::vector<std::string> &result, int n, int left, int right)
{
	size_t size;
	std::string str;

	if (0 == n)
		return;

	if ((n == left) && (n == right))
		return;

	size = result.size();

	if (0 == size)
	{
		result.push_back("(");
		parenthesis(result, n, 1, 0);
		return;
	}

	str = result[size - 1];

	result.pop_back();

	if ('(' == str[str.length() - 1])
	{
		if (left < n)
		{
			result.push_back(str + "(");
			parenthesis(result, n, left + 1, right);

			result.push_back(str + ")");
			parenthesis(result, n, left, right + 1);
		}
		else
		{
			result.push_back(str + ")");
			parenthesis(result, n, left, right + 1);
		}
	}
	else
	{
		if (left < n)
		{
			result.push_back(str + "(");
			parenthesis(result, n, left + 1, right);

			if (left > right)
			{
				result.push_back(str + ")");
				parenthesis(result, n, left, right + 1);
			}
		}
		else
		{
			result.push_back(str + ")");
			parenthesis(result, n, left, right + 1);
		}
	}
}

std::vector<std::string> generateParenthesis(int n)
{
	std::vector<std::string> result;

	result.clear();

	parenthesis(result, n, 0, 0);

	return result;
}
