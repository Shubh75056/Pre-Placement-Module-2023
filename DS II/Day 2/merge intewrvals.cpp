class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int > > v;
        sort(intervals.begin(), intervals.end());
        
        for(auto i: intervals) {
            int st = i[0], en = i[1];
            
            if(v.size() && st <= v.back()[1]) {
                st = v.back()[0];
                en = max(i[1], v.back()[1]);

                v.pop_back();
            }
            
            v.push_back({st, en});
        }
        
        return v;
    }
};