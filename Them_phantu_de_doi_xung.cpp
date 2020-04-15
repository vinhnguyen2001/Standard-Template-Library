#include<iostream>
#include<string>
using namespace std;
/*




*/
/*
   The solution can be achieved by removing characters from the beginning of the string  
 one by one and checking if the string is paindrome or not 
   For example , consider the above string s ='abede'
   We check if the string is palindrome or not.
   The result is false , then we remove the character from the beginning of string
 and now string become 'bede'
   We check if the string is palindrome or not .The result is again false , then we
 remove the character from the beginning of the string and now string becomes 'ede'.
 We check if the string is palindrome or not .The result is true...stop. &we  add the 
 character of the string we just removed earlier.
*/
bool checkIsPalindrome(string s)
{
	int len = s.length();
	for (int i = 0; i < len; i++)
	{
		if (s[i] != s[len - i - 1])
			return false;
	}
	return true;
}
string checkString(string s)
{
	int s_len = s.length();
	if (s_len == 1) return s;
	string sa;
	string a = s;
	int i = 1;
	while (!checkIsPalindrome(a))
	{
	     sa=s.substr(0, i);
		
		a.erase(0,1);//delete the character from the beginning of the string one by one.
		i++;
	}
	int len = sa.length();
	for (int i = len - 1; i >= 0; i--)
	{
		s += sa[i];//add the character of the string we just removed earlier.
	}
	return s;
}
int main()
{
	string a = "Xyzy";

	cout << " result " << checkString(a);

}
