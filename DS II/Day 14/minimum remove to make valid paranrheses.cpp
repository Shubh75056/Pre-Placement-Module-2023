class Solution {
public:
    string minRemoveToMakeValid(string S) {
        int len = S.size(), i = 0, j = 0, stIx = 0;
        vector<int> stack;
        for (; i < len; i++)
            if (S[i] == ')')
                if (stack.size() > 0) stack.pop_back();
                else S[i] = '_';
            else if (S[i] == '(') stack.push_back(i);
        stack.push_back(-1);
        for (i = 0; j < len; j++)
            if (j == stack[stIx]) stIx++;
            else if (S[j] != '_') S[i++] = S[j];
        return S.substr(0, i);
    }
};