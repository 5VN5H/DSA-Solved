class Solution {
public:
    bool isvalid(string&curr){
        int count =0;
        for(auto x :curr){
            if(x == '('){
                count++;
            }else{
                count--;
            }
            if(count<0){
                return false;
            }
        }
        return count==0;
    }
    vector<string> result;
    void solve(string &curr, int n){
        if(curr.length()==2*n){
            if(isvalid(curr)){
                result.push_back(curr);
            }
            return;
        }
        
        curr.push_back('(');
        solve(curr,n);
        curr.pop_back();
        curr.push_back(')');
        solve(curr,n);
        curr.pop_back();
    }
    vector<string> generateParenthesis(int n) {
         string curr ="";
         solve(curr,n);
         return result;
    }
};