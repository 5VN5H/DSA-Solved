class Solution {
public:
//typedef pair<int,int> pii;
    using pii = pair<int,int> ;
    struct compare{
        bool operator()(pii a,pii b){
            if(a.first==b.first){
                return a.second>b.second;
            }
            return a.first>b.first;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;

        for(auto x: nums){
            mp[x]++;
        }

        priority_queue<pii,vector<pii>,compare>pq;

        for(auto it :mp){
            int ele = it.first;
            int freq = it.second;

            pq.push({freq,ele});

            if(pq.size()>k){
                pq.pop();
            }
        }

        vector<int>ans;

        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;

    }
};