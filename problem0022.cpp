#include <iostream>
#include <vector>

using namespace std;

void changeString(string& s)
{
    s += "!!!";
}

void changeVector(vector<string>& v)
{
    v.push_back("Hehehe");
}

void gen1(string s, int opened, int closed, int n, vector<string>& result)
{
    if (s.size() == n * 2 - 1)
    {
        s += ")";
        result.push_back(s);
        return;
    }
    if (opened == closed)
    {
        s += "(";
        gen1(s, opened + 1, closed, n, result);
        return;
    }
    if (opened == n)
    {
        s += ")";
        gen1(s, opened, closed + 1, n, result);
        return;
    }
    gen1(s + "(", opened + 1, closed, n, result);
    gen1(s + ")", opened, closed + 1, n, result);
}

vector<string> generateParenthesis(int n) {
    vector<string> result;
    gen1("(", 1, 0, n, result);
    return result;
}

int main()
{
    string s = "Hi";
    changeString(s);
    
    vector<string> v;
    v.push_back(s);
    changeVector(v);
    cout << v.size() << endl;

    generateParenthesis(3);
}