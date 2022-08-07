class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if (!n) return res;
        string stack, running;
        parenthesisHelper(n, n, stack, running, res);
        return res;
    }
private:
    void parenthesisHelper(int left, int right, string &stack, string &running, vector<string> &combs) {
        if (left == 0 && right == 0) {
            if (stack.empty()) {
                combs.push_back(string(running));
            }
            return;
        }
        if (left) {
            stack.push_back('(');
            running.push_back('(');
            parenthesisHelper(left - 1, right, stack, running, combs);
            stack.pop_back();
            running.pop_back();
        }
        if (right && stack.back() == '(') {
            stack.pop_back();
            running.push_back(')');
            parenthesisHelper(left, right - 1, stack, running, combs);
            stack.push_back('(');
            running.pop_back();
        }
    }
};