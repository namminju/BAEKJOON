class Solution {
    int[] dx = {0, -1, 1, 0};
    int[] dy = {1, 0, 0, -1};
    char[] ds = {'d', 'l', 'r', 'u'};

    boolean find = false;
    int n, m, r, c, k;
    String answer = "";
    StringBuilder path = new StringBuilder();

    void dfs(int x, int y, int cnt) {
        if (find) return;

        int dist = Math.abs(r - x) + Math.abs(c - y);
        int remain = k - cnt;

        // 핵심 가지치기
        if (dist > remain) return;
        if (((remain - dist) & 1) == 1) return;

        if (cnt == k) {
            if (x == r && y == c) {
                find = true;
                answer = path.toString();
            }
            return;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dy[i];
            int ny = y + dx[i];
            if (nx < 1 || ny < 1 || nx > n || ny > m) continue;

            path.append(ds[i]);
            dfs(nx, ny, cnt + 1);
            path.deleteCharAt(path.length() - 1);

            if (find) return;
        }
    }

    public String solution(int n, int m, int x, int y, int r, int c, int k) {
        this.n = n; this.m = m; this.r = r; this.c = c; this.k = k;

        int dist0 = Math.abs(r - x) + Math.abs(c - y);
        if (dist0 > k || ((k - dist0) & 1) == 1) return "impossible";

        dfs(x, y, 0);
        return find ? answer : "impossible";
    }
}
