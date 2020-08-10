class Solution {
public:
    bool divisorGame(int N) {
        return playGame(N, true);
    }

    bool playGame(int N, bool player) {

        if (N == 1) {
            return !player;
        }

        // for (int i=sqrt(N); i>0; i--) {
        //     if (N % i == 0) {
        //         return playGame(N-i, !player);
        //     }
        // }

        return playGame(N-1, !player);

        return true;
    }
};
