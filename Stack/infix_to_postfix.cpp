#include <iostream>
#include <stack>
#include <string>

using namespace std;

int precedence(char p)
{
    switch (p)
    {
    case '^':
        return 2;
        break;
    case '/':
    case '*':
        return 1;
        break;
    case '-':
    case '+':
        return 0;
        break;
    }
    return 0;
}

bool right_associative(char s)
{
    if (s == '^')
    {
        return true;
    }
    return false;
}

string infix_to_postfix(string s)
{
    string result = "";
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))
        {
            result.push_back(s[i]);
        }
        else if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                result += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            if (right_associative(s[i]) && !st.empty() && (precedence(s[i]) == precedence(st.top())))
            {
                st.push(s[i]);
                continue;
            }

            while (!st.empty() && st.top() != '(' && (precedence(s[i]) <= precedence(st.top())))
            {
                result += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }
    return result;
}
int main()
{
    // cout << infix_to_postfix("k+l-m*n+(o^p)*w/u/v*t+q^z^t^y") << endl;
    cout << infix_to_postfix("k^l-m*n^z^t^y") << endl;
    // cout << infix_to_postfix("a+b*c/(m*n)^q^y^t") << endl;
    // cout << infix_to_postfix("(a+b)/c") << endl;
    return 0;
}