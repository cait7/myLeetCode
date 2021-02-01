class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> s, t;

        for (int i=0; i<S.size(); i++) {
            if (S[i] == '#' && s.size() != 0) s.pop();

            if (S[i] != '#') s.push(S[i]);
        }

        for (int i=0; i<T.size(); i++) {
            if (T[i] == '#' && t.size() != 0) t.pop();

            if (T[i] != '#') t.push(T[i]);
        }

        while (s.size() > 0 && t.size() > 0) {
            char a = s.top(), b = t.top();

            if (a != b) return false;
            
            s.pop();
            t.pop();
        }

        return s.size() == t.size();
    }
};
