class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int depth =0;
        for(auto x :s){
            if(x=='('){
                if(depth>=1){
                    ans+=x;
                }
                depth++;
            }
            else{
                depth--;
                if(depth>=1){
                    ans+=x;
                }
            }
        }
        return ans;
    }
};