bool get_combinations(std::vector<std::string> &combinations, std::string digits)
{
	size_t size;
	char letter, buff[2];
	std::string str, letters;

	static std::map <char, std::string> map =
	{
		{ '2', "abc" },
		{ '3', "def" },
		{ '4', "ghi" },
		{ '5', "jkl" },
		{ '6', "mno" },
		{ '7', "pqrs" },
		{ '8', "tuv" },
		{ '9', "wxyz" }
	};

	if (0 == digits.length())
		return false;

	letter = digits[0];
	digits.erase(0, 1);

	letters = map[letter];

	if (0 == combinations.size())
	{
		for (size_t i = 0; i < letters.length(); i++)
		{
			buff[0] = letters[i];
			buff[1] = 0;

			combinations.push_back(buff);
		}
	}
	else
	{
		size = combinations.size();
		for (size_t i = 0; i < size; i++)
		{
			str = combinations[0];
			combinations.erase(combinations.begin());

			for (size_t j = 0; j < letters.length(); j++)
			{
				buff[0] = letters[j];
				buff[1] = 0;

				combinations.push_back(str + buff);
			}
		}
	}

	return get_combinations(combinations, digits);
}

std::vector<std::string> letterCombinations(std::string digits)
{
	std::vector<std::string> result;

	result.clear();

	get_combinations(result, digits);

	return result;
}
