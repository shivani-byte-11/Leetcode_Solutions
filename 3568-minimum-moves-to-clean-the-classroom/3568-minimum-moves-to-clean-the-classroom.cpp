class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();
        int sr = 0, sc = 0;
        int litterCount = 0;
        vector<vector<int>> id(m, vector<int>(n, -1));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }
                else if (classroom[i][j] == 'L') {
                    id[i][j] = litterCount++;
                }
            }
        }
        if (litterCount == 0)
            return 0;
        int fullMask = (1 << litterCount) - 1;
        queue<tuple<int, int, int, int>> q;
        q.push({sr, sc, energy, 0});
        vector<vector<vector<vector<bool>>>> visited(
            m,
            vector<vector<vector<bool>>>(
                n,
                vector<vector<bool>>(
                    energy + 1,
                    vector<bool>(1 << litterCount, false)
                )
            )
        );
        visited[sr][sc][energy][0] = true;
        int moves = 0;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto [r, c, e, mask] = q.front();
                q.pop();
                if (mask == fullMask)
                    return moves;
                if (e == 0)
                    continue;
                for (int k = 0; k < 4; k++) {
                    int nr = r + dr[k];
                    int nc = c + dc[k];
                    if (nr < 0 || nr >= m ||
                        nc < 0 || nc >= n ||
                        classroom[nr][nc] == 'X') {
                        continue;
                    }
                    int newEnergy = e - 1;
                    int newMask = mask;
                    if (classroom[nr][nc] == 'R') {
                        newEnergy = energy;
                    }
                    if (classroom[nr][nc] == 'L') {
                        newMask |= (1 << id[nr][nc]);
                    }
                    if (!visited[nr][nc][newEnergy][newMask]) {
                        visited[nr][nc][newEnergy][newMask] = true;
                        q.push({
                            nr,
                            nc,
                            newEnergy,
                            newMask
                        });
                    }
                }
            }
            moves++;
        }
        return -1;
    }
};