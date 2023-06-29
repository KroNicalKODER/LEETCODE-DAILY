class Solution {
public:

    unordered_map<char,int> memo;
    struct VectorHash {
        size_t operator()(const std::vector<int>& v) const {
            size_t seed = v.size();
            for (const int& i : v) {
                seed ^= i + 0x9e3779b9 + (seed << 6) + (seed >> 2);
            }
            return seed;
        }
    };

    int solve(vector<string>& grid ,int x,int y,int k) {
        unordered_map<vector<int>,bool,VectorHash> vis;
        int m = grid.size();
        int n = grid[0].size();
        queue<vector<int>> qu;
        qu.push({0,x,y});
        vis.insert({{0,x,y},1});
        int ans = 0;
        while(!qu.empty()) {
            int sz = qu.size();
            while(sz--){
                auto curr = qu.front();
                qu.pop();
                int i = curr[1];
                int j = curr[2];
                int dx[] = {1,-1,0,0};
                int dy[] = {0,0,1,-1};
                for(int a=0;a<4;a++){
                    int keys = curr[0];
                    int nx = i+dx[a];
                    int ny = j+dy[a];
                    if(nx<0||ny<0||nx>=m||ny>=n) continue;
                    if(grid[nx][ny] == '#') continue;
                    if(grid[nx][ny] == 'a' || grid[nx][ny] == 'b'|| grid[nx][ny] == 'c'|| grid[nx][ny] == 'd'|| grid[nx][ny] == 'e'|| grid[nx][ny] == 'f'){
                        keys |= memo[grid[nx][ny]];
                        if(keys == k) return ans+1;
                    }
                    else if((grid[nx][ny] == 'A' || grid[nx][ny] == 'B'|| grid[nx][ny] == 'C'|| grid[nx][ny] == 'D'|| grid[nx][ny] == 'E'|| grid[nx][ny] == 'F')){
                        if(keys & memo[grid[nx][ny]-'A'+'a']){
                            if(vis.find({keys,nx,ny}) == vis.end()) {
                                vis.insert({{keys,nx,ny},1});
                                qu.push({keys,nx,ny});
                            }
                            continue;
                        } else continue;

                    }
                    if(vis.find({keys,nx,ny}) == vis.end()) {
                        vis.insert({{keys,nx,ny},1});
                        qu.push({keys,nx,ny});
                    }
                }
            }
            ans++;
         }
         
         return -1;
    }

    int shortestPathAllKeys(vector<string>& grid) {
        int stx=0,sty=0;
        memo['a'] = 1;
        memo['b'] = 2;
        memo['c'] = 4;
        memo['d'] = 8;
        memo['e'] = 16;
        memo['f'] = 32;
        int keys = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == '@'){
                    stx = i;
                    sty = j;
                }
                if(grid[i][j] == 'a' || grid[i][j] == 'b'|| grid[i][j] == 'c'|| grid[i][j] == 'd'|| grid[i][j] == 'e'|| grid[i][j] == 'f') keys|=memo[grid[i][j]];
            }
        }
        return solve(grid,stx,sty,keys);
    }
};
