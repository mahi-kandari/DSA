class Solution {
public:
    int solve(string &word1, string &word2, int ind1, int ind2, vector<vector<int>> &rec) {
        if (ind1 == word1.size()) return word2.size() - ind2;
        if (ind2 == word2.size()) return word1.size() - ind1;
        
        if (rec[ind1][ind2] != -1) return rec[ind1][ind2];
        
        int same = 1e8, insert = 1e8, del = 1e8, rep = 1e8;
        
        if (word1[ind1] == word2[ind2]) {
            same = solve(word1, word2, ind1 + 1, ind2 + 1, rec);
        } else {
            insert = 1 + solve(word1, word2, ind1, ind2 + 1, rec);
            del = 1 + solve(word1, word2, ind1 + 1, ind2, rec);
            rep = 1 + solve(word1, word2, ind1 + 1, ind2 + 1, rec);
        }
        
        return rec[ind1][ind2] = min({insert, del, rep, same});
    }

    int minDistance(string word1, string word2) {
        vector<vector<int>> rec(word1.size(), vector<int>(word2.size(), -1));
        return solve(word1, word2, 0, 0, rec);
    }
};