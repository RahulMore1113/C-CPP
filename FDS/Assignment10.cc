#include <iostream>
#include <stack>
#include <cctype> // for isdigit() function
#include <cmath>  // for handling evaluation of the expression

using namespace std;

// Function to return the precedence of operators
int precedence(char op)
{
    if (op == '+' || op == '-')
    {
        return 1;
    }
    else if (op == '*' || op == '/')
    {
        return 2;
    }
    return 0;
}

// Function to perform the operation
int applyOperator(int a, int b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    }
    return 0;
}

// Function to convert infix expression to postfix
string infixToPostfix(string infix)
{
    stack<char> operators;
    string postfix = "";

    for (int i = 0; i < infix.length(); ++i)
    {
        char ch = infix[i];

        // If the character is an operand, add it to the postfix expression
        if (isalnum(ch))
        {
            postfix += ch;
        }
        // If the character is '(', push it to the stack
        else if (ch == '(')
        {
            operators.push(ch);
        }
        // If the character is ')', pop from the stack until '(' is found
        else if (ch == ')')
        {
            while (!operators.empty() && operators.top() != '(')
            {
                postfix += operators.top();
                operators.pop();
            }
            operators.pop(); // Pop '('
        }
        // If the character is an operator
        else
        {
            while (!operators.empty() && precedence(operators.top()) >= precedence(ch))
            {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(ch);
        }
    }

    // Pop all remaining operators from the stack
    while (!operators.empty())
    {
        postfix += operators.top();
        operators.pop();
    }

    return postfix;
}

// Function to evaluate a postfix expression
int evaluatePostfix(string postfix)
{
    stack<int> values;

    for (int i = 0; i < postfix.length(); ++i)
    {
        char ch = postfix[i];

        // If the character is an operand, push it onto the stack
        if (isalnum(ch))
        {
            values.push(ch - '0'); // Convert char to int (assuming single digit operands)
        }
        // If the character is an operator, pop two values and apply the operator
        else
        {
            int b = values.top();
            values.pop();
            int a = values.top();
            values.pop();
            int result = applyOperator(a, b, ch);
            values.push(result);
        }
    }

    // The result will be the only value left in the stack
    return values.top();
}

int main()
{
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    // Convert infix to postfix
    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    // Evaluate the postfix expression
    int result = evaluatePostfix(postfix);
    cout << "Evaluation result: " << result << endl;

    return 0;
}
