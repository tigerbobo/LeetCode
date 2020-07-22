bool isPalindrome(int x)
{
	if (x < 0)
		return false;

	if (x < 10)
		return true;

	int start, stop;
	bool result = true;
	int offset = 0, length = 0, buffer[10];

	memset(buffer, -1, sizeof(buffer));

	while (true)
	{
		buffer[offset++] = x % 10;
		x /= 10;
		length += 1;

		if (0 == x)
			break;
	}

	start = 0;
	stop = length - 1;

	while (true)
	{
		if (start >= stop)
			break;

		if (buffer[start++] != buffer[stop--])
		{
			result = false;
			break;
		}
	}

	return result;
}
