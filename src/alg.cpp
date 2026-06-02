// Copyright 2025 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

int getPriority(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

std::string infx2pstfx(const std::string& inf) {
    TStack<char, 100> stack;
    std::string result = "";
    int i = 0;

    while (i < inf.length()) {
        char ch = inf[i];

        if (ch == ' ') {
            i++;
            continue;
        }

        if (ch >= '0' && ch <= '9') {
            while (i < inf.length() && inf[i] >= '0' && inf[i] <= '9') {
                result += inf[i];
                i++;
            }
            result += ' ';
            continue;
        }

        if (ch == '(') {
            stack.push(ch);
        } else if (ch == ')') {
            while (!stack.isEmpty() && stack.get() != '(') {
                result += stack.pop();
                result += ' ';
            }
            if (!stack.isEmpty() && stack.get() == '(') {
                stack.pop();
            }
        } else {
            while (!stack.isEmpty() && stack.get() != '(' &&
                   getPriority(stack.get()) >= getPriority(ch)) {
                result += stack.pop();
                result += ' ';
            }
            stack.push(ch);
        }
        i++;
    }

    while (!stack.isEmpty()) {
        result += stack.pop();
        result += ' ';
    }

    if (!result.empty() && result.back() == ' ') {
        result.pop_back();
    }

    return result;
}

int eval(const std::string& post) {
    TStack<int, 100> stack;
    int i = 0;

    while (i < post.length()) {
        char ch = post[i];

        if (ch == ' ') {
            i++;
            continue;
        }

        if (ch >= '0' && ch <= '9') {
            int num = 0;
            while (i < post.length() && post[i] >= '0' && post[i] <= '9') {
                num = num * 10 + (post[i] - '0');
                i++;
            }
            stack.push(num);
            continue;
        }

        int val2 = stack.pop();
        int val1 = stack.pop();
        int res = 0;

        switch (ch) {
            case '+': res = val1 + val2; break;
            case '-': res = val1 - val2; break;
            case '*': res = val1 * val2; break;
            case '/': res = val1 / val2; break;
        }
        stack.push(res);
        i++;
    }

    return stack.pop();
}
