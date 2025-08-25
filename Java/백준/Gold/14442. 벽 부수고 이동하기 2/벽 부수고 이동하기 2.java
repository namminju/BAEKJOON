//  Link: https://www.acmicpc.net/problem/14442

import java.io.*;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Deque;

public class Main {
    //상하좌우 이동
    public static int[] dx = {0, 0, 1, -1};
    public static int[] dy = {1, -1, 0, 0};

    //방문여부 배열
    public static boolean[][][] visited;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        //결과값 (방문 불가시 -1)
        int result = -1;

        String input = br.readLine();
        String[] inputArray = input.split(" ");
        // 목적지 (n, m)
        int n = Integer.parseInt(inputArray[0]);
        int m = Integer.parseInt(inputArray[1]);

        //부술 수 있는 벽의 개수
        int k = Integer.parseInt(inputArray[2]);

        int[][] matrix = new int[n][m];
        visited = new boolean[n][m][k + 1];

        for (int i = 0; i < n; i++) {
            int[] line = Arrays.stream(br.readLine().split("")).mapToInt(Integer::parseInt).toArray();
            matrix[i] = line;
        }

        Deque<int[]> deque = new ArrayDeque<>();
        //초기값
        deque.addLast(new int[]{0, 0, 1, 0});
        visited[0][0][0] = true;
        // 위치 n,m ,  이동거리, 파괴한 벽의 수

        while (!deque.isEmpty()) {
            int[] cur = deque.removeFirst();
            if (cur[0] == n - 1 && cur[1] == m - 1) {
                result = cur[2];
                break;
            }
            for (int i = 0; i < 4; i++) {
                int nx = cur[0] + dx[i];
                int ny = cur[1] + dy[i];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
                    continue;
                }
                if (matrix[nx][ny] == 0 && !visited[nx][ny][cur[3]]) {
                    deque.addLast(new int[]{nx, ny, cur[2] + 1, cur[3]});
                    visited[nx][ny][cur[3]] = true;
                } else if (matrix[nx][ny] == 1 && cur[3] < k && !visited[nx][ny][cur[3] + 1]) {
                    deque.addLast(new int[]{nx, ny, cur[2] + 1, cur[3] + 1});
                    visited[nx][ny][cur[3] + 1] = true;
                }
            }

        }
        bw.write(result + "");
        bw.flush();
    }
}
