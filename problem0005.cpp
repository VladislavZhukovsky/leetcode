#include <iostream>

using namespace std;

bool isPalindrome_v1(string s, int start, int end)
{
    if (end - start == 1)
    {
        return s[start] == s[end];
    }
    while (end - start > 0)
    {
        if (s[start] != s[end])
        {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

string longestPalindrome_v1(string s) {
    if (isPalindrome_v1(s, 0, s.length() - 1))
    {
        return s;
    }
    for (int l = s.length() - 1; l > 1; l--)
    {
        for(int i = 0; i <= s.length() - l; i++)
        {
            if (isPalindrome_v1(s, i, i + l - 1))
            {
                return s.substr(i, l);
            }
        }
    }
    return s.substr(0, 1);
}

int expand1(string s, int i)
{
    int length = -1;
    int a = i;
    int b = i;
    while (a >= 0 && b < s.length() && s[a] == s[b])
    {
        length += 2;
        a--;
        b++;
    }
    return length;
}

int expand2(string s, int i)
{
    int length = 0;
    int a = i;
    int b = i + 1;
    while (a >= 0 && b < s.length() && s[a] == s[b])
    {
        length += 2;
        a--;
        b++;
    }
    return length;
}

string longestPalindrome(string s) {
    if (s.length() == 1)
    {
        return s;
    }
    if (s.length() == 2)
    {
        if (s[0] == s[1]) return s;
        else return s.substr(0,1);
    }
    int result_i = 0;
    int result_length = 0;
    for (int i = 0; i < s.length() - 1; i++)
    {
        int p = expand1(s, i);
        int q = expand2(s, i);
        int r;
        if (p > q)
        {
            if (p > result_length)
            {
                result_i = i - p / 2;
                result_length = p;
            }
        }
        else
        {
            if (q > result_length)
            {
                result_i = i - q / 2 + 1;
                result_length = q;
            }
        }
    }
    return s.substr(result_i, result_length);
}

int main()
{
    string s = "aaaacaaaa";
    cout << longestPalindrome(s) << endl;
}