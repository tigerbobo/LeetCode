int myAtoi(std::string str)
{
	char ch;
	int offset = 0, result = 0, sign = 1, flag = 0;

	while (true)
	{
		if (0 == str[offset])
			break;

		ch = str[offset++];
		if (' ' == ch)
		{
			if (0 != flag)
				break;

			continue;
		}

		if ('-' == ch)
		{
			if (0 == flag)
			{
				sign = -1;
				flag = 1;
				continue;
			}
			else
				break;
		}

		if ('+' == ch)
		{
			if (0 == flag)
			{
				sign = 1;
				flag = 1;
				continue;
			}
			else
				break;
		}

		if((ch < '0') || (ch > '9'))
			break;

		flag = 1;

		if (sign > 0)
		{
			if (result > INT_MAX / 10)
				return INT_MAX;
		}
		else
		{
			if (result < INT_MIN / 10)
				return INT_MIN;
		}
		result *= 10;

		if (sign > 0)
		{
			if (INT_MAX - result < ch - '0')
				return INT_MAX;
		}
		else
		{
			if (INT_MIN - result > (ch - '0') * sign)
				return INT_MIN;
		}
		result += (ch - '0') * sign;
	}

	return result;
}
