class Solution {
public:
    string findShortestWay(
        vector<vector<int>>& maze,
        vector<int>& ball,
        vector<int>& hole
    ) {
        int rows = maze.size();
        int cols = maze[0].size();

        // Lexicographical order: d < l < r < u
        vector<int> dr = {1, 0, 0, -1};
        vector<int> dc = {0, -1, 1, 0};
        vector<char> directions = {'d', 'l', 'r', 'u'};

        // distance[r][c] = minimum distance needed to reach this position
        vector<vector<int>> distance(
            rows,
            vector<int>(cols, INT_MAX)
        );

        // bestPath[r][c] = lexicographically smallest path
        // among all paths having minimum distance
        vector<vector<string>> bestPath(
            rows,
            vector<string>(cols, "")
        );

        /*
            Priority queue state:

            {
                distance travelled,
                path string,
                row,
                column
            }

            greater<> makes it a min-heap.

            It first compares distance.
            If distances are equal, it compares path strings.
        */
        using State = tuple<int, string, int, int>;

        priority_queue<
            State,
            vector<State>,
            greater<State>
        > minHeap;

        int startRow = ball[0];
        int startCol = ball[1];

        distance[startRow][startCol] = 0;
        bestPath[startRow][startCol] = "";

        minHeap.push({0, "", startRow, startCol});

        while (!minHeap.empty()) {
            auto [currentDistance, currentPath, row, col] =
                minHeap.top();

            minHeap.pop();

            // Ignore outdated states.
            if (currentDistance > distance[row][col]) {
                continue;
            }

            if (currentDistance == distance[row][col] &&
                currentPath > bestPath[row][col]) {
                continue;
            }

            // Since Dijkstra gives the smallest state first,
            // reaching the hole means this is the required answer.
            if (row == hole[0] && col == hole[1]) {
                return currentPath;
            }

            // Try rolling in all four directions.
            for (int i = 0; i < 4; i++) {
                int nextRow = row;
                int nextCol = col;
                int steps = 0;

                // Keep rolling until the next cell is invalid,
                // is a wall, or the ball reaches the hole.
                while (true) {
                    int newRow = nextRow + dr[i];
                    int newCol = nextCol + dc[i];

                    // Stop if next position is outside the maze
                    // or contains a wall.
                    if (newRow < 0 || newRow >= rows ||
                        newCol < 0 || newCol >= cols ||
                        maze[newRow][newCol] == 1) {
                        break;
                    }

                    nextRow = newRow;
                    nextCol = newCol;
                    steps++;

                    // The ball falls into the hole immediately.
                    if (nextRow == hole[0] &&
                        nextCol == hole[1]) {
                        break;
                    }
                }

                // Ball did not move in this direction.
                if (steps == 0) {
                    continue;
                }

                int newDistance = currentDistance + steps;
                string newPath = currentPath + directions[i];

                // Update if:
                // 1. We found a shorter route.
                // 2. Distance is equal, but path is lexicographically smaller.
                if (newDistance < distance[nextRow][nextCol] || (newDistance == distance[nextRow][nextCol] &&
                    (bestPath[nextRow][nextCol].empty() || newPath < bestPath[nextRow][nextCol]))) 
                    {

                        distance[nextRow][nextCol] = newDistance;
                        bestPath[nextRow][nextCol] = newPath;

                        minHeap.push({
                            newDistance,
                            newPath,
                            nextRow,
                            nextCol
                        });
                }
            }
        }

        return "impossible";
    }
};