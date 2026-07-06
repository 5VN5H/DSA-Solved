class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()){
            return false;
        }
        int freq[26]={0};

        for(auto x:s){
            freq[x-'a']++;
        }
        for(auto x:t){
            freq[x-'a']--;
        }
        for(int i =0; i<26; i++){
            if(freq[i]!=0){
                return false;
            }
        }
        return true;
    }
};