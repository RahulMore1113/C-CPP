#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isWellParenthesized(const string &expression)
{
    stack<char> s; // Stack to store opening parentheses

    for (char ch : expression)
    {
        // If it's an opening bracket, push it onto the stack
        if (ch == '(' || ch == '{' || ch == '[')
        {
            s.push(ch);
        }
        // If it's a closing bracket
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            // Check if stack is empty or the top element doesn't match
            if (s.empty())
            {
                return false;
            }
            char top = s.top();
            s.pop();

            // Check if the popped element matches the current closing bracket
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '['))
            {
                return false;
            }
        }
    }

    // If stack is empty, all opening brackets matched with closing ones
    return s.empty();
}

int main()
{
    string expression;

    cout << "Enter an expression to check if it is well-parenthesized: ";
    cin >> expression;

    if (isWellParenthesized(expression))
    {
        cout << "The expression is well-parenthesized!" << endl;
    }
    else
    {
        cout << "The expression is not well-parenthesized." << endl;
    }

    return 0;
}
