#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

int apply_op(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return 0;
}

void eval(stack<int>& nums, stack<char>& ops) {
    int b = nums.top(); nums.pop();
    int a = nums.top(); nums.pop();
    char op = ops.top(); ops.pop();
    nums.push(apply_op(a, b, op));
}

int main() {
    string expr;
    getline(cin, expr);

    stack<int> nums;
    stack<char> ops;

    for (size_t i = 0; i < expr.size(); i++) {
        if (isspace(expr[i])) continue;

        if (isdigit(expr[i])) {
            int num = 0;
            while (i < expr.size() && isdigit(expr[i])) {
                num = num * 10 + (expr[i] - '0');
                i++;
            }
            i--;
            nums.push(num);
        } else if (expr[i] == '(') {
            ops.push(expr[i]);
        } else if (expr[i] == ')') {
            while (!ops.empty() && ops.top() != '(') {
                eval(nums, ops);
            }
            if (!ops.empty()) ops.pop(); // pop '('
        } else {
            // operator: + - * /
            while (!ops.empty() && ops.top() != '(' &&
                   precedence(ops.top()) >= precedence(expr[i])) {
                eval(nums, ops);
            }
            ops.push(expr[i]);
        }
    }

    while (!ops.empty()) {
        eval(nums, ops);
    }

    cout << nums.top() << endl;
    return 0;
}
