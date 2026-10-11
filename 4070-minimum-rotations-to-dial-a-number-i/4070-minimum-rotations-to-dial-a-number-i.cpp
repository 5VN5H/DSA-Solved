class Solution {
public:
    int minRotations(string s) {
        int ans =0;
        int y= 0;
        for(int i =0;i<s.size();i++){
            int x = s[i]-'0';
            int diff = abs(y-x);
            ans+=min(diff,10-diff);
            y = x;
        }
        return ans;
    }
};