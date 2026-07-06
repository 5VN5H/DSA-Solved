class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()){
            return false;
        }
        // string temp = s;
        // for(int i =0;i<s.size();i++){
        //     temp = temp.substr(1)+temp[0];
        //     if(temp==goal){
        //         return true;
        //     }
        // }
        // return s==goal;


        string doubled = s+s;

        return doubled.find(goal)!=string::npos;
    }
};