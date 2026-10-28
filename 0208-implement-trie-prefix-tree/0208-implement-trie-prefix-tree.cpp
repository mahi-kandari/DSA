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
    
    bool search(string word) {
        Trie* curr = this;
        for (char c : word) {
            int idx = c - 'a';
            if (curr->vec[idx] == nullptr) {
                return false;
            }
            curr = curr->vec[idx];
        }
        return curr->end;
    }
    
    bool startsWith(string prefix) {
        Trie* curr = this;
        for (char c : prefix) {
            int idx = c - 'a';
            if (curr->vec[idx] == nullptr) {
                return false;
            }
            curr = curr->vec[idx];
        }
        return true;
    }
};