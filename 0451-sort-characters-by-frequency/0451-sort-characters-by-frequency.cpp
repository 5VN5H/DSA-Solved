class Solution {
public:
    static bool cmp(pair<char,int>& a, pair<char,int>& b) {
        return a.second>b.second;
    }
    string frequencySort(string s) {
        unordered_map<char,int>freq;
        for(auto x:s){
            freq[x]++;
        }
        vector<pair<char,int>> vec;

        for(auto it : freq)
        {
            vec.push_back(it);
        }

        sort(vec.begin(), vec.end(), cmp);

        string ans = "";

        for(auto p : vec)
        {
            ans.append(p.second, p.first);
        }

        return ans;
    }
};