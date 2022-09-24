#include <iostream>

using namespace std;

int main()
{
    //char* s = "123";
    //char c = s[1];
    //cout << c << endl;
    //int x = atoi(s);
    //cout << x;

    string s = "-91283472332";
    cout << "Input: " << s << endl;

    bool sign = false; //+
    bool run = true;
    int n = s.length();

    if (n == 0) return 0;

    int i = -1;
    while (run && i < n)
    {
        i++;
        char c = s[i];
        if (c != ' ')
        {
            run = false;
        }
    }

    if (i == n) return 0;

    if (s[i] == '.' || (s[i] >= 65 && s[i] <= 122))
    {
        return 0;
    }

    if (s[i] == '-' || s[i] == '+')
    {
        if (i < n && s[i] == '-')
        {
            sign = true;
        }
        i++;
        if (i >= n || !(s[i] >= '0' && s[i] <= '9'))
        {
            return 0;
        }
    }

    int result = 0;
    const int INTMAXDIV10 = INT32_MAX / 10;
    cout << "Sign: " << sign << endl;
    while(i < n && s[i] >= '0' && s[i] <= '9')
    {
        cout << result << endl;
        char c = s[i];
        if (c >= '0' && c <= '9')
        {
            if (result > INTMAXDIV10)
            {
                if (sign)
                {
                    return INT32_MIN;
                }
                else
                {
                    return INT32_MAX;
                }
                break;
            }
            if (result == INTMAXDIV10)
            {
                if (!sign && c >= 56)
                {
                    return INT32_MAX;
                }
                if (sign && c >= 56)
                {
                    return INT32_MIN;
                }
            }
            result = result * 10 + (c - 48);
        }
        i++;
    }

    if (sign) result = -result;
    cout << result;
    return result;
}