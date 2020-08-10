class Solution {
public:
    vector<string> letterCombinations(string digits) {
        
        if (!digits.size()) {
            return vector<string>();
        }

        string numsToChar[8][3] = {{"a", "b", "c"},
                            {"d", "e", "f"},
                            {"g", "h", "i"},
                            {"j", "k", "l"},
                            {"m", "n", "o"},
                            {"p", "q", "r"},
                            {"t", "u", "v"},
                            {"w", "x", "y"}};
        
        vector<vector<string>> maps;
        for (int i=0; i<8; i++) {
            maps.push_back( vector<string>(numsToChar[i], numsToChar[i]+3) );
        }
        maps[5].push_back("s");
        maps[7].push_back("z");

        queue<string> q;
        q.push("");

        for (int i=0; i<digits.size(); i++) {
            int size = q.size();

            while(size) {
                string top = q.front();
                q.pop();

                for (int j=0; j<maps[digits[i]-'2'].size(); j++) {
                    q.push( top + maps[digits[i]-'2'][j] );
                }

                size--;
            }
        }

        vector<string> v(q.size(), "");
        int ptr = 0;
        while( !q.empty() ) {
            string ele = q.front();
            q.pop();

            v[ptr++] = ele;
        }

        return v;
    }
};
