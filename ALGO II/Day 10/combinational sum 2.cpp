class Solution {
public:
    vector<pair<int,int>> freg;
    vector<vector<int>> ans;
    vector<int> sequence;
    void dfs(int pos,int rest){
        if(rest == 0){
            ans.emplace_back(sequence);
            return;
        }
        if(pos == freg.size() || rest<freg[pos].first){
            return;//After adding the last number, more than the corresponding Target
        }
        dfs(pos+1,rest);

        int most = min(rest/freg[pos].first,freg[pos].second);
        for(int i=1;i<=most;++i){
            sequence.emplace_back(freg[pos].first);
            dfs(pos+1,rest-i*freg[pos].first);
        }
        for(int i=1;i<=most;++i){
            sequence.pop_back();//Restore the site, in order to make it easier for further recursive
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        for(int num:candidates){
            if(freg.empty() || num!=freg.back().first){
                freg.emplace_back(num,1);
            }
            else{
                ++freg.back().second;
            }
        }
        dfs(0,target);
        return ans;
    }
};