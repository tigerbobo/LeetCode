void get_count(std::string str, int &left, int &right)
{
	left = right = 0;

	for (size_t i = 0; i < str.length(); i++)
	{
		if ('(' == str[i])
			left += 1;
		else
			right += 1;
	}
}

void parenthesis(std::vector<std::string> &result, int n)
{
	size_t size;
	std::string str;
	int left, right;

	if (0 == n)
		return;

	size = result.size();

	if (0 == size)
	{
		result.push_back("(");
		return parenthesis(result, n);
	}

	for (size_t i = 0; i < size; i++)
	{
		str = result[0];
		get_count(str, left, right);

		if ((n == left) && (n == right))
			continue;

		result.erase(result.begin());

		if ('(' == str[str.length() - 1])
		{
			if (left < n)
			{
				result.push_back(str + "(");
				result.push_back(str + ")");
				return parenthesis(result, n);
			}
			else
			{
				result.push_back(str + ")");
				return parenthesis(result, n);
			}
		}
		else
		{
			if (left < n)
			{
				result.push_back(str + "(");
				
				if(left > right)
					result.push_back(str + ")");
				return parenthesis(result, n);
			}
			else
			{
				result.push_back(str + ")");
				return parenthesis(result, n);
			}
		}		
	}
}

std::vector<std::string> generateParenthesis(int n)
{
	std::vector<std::string> result;

	result.clear();

	parenthesis(result, n);

	return result;
}
