bool match(const char *s, const char *p)
{
	char buff[3] = { 0, 0, 0 };

	strncpy_s(buff, 3, p, 2);

	if ((0 == *s) && (0 == *p))
		return true;

	if ((*s != *p) && ('.' != buff[0]) && ('*' != buff[1]))
		return false;

	if ((0 != *s) &&
		(0 != *p) &&
		('*' != p[strlen(p) - 1]) &&
		('.' != p[strlen(p) - 1]) &&
		(s[strlen(s) - 1] != p[strlen(p) - 1]))
		return false;

	if (0 == *p)
		return false;

	if ((0 == *s) && ('*' != buff[1]))
		return false;

	if ((0 == *s) && ('*' == buff[1]))
		return match(s, p + 2);

	if ((*s != *p) && ('.' != buff[0]) && ('*' == buff[1]))
		return match(s, p + 2);

	if ((*s != *p) && ('.' == buff[0]) && ('*' == buff[1]))
		return match(s + 1, p) || match(s, p + 2);

	if ((*s != *p) && ('.' == buff[0]) && ('*' != buff[1]))
		return match(s + 1, p + 1);

	if ((*s == *p) && ('*' != buff[1]))
		return match(s + 1, p + 1);

	if ((*s == *p) && ('*' == buff[1]))
		return match(s + 1, p) || match(s, p + 2);

	return true;
}

bool isMatch(std::string s, std::string p)
{
	return match(s.c_str(), p.c_str());
}

int main()
{
	bool result;

	result = isMatch("", "..*");

	system("pause");
	return 0;
}
