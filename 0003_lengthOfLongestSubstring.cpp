#include <string>
#include <unordered_set>

int lengthOfLongestSubstring(std::string s)
{
	std::unordered_set<char> set;
	int start = 0, stop = 0, length = 0;

	while (0 != s[stop])
	{
		if (set.find(s[stop]) == set.end())
		{
			set.insert(s[stop++]);
			if (stop - start > length)
				length = stop - start;
		}
		else
			set.erase(s[start++]);
	}

	return length;
}
