class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> theStack;
        for (auto c: s) {
            if (c == ')') {
                string medium = "";
                char letter;
                while (true) {
                    letter = theStack.top();
                    theStack.pop();
                    if (letter == '(') {
                        break;
                    }
                    medium += letter;
                }
                for (auto letter: medium) {
                    theStack.push(letter);
                }
            }
            else {
                theStack.push(c);
            }
        }
        string stack2Str = "";
        while (!theStack.empty()) {
            stack2Str += theStack.top();
            theStack.pop();
        }
        string ans = stack2Str;
        for (int i=0; i<ans.size(); i++) {
            ans[i] = stack2Str[ ans.size()-1-i ];
        }
        return ans;
    }
};
