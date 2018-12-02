#ifndef LARGE_SUM_H
#define LARGE_SUM_H
#include <cstdlib>
#include <stack>
#include <iostream>
#include <cstring>

int getInt(char);

char *largeSumInt(char *arg1, char *arg2)
{
    int carry = 0, resultSize;
    char* result;
    std::stack<int> arg1Stack, arg2Stack, resultStack;
    for (int i = 0; i < strlen(arg1); i++)
        arg1Stack.push(getInt(arg1[i]));
    for (int i = 0; i < strlen(arg2); i++)
        arg2Stack.push(getInt(arg2[i]));
    while (!arg1Stack.empty() && !arg2Stack.empty())
    {
        resultStack.push((arg1Stack.top() + arg2Stack.top() + carry) % 10);
        carry = (arg1Stack.top() + arg2Stack.top() + carry) / 10;
        arg1Stack.pop();
        arg2Stack.pop();
    }
    while (!arg1Stack.empty())
    {
        resultStack.push((arg1Stack.top() + carry) % 10);
        carry = (arg1Stack.top() + carry) / 10;
        arg1Stack.pop();
    }
    while (!arg2Stack.empty())
    {
        resultStack.push((arg2Stack.top() + carry) % 10);
        carry = (arg2Stack.top() + carry) / 10;
        arg2Stack.pop();
    }
    resultSize = resultStack.size() + 1;
    result = new char[resultSize];
    result[resultSize-1] = '\0';
    for(int i=resultSize-2;i>=0;i--)
    {
        result[i] = resultStack.top() + '0';
        resultStack.pop();
    }
    return result;
}

int getInt(char c)
{
    char str[2];
    str[0] = c;
    str[1] = '\0';
    return atoi(str);
}

#endif