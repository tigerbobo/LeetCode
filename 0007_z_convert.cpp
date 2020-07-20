std::string convert(std::string s, int rows)
{
	std::string result = "";
	int index = 0, value = 1;
	size_t length = s.length();
	std::vector<std::string> strings;

	if (1 == rows)
		return s;

	strings.clear();
	for (int i = 0; i < rows; i++)
		strings.push_back("");

	for (size_t i = 0; i < length; i++)
	{
		strings[index] += s[i];

		index += value;
		if (index == rows)
		{
			index = rows - 2;
			value = -1;
		}

		if (index < 0)
		{
			index = 1;
			value = 1;
		}
	}

	for (int i = 0; i < rows; i++)
		result += strings[i];

	return result;
}
