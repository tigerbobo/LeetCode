#include <string>

void palindrome(std::string &s, int &start, int &stop)
{
	int offset1, offset2, length = (int)(s.length());

	offset1 = start;
	offset2 = stop;

	start = stop = 0;

	while ((offset1 >= 0) && (offset2 < length))
	{
		if (s[offset1] == s[offset2])
		{
			start = offset1;
			stop = offset2;

			offset1 -= 1;
			offset2 += 1;
		}
		else
			break;
	}
}

std::string longestPalindrome(std::string s)
{
	int offset, count;
	int start, stop, length, length_longest;

	offset = count = 0;
	start = stop = length_longest = 0;

	length = (int)(s.length());
	for (int i = 0; i < length; i++)
	{
		start = i;
		stop = i;
		palindrome(s, start, stop);

		if (stop - start + 1 > length_longest)
		{
			offset = start;
			count = stop - start + 1;

			length_longest = count;
		}

		//////////////////////////////

		start = i;
		stop = i + 1;
		palindrome(s, start, stop);

		if (stop - start + 1 > length_longest)
		{
			offset = start;
			count = stop - start + 1;

			length_longest = count;
		}
	}

	return s.substr(offset, count);
}
