#include <string>
#include <algorithm>


int reverse(int x)
{
	std::string s;
	char buffer[100] = { 0 };
	long long result = abs(x);

	sprintf_s(buffer, 100, "%lld", result);

	s = buffer;

	std::reverse(s.begin(), s.end());

	if (x >= 0)
	{
		result = atoll(s.c_str());
		if (result > INT_MAX)
			result = 0;
	}
	else
	{
		result = 0 - atoll(s.c_str());
		if (result < INT_MIN)
			result = 0;
	}

	return result;
}
