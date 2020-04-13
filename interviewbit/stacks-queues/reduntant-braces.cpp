int Solution::braces(string A) {
    stack <char> s;
    int cnt; // To count no. of operators lying between braces
    char x;
    for (auto it:A) {
        if (it != ')')
        s.push(it);
        else if (it == ')') {
            cnt=0;
            while (!s.empty()) {
                x = s.top();
                if (x == '+' || x== '-' || x== '*' || x== '/') cnt++;
                s.pop();
                if (x== '(') {
                    if (cnt == 0) return 1; // If no operators present between braces
                    break;
                }
            }
        }
    }
    return 0;
}
