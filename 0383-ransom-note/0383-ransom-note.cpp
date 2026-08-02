class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> need;
        unordered_map<char,int>have;
        for(auto x : ransomNote){
            need[x]++;
        }
        for(auto x : magazine){
            have[x]++;
        }

        for(auto x : need){
            int c = x.first;
            int freqn = x.second;
            int freqh = have[c];
            if(freqn>freqh){
                return false;
            }
            
        }
        return true;
    }
};