class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp;
        vector<int> res;
        for(auto it:nums){
            mp[it]++;
        }
        
        priority_queue<pair<int,int>>pq;
           for (auto i : mp)
          pq.push(make_pair(i.second, i.first));
        
        for(int i=0;i<k;i++){
            res.push_back(pq.top().second);
            pq.pop();
        }
             return res;
    }
};