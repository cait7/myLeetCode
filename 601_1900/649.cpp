class Solution {
public:
    string predictPartyVictory(string senate) {
        while (true) {
            for (int i=0; i<senate.size(); i++) {
                char c = senate[i];
                bool valid = false;
                switch (c) {
                    case 'B':
                        break;
                    case 'R':
                        for (int j=0; j<senate.size(); j++) {
                            if (senate[(j+i)%senate.size()] == 'D') {
                                senate[(j+i)%senate.size()] = 'B';
                                valid = true;
                                break;
                            }
                        }
                        if (!valid) {
                            return "Radiant";
                        }
                        break;
                    case 'D':
                        for (int j=0; j<senate.size(); j++) {
                            if (senate[(j+i)%senate.size()] == 'R') {
                                senate[(j+i)%senate.size()] = 'B';
                                valid = true;
                                break;
                            }
                        }
                        if (!valid) {
                            return "Dire";
                        }
                        break;
                }
            }
        }
    }
};
