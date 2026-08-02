class Solution {
public:
    int countGoodSubstrings(string s) {
        int st =0;
        int en =0;
        int count = 0;
        while(en<s.size()){
            if(en-st+1==3){
                char a = s[st];
                char b = s[st+1];
                char c = s[en];
                if(a!=b&&b!=c&&c!=a){
                    count++;
                }
                st++;
            }
            en++;
        }
        return count;
    }
};