import java.util.*;

class Solution {
    public int[] dx = {0, 0, 1, -1};
    public int[] dy = {1, -1, 0, 0};
    public int n;
    public int[][] map;

    int min = Integer.MAX_VALUE;
    int[][][] cost; // cost[x][y][dir] = 해당 칸에 dir 방향으로 도착한 최소 비용

    public void dfs(int x, int y, int amount, int pre) {
        if (amount >= min) return;

        if (x == n - 1 && y == n - 1) {
            min = Math.min(min, amount);
            return;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= n || map[nx][ny] == 1) {
                continue;
            }

            int nextCost = amount + ((pre == i || pre == -1) ? 100 : 600);

            // (nx, ny)에 i방향으로 도착한 최소비용보다 비싸면 컷
            if (cost[nx][ny][i] <= nextCost) continue;
            cost[nx][ny][i] = nextCost;

            map[nx][ny] = 1;
            dfs(nx, ny, nextCost, i);
            map[nx][ny] = 0;
        }
    }

    public int solution(int[][] board) {
        n = board.length;
        map = board;

        cost = new int[n][n][4];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                Arrays.fill(cost[i][j], Integer.MAX_VALUE);
            }
        }

        // 시작점 방문 처리(되돌아오기 방지)
        map[0][0] = 1;

        dfs(0, 0, 0, -1);

        return min;
    }
}
