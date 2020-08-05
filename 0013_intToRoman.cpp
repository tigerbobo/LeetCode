static std::map<int, std::string> roman = {
	{ 1, "I" },
	{ 2, "II" },
	{ 3, "III" },
	{ 4, "IV" },
	{ 5, "V" },
	{ 6, "VI" },
	{ 7, "VII" },
	{ 8, "VIII" },
	{ 9, "IX" },
	{ 10, "X" },
	{ 20, "XX" },
	{ 30, "XXX" },
	{ 40, "XL" },
	{ 50, "L" },
	{ 60, "LX" },
	{ 70, "LXX" },
	{ 80, "LXXX" },
	{ 90, "XC" },
	{ 100, "C" },
	{ 200, "CC" },
	{ 300, "CCC" },
	{ 400, "CD" },
	{ 500, "D" },
	{ 600, "DC" },
	{ 700, "DCC" },
	{ 800, "DCCC" },
	{ 900, "CM" },
	{ 1000, "M" },
	{ 2000, "MM" },
	{ 3000, "MMM" } };

std::string intToRoman(int num)
{
	int temp;
	std::string result = "";
	std::vector<std::string> numstr;

	do
	{
		// x
		temp = num % 10;
		num  = num / 10;
		
		if (roman.find(temp) != roman.end())
			numstr.insert(numstr.begin(), roman[temp]);
		
		if (0 == num)
			break;

		// 1x
		temp = num % 10;
		num = num / 10;

		temp *= 10;
		if (roman.find(temp) != roman.end())
			numstr.insert(numstr.begin(), roman[temp]);

		if (0 == num)
			break;

		// 1xx
		temp = num % 10;
		num = num / 10;

		temp *= 100;

		if (roman.find(temp) != roman.end())
			numstr.insert(numstr.begin(), roman[temp]);

		if (0 == num)
			break;

		// 1xxx
		temp = num % 10;
		num = num / 10;

		temp *= 1000;

		if (roman.find(temp) != roman.end())
			numstr.insert(numstr.begin(), roman[temp]);

		if (0 == num)
			break;

	} while (0);
	
	for (size_t i = 0; i < numstr.size(); i++)
		result += numstr[i];

	return result;
}
