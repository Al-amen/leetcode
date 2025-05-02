class Domino {
public:
    void doubleDominoPush(int last_R, int pos, string& dominoes) {
        while (last_R < pos) {
            dominoes[last_R++] = 'R';
            dominoes[pos--] = 'L';
        }
    }
    
    void leftDominoPush(int start, int end, string& dominoes) {
        while (start <= end)
            dominoes[start++] = 'L';
    }
    
    void rightDominoPush(int last_R, int pos, string& dominoes) {
        while (last_R <= pos)
            dominoes[last_R++] = 'R';
    }
};

class Solution {
public:
    string pushDominoes(string dominoes) {
        Domino newDomino;  // Removed 'new' since we're not using pointers
        int last_L = -1, last_R = -1;
        int n = dominoes.size();

        for (int pos = 0; pos < n; pos++) {
            if (dominoes[pos] == 'L') {
                if (last_R > last_L) {
                    newDomino.doubleDominoPush(last_R, pos, dominoes);
                }
                else if ((last_L > last_R) || last_L == -1) {
                    newDomino.leftDominoPush(last_L + 1, pos, dominoes);
                }
                last_L = pos;
            }
            else if (dominoes[pos] == 'R') {
                if (last_R > last_L) {
                    newDomino.rightDominoPush(last_R, pos, dominoes);
                }
                last_R = pos;
            }
        }
        
        // Final case: (R)RR...R(end)
        if (last_R > last_L)
            newDomino.rightDominoPush(last_R, n - 1, dominoes);

        return dominoes;
    }
};