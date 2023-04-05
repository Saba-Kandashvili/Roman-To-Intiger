#include <iostream>
#include <string>

using namespace std;

int RomanToInt(string);

int main()
{
	string str = "DCXXI";
	cout << str << "=" << RomanToInt(str) << endl;

	return 0;
}

int RomanToInt(string s)
{
	int num = 0;
	int i = 0;
	while (i < s.size())
	{
		if (s[i] != 'I' && s[i] != 'X' && s[i] != 'C')
		{
			switch (s[i])
			{
			case 'V': num += 5; break;
			case 'L': num += 50; break;
			case 'D': num += 500; break;
			case 'M': num += 1000; break;
			default:
				break;
			}
			i++;
		}
		else if (s[i] == 'I')
		{
			if (s[i+1] != 'I' && s[i + 1] != '\0')
			{
				switch (s[i+1])
				{
				case 'V': num += 4; break;
				case 'X': num += 9; break;
				default:
					break;
				}
				i += 2;
				continue;
			}
			else
			{
				num++;
				i++;
				continue;
			}
		}
		else if (s[i] == 'X')
		{
			if ((s[i + 1] == 'L' || s[i + 1] == 'C') && s[i + 1] != '\0')
			{
				switch (s[i+1])
				{
				case 'L': num += 40; break;
				case 'C': num += 90; break;
				default:
					break;
				}
				i += 2;
				continue;
			}
			else
			{
				num += 10;
				i++;
				continue;
			}
		}
		else if (s[i] == 'C')
		{
			if ((s[i + 1] == 'D' || s[i + 1] == 'M') && s[i + 1] != '\0')
			{
				switch (s[i + 1])
				{
				case 'D': num += 400; break;
				case 'M': num += 900; break;
				default:
					break;
				}
				i += 2;
				continue;
			}
			else
			{
				num += 100;
				i++;
				continue;
			}
		}
	}
	return num;
}