class Solution {
public:
    string removeKdigits(string num, int k) {
        string st;

        for(auto x : num){
            while(!st.empty()&&k>0&&st.back()>x){
                st.pop_back();
                k--;
            }
            st.push_back(x);
        }

        while(k>0){
            st.pop_back();
            k--;
        }
        int i = 0;
        while(st[i]=='0'&&i<st.size()){
            i++;
        }

        st = st.substr(i);

        if(st.empty()){
            return "0";
        }

        return st;

    }
};