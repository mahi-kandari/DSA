class Solution {
public:
    void solve(unordered_map<char,string>& m, string& digits, string& temp, int ind, vector<string>& ans){
        if(ind == digits.size()){
            ans.push_back(temp);
            return;
        }

        string s = m[digits[ind]];

        for(int i = 0; i < s.size(); i++){
            temp.push_back(s[i]);
            solve(m, digits, temp, ind + 1, ans);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {

        vector<string> ans;

        if(digits.empty()) return ans;

        unordered_map<char,string> m;

        m['2'] = "abc";
        m['3'] = "def";
        m['4'] = "ghi";
        m['5'] = "jkl";
        m['6'] = "mno";
        m['7'] = "pqrs";
        m['8'] = "tuv";
        m['9'] = "wxyz";
        string temp = "";

        solve(m, digits, temp, 0, ans);

        return ans;
    }
};