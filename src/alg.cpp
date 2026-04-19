// Copyright 2025 NNTU-CS
#include <string>
#include <cctype>
#include "tstack.h"

std::string infx2pstfx(const std::string& inf) {
  TStack<char, 100> operators;
  std::string result;

  for (size_t i = 0; i < inf.length(); ++i) {
    char c = inf[i];

    if (c == ' ') {
      continue;
    }

    if (isdigit(c)) {
      while (i < inf.length() && isdigit(inf[i])) {
        result += inf[i];
        ++i;
      }
      result += ' ';
      --i;
    } else if (c == '(') {
      operators.push(c);
    } else if (c == ')') {
      while (!operators.isEmpty() && operators.top() != '(') {
        result += operators.pop();
        result += ' ';
      }
      if (!operators.isEmpty() && operators.top() == '(') {
        operators.pop();
      }
    } else if (c == '+' || c == '-' || c == '*' || c == '/') {
      int priority = 0;
      if (c == '+' || c == '-') {
        priority = 1;
      } else if (c == '*' || c == '/') {
        priority = 2;
      }

      while (!operators.isEmpty() && operators.top() != '(') {
        char top = operators.top();
        int topPriority = 0;
        if (top == '+' || top == '-') {
          topPriority = 1;
        } else if (top == '*' || top == '/') {
          topPriority = 2;
        }

        if (topPriority >= priority) {
          result += operators.pop();
          result += ' ';
        } else {
          break;
        }
      }
      operators.push(c);
    }
  }

  while (!operators.isEmpty()) {
    result += operators.pop();
    result += ' ';
  }

  if (!result.empty() && result.back() == ' ') {
    result.pop_back();
  }

  return result;
}

int eval(const std::string& post) {
  TStack<int, 100> values;

  for (size_t i = 0; i < post.length(); ++i) {
    char c = post[i];

    if (c == ' ') {
      continue;
    }

    if (isdigit(c)) {
      int number = 0;
      while (i < post.length() && isdigit(post[i])) {
        number = number * 10 + (post[i] - '0');
        ++i;
      }
      values.push(number);
      --i;
    } else if (c == '+' || c == '-' || c == '*' || c == '/') {
      int b = values.pop();
      int a = values.pop();
      int result = 0;

      if (c == '+') {
        result = a + b;
      } else if (c == '-') {
        result = a - b;
      } else if (c == '*') {
        result = a * b;
      } else if (c == '/') {
        result = a / b;
      }
      values.push(result);
    }
  }

  return values.pop();
}
