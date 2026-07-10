class Solution {
public:
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {

        int n = maze.size();
        int m = maze[0].size();

        // dlru
        vector<int> dx = {1, 0, 0, -1};
        vector<int> dy = {0, -1, 1, 0};
        vector<char> directions = {'d', 'l', 'r', 'u'};

        vector<vector<int>> distance(n, vector<int>(m, INT_MAX));

        vector<vector<string>> bestPath(n, vector<string>(m, ""));

        using State = tuple<int, string, int, int>;

        priority_queue<State, vector<State>, greater<State>> minh;
        minh.push({0, "", ball[0], ball[1]});
        distance[ball[0]][ball[1]] = 0;
        bestPath[ball[0]][ball[1]] = "";

        while(!minh.empty()){
            auto [currDist, currPath, r, c] = minh.top();
            minh.pop();

            if(r==hole[0] && c==hole[1]) return currPath;

            if(currDist > distance[r][c]) continue;

            if(currDist == distance[r][c] && currPath > bestPath[r][c]) continue;

            for(int i=0;i<4;i++){
                int nextRow = r;
                int nextCol = c;
                int steps = 0;

                while(true){
                    int newRow = nextRow + dx[i];
                    int newCol = nextCol + dy[i];

                    if(newRow < 0 || newRow >= n || newCol < 0 || newCol >= m || maze[newRow][newCol]==1){
                        break;
                    }

                    steps++;
                    nextRow = newRow;
                    nextCol = newCol;

                    if(nextRow==hole[0] && nextCol==hole[1]) break;
                }

                if(steps==0) continue;

                string newPath = currPath + directions[i];
                int newDist = currDist + steps;

                if(newDist < distance[nextRow][nextCol] || (newDist == distance[nextRow][nextCol] && (newPath < bestPath[nextRow][nextCol] || bestPath[nextRow][nextCol].empty()))){
                    distance[nextRow][nextCol] = newDist;
                    bestPath[nextRow][nextCol] = newPath;
                    minh.push({newDist, newPath, nextRow, nextCol});
                }
            }
        }
        return "impossible";
    }
};