class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> s;
        for (char &c: num) {
            while (!s.empty() && s.top()>c && k>0 ) {
                s.pop();
                k--;
            }
            s.push(c);
        }
        int cnt = s.size();
        vector<char> ans(cnt, ' ');
        for (int i=0; i<cnt; i++) {
            char c = s.top();
            s.pop();
            ans[cnt-1-i] = c;
        }
        stringstream ss;
        string ret;
        int prefix;
        for (prefix=0; prefix<cnt-k; prefix++) {
            if (ans[prefix]!='0') break;
        }
        for (int i=prefix; i<cnt-k; i++) {
            ss << ans[i];
        }
        ss >> ret;
        return ret == "" ? "0" : ret;
    }
};
