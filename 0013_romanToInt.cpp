int romanToInt(std::string s)
{
	int i = 0, result = 0;

	while (true)
	{
		if (0 == s[i])
			break;

		if ('M' == s[i])
		{
			i += 1;
			result += 1000;
			continue;
		}

		if ('C' == s[i])
		{
			if ('M' == s[i + 1])
			{
				i += 2;
				result += 900;
				continue;
			}

			if ('D' == s[i + 1])
			{
				i += 2;
				result += 400;
				continue;
			}

			i += 1;
			result += 100;
			continue;
		}

		if ('D' == s[i])
		{
			i += 1;
			result += 500;
			continue;
		}

		if ('X' == s[i])
		{
			if ('C' == s[i + 1])
			{
				i += 2;
				result += 90;
				continue;
			}

			if ('L' == s[i + 1])
			{
				i += 2;
				result += 40;
				continue;
			}

			i += 1;
			result += 10;
			continue;
		}

		if ('L' == s[i])
		{
			i += 1;
			result += 50;
			continue;
		}

		if ('I' == s[i])
		{
			if ('X' == s[i + 1])
			{
				i += 2;
				result += 9;
				continue;
			}

			if ('V' == s[i + 1])
			{
				i += 2;
				result += 4;
				continue;
			}

			i += 1;
			result += 1;
			continue;
		}

		if ('V' == s[i])
		{
			i += 1;
			result += 5;
			continue;
		}
	}

	return result;
}
