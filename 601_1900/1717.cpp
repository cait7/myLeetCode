class Solution {
public:
    int maximumGain(string s, int x, int y) {
        if (x > y) {
            s = reverse(s);
            x = x + y;
            y = x - y;
            x = x - y;
        }
        int ans = 0;
        // 删除 ba
        ans += removeStr(s, 'b', 'a', y);
        ans += removeStr(s, 'a', 'b', x);
        return ans;
    }

    string reverse(string& s) {
        string ans = s;
        for (int i=0; i<ans.size(); i++) {
            ans[i] = s[s.size()-1-i];
        }
        return ans;
    }

    int removeStr(string& str, char first, char second, int reward) {
        stack<char> s;
        int ans = 0;
        for (auto c: str) {
            if (s.empty()) {
                s.push(c);
            }
            else if (c == second && s.top() == first) {
                ans += reward;
                s.pop();
            }
            else {
                s.push(c);
            }
        }
        string s2;
        while(!s.empty()) {
            s2 += s.top();
            s.pop();
        }
        str = reverse(s2);
        return ans;
    }
};
