class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& dest) {

        int n = maze.size();
        int m = maze[0].size();

        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, -1, 0, 1};

        vector<vector<int>> distance(n, vector<int>(m, INT_MAX));

        using State = tuple<int, int, int>;
        priority_queue<State, 
            vector<State>,
            greater<State>> minh;
        
        minh.push({0, start[0], start[1]});
        distance[start[0]][start[1]] = 0;

        while(!minh.empty()){
            auto [currDist, row, col] = minh.top();
            minh.pop();

            if(row==dest[0] && col==dest[1]) return currDist;

            if(currDist > distance[row][col]) continue;

            for(int i=0;i<4;i++){
                int nr = row;
                int nc = col;
                int steps = 0;

                while(true){
                    int nextRow = nr + dx[i];
                    int nextCol = nc + dy[i];

                    if(nextRow < 0 || nextRow >= n || nextCol < 0 || nextCol >= m || maze[nextRow][nextCol]==1){
                        break;
                    }

                    steps++;
                    nr = nextRow;
                    nc = nextCol;
                }

                // if(nr==dest[0] && nc==dest[1]) break;

                if(steps==0) continue;

                int newDist = currDist + steps;

                if(newDist < distance[nr][nc]){
                    distance[nr][nc] = newDist;
                    minh.push({newDist, nr, nc});
                }
            }
        }
        return -1;
    }
};