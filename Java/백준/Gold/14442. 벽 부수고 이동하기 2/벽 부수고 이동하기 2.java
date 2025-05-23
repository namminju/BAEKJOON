import java.io.*;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Deque;

public class Main {
    public static final int[] dx = {0, 0,  -1, 1};
    public static final int[] dy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int[] input = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        //input - 0: 줄, 1: 개수(줄 별), 2: 벽 부수기 가능 횟수
        int[][] grid = new int[input[0]][input[1]];

        boolean[][][] visited = new boolean[input[0]][input[1]][input[2]+1];
        //세로, 가로, 부순 횟수

        boolean isPossible = false;

        for (int i = 0; i < input[0]; i++) {
            grid[i] = Arrays.stream(br.readLine().split("")).mapToInt(Integer::parseInt).toArray();

        }

        Deque<int[]> deque = new ArrayDeque<>();
        // Y, X, 이동 거리, 부순 횟수
        deque.addLast(new int[]{0, 0, 1, 0});
        visited[0][0][0] = true;

        while(!deque.isEmpty()) {
            int[] now = deque.removeFirst();

            int x = now[0], y = now[1], dep = now[2], bNum=now[3];

            if(x==input[0]-1 && y==input[1]-1) {
                bw.write(String.valueOf(dep));
                isPossible = true;
                break;
            }

            for(int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    //불가능한 경우는 Continue
                    if(nx < 0 || ny < 0 || nx >= input[0] || ny >= input[1]){
                        continue;
                    }
//                    System.out.println(nx+","+ny+": "+grid[nx][ny]+ "-->" +bNum);
                    //벽 안부수는 경우 + visited 체크 필요
                    if(grid[nx][ny]==0 && !visited[nx][ny][bNum]){
                        deque.addLast(new int[]{nx, ny, dep+1, bNum});
                        //visited 업데이트
                        visited[nx][ny][bNum] = true;
                    }

                    //벽 부술 수 있는 경우 + visited 체크 필요
                    else if(bNum<input[2] && !visited[nx][ny][bNum+1]){
                        deque.addLast(new int[]{nx, ny, dep+1, bNum+1});
                        //visited 업데이트
                        visited[nx][ny][bNum+1] = true;
                    }
           }

        }
        // 도착지에 도착하지 못한 경우
        if(!isPossible){
            bw.write("-1");
        }

        br.close();
        bw.flush();
        bw.close();
    }
}
