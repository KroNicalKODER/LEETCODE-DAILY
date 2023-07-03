class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int sw=0;
        int n = s.length();
        if(n!=goal.length()) return false;

        if(s==goal){
            vector<bool> vis(27,0);
            for(auto itr : s){
                if(vis[itr-'a'] == true) return true;
                vis[itr-'a'] = true;
            }
            return false;
        }

        int miss1=-1,miss2=-1;

        for(int i=0;i<n;i++){
            if(s[i] != goal[i]) {
                if(miss1==-1) miss1=i;
                else if(miss2==-1) miss2=i;
                else return false;
            }
        }

        if(miss1==-1 || miss2==-1) return false;

        swap(s[miss1],s[miss2]);
        if(s==goal) return true;
        return false;
    }
};
