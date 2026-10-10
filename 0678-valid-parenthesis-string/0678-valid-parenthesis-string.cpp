class Solution {
public:
    bool checkValidString(string s) {
        stack<int> opens;
        stack<int> as;
        int n = s.size();

        for(int i=0;i<n;i++){
            if(s[i] =='('){
                opens.push(i);
            }else if(s[i]=='*'){
                as.push(i);
            }else{
                if(!opens.empty()){
                    opens.pop();
                }else{
                    if(!as.empty()){
                        as.pop();
                    }else{
                        return false;
                    }
                }
            }
        }

        while(!opens.empty()&&!as.empty()){
            if(opens.top()>as.top()){
                return false;
            }
            as.pop();
            opens.pop();
        }
        return opens.empty();
    }
};