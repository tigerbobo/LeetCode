int reverse(int x)
{
	int temp, result = 0;

	temp = x;
	while (true)
	{
		if (x > 0)
		{
			if(result > INT_MAX / 10)
				return 0;
		}
		else
		{
			if (result < INT_MIN / 10)
				return 0;
		}
		result *= 10;

		if (x > 0)
		{
			if(INT_MAX - result < temp % 10)
				return 0;
		}
		else
		{
			if(INT_MIN - result > temp % 10)
				return 0;
		}
		
		result += temp % 10;

		temp /= 10;
		if (0 == temp)
			break;
	}

	return result;
}
