#include <iostream>
#include "Stack.h"
#include "LimitedStack.h"

std::string getRpn(std::string str);

int getRes(std::string rpn);

int main()
{
    std::string string;

    std::cout << "Enter your mathematical expression: ";
    std::cin >> string;
    
    LimitedStack<char> stack(string.length());

    std::cout << getRpn(string) << '\n';

    std::cout << getRes(getRpn(string)) << '\n';

    return 0;
}

std::string getRpn(std::string str) {
    std::string rpn;
    LimitedStack<int> stack(str.length());
    
    for (char i : str) {
        if (i == '(') {
            stack.push(i);
        }

        else if (i == ')') {
            while (!stack.isEmpty() && stack.peek() != '(') {
                rpn += stack.pop();
            }
            stack.pop();
        }

        else if (i == '+' || i == '-' || i == '*' || i == '/') {
            while (!stack.isEmpty() && stack.peek() != '(') {
                rpn += stack.pop();
            }
            stack.push(i);
        }
        
        else {
            rpn += i;
        }
    }
    while (!stack.isEmpty()) { rpn += stack.pop(); }

    return rpn;
}

int getRes(std::string rpn) {
    LimitedStack<int> stack(rpn.length());

    for (int i : rpn) {
        if (i == '+' || i == '-' || i == '*' || i == '/') {
            
            int second = stack.pop();
            int first = stack.pop();

            if (i == '+') stack.push(first + second);
            if (i == '-') stack.push(first - second);
            if (i == '*') stack.push(first * second);
            if (i == '/') stack.push(first / second);
        }
        else {
            stack.push(i - '0');
        }
    }

    return stack.pop();
}