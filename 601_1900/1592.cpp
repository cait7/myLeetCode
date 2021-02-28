class Solution {
public:
    string reorderSpaces(string text) {
        vector<string> words;
        string word;
        int spaces = 0;
        for (int i=0; i<text.size(); i++) {
            if (text[i] == ' ') {
                spaces++;
                if (word.size() != 0) {
                    words.push_back(word);
                    word = "";
                }
                continue;
            }
            word += text[i];
        }
        if (word.size() != 0) {
            words.push_back(word);
        }
        string ans;
        int between = words.size() == 1 ? spaces : spaces / (words.size() - 1);
        for (int i=0; i<words.size(); i++) {
            ans += words[i];
            int inserts = spaces >= between ? between : spaces;
            spaces -= inserts;
            ans += string(inserts, ' ');
        }
        ans += string(spaces, ' ');
        return ans;
    }
};
