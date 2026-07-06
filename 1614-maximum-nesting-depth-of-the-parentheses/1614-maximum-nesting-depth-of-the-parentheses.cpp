class Solution {
public:
    int maxDepth(string s) {
        int depth =0;
        int maxdepth = 0;

        for(auto x:s){
            if(x=='('){
                depth++;
                maxdepth = max(depth,maxdepth);
            }
            else if (x==')'){
                depth--;
            }
        }
        return maxdepth;
    }
};