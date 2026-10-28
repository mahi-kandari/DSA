class Trie {
public:
    vector<Trie*> vec;
    bool end;   
    Trie() {
        vec.resize(26, nullptr);
        end = false;
    }   
    void insert(string word) {
        Trie* curr = this;
        for (char c : word) {
            int idx = c - 'a';
            if (curr->vec[idx] == nullptr) {
                curr->vec[idx] = new Trie();
            }
            curr = curr->vec[idx];
        }
        curr->end = true;
    }
};

class Solution {
private:
    void dfs(vector<vector<char>>& board, int i, int j, Trie* curr, string& path, vector<string>& result) {
        char c = board[i][j];
        if (c == '#' || curr->vec[c - 'a'] == nullptr) return;        
        curr = curr->vec[c - 'a'];
        path.push_back(c);
        
        if (curr->end) {
            result.push_back(path);
            curr->end = false; 
        }
        
        board[i][j] = '#';
        
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        for (int d = 0; d < 4; d++) {
            int ni = i + dr[d];
            int nj = j + dc[d];
            if (ni >= 0 && ni < board.size() && nj >= 0 && nj < board[0].size() && board[ni][nj] != '#') {
                dfs(board, ni, nj, curr, path, result);
            }
        }
        
        board[i][j] = c;
        path.pop_back();
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* root = new Trie();
        for (const string& word : words) {
            root->insert(word);
        }       
        vector<string> result;
        int m = board.size();
        int n = board[0].size();        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                string path = "";
                dfs(board, i, j, root, path, result);
            }
        }
        return result;
    }
};