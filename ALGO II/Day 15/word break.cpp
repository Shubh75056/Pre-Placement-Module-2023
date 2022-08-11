class Solution {
public:
    bool find(string s , int start , unordered_map<int,bool> &l1 , unordered_set<string> &l2){
        if(start>=s.length()) return true;
        if(l1.find(start)!=l1.end()) return l1[start];
        int l = s.length();
        string st = "";
        for(int i=start;i<l;i++){
            st+=s[i];
            if(l2.find(st)!=l2.end()){
                if(find(s,i+1,l1,l2)){
                    l1.insert(make_pair(i,true));
                    return true;
                }
            }
        }
        l1.insert(make_pair(start,false));
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<int,bool> l1;
        unordered_set<string> l2;
        for(string s:wordDict) l2.insert(s);
        return find(s,0,l1,l2);
    }
};
