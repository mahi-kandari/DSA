class Solution {
public:
    int maxDepth(string s) {
      vector<int> depth(s.length(),0);
      
      for(int i =1;i<s.length();i++){
        int left=0,right=0;
        for(int j=0;j<i;j++){
            if(s[j] =='(') left++;
            else if(s[j] ==')') right++;
            else continue;
        
        }
        depth[i] = left - right;

      }  
      return *max_element(depth.begin(),depth.end());
    }
};