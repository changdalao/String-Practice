bool IsPalindrome(string s)
{
	int len = s.length();
	if (len % 2 == 1)
	{
		for (int i = 0; i < len-2; i++)
		{
			if (s[i] != s[i + 1])
				return false;
		}
		return true;
	}
	if (len % 2 == 0)
	{
		int begin = 0;
		int end = len-1;
		while (begin < end) {
			if (s[begin] != s[end])
				return false;
			begin++;
			end--;
		}
	}
	return true;
}
