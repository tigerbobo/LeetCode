bool isValid(std::string s)
{
	char left, temp;
	bool result = true;
	std::vector<char> lefts;
	std::map<char, char> map = { {')', '('}, { ']', '[' }, { '}', '{' } };

	lefts.clear();

	for (size_t i = 0; i < s.length(); i++)
	{
		if (('(' == s[i]) || ('[' == s[i]) || ('{' == s[i]))
		{
			lefts.push_back(s[i]);
			continue;
		}

		if (0 == lefts.size())
			return false;

		left = lefts.back();
		temp = map[s[i]];
		if(left != temp)
			return false;

		lefts.pop_back();
	}
	
	return 0 == lefts.size() ? true : false;
}
