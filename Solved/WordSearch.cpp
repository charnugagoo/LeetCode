//
//  WordSearch.cpp
//  
//
//  Created by 于 卓然 on 13-1-31.
//
// small bug for much time


int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};
class Solution {
public:
    
    bool vis[1000][1000];
    bool dfs(vector<vector<char> > &board, string word, int i, int j, int curr) {
        if(word[curr] != board[i][j]) return false;
        if(curr == word.length() - 1) return true;
        
        vis[i][j] = true;
        int m = board.size(), n = board[0].size();
        bool flag = false;
        for(int dir = 0; dir < 4; ++dir) {
            int x = i + dx[dir], y = j + dy[dir];
            if( x >= 0 && y >= 0 && x < m && y < n && !vis[x][y])
                flag = flag || dfs(board, word, x, y, curr+1);
        }
        vis[i][j] = false;
        return flag;
    }
    bool exist(vector<vector<char> > &board, string word) {
        int l = word.length();
        if(!l) return true;
        int m = board.size();
        if(!m) return false;
        int n = board[0].size();
        if(!n) return false;
        memset(vis, false, sizeof(vis));
        bool flag = false;
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                flag = flag || dfs(board, word, i, j, 0);
        return flag;
    }
};