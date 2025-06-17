import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Deque;

public class Main {
    static int max = 0;
    static Deque<int[]> deque = new ArrayDeque<>();
    static int[] dx={0, 0, 1, -1};
    static int[] dy={1, -1, 0, 0};
    public static int[][]  virusActive(int[][] grid){

        boolean[][] visited = new boolean[grid.length][grid[0].length];
        int[][] temp = new int[grid.length][grid[0].length];
        for (int i = 0; i < grid.length; i++) {
            temp[i] = grid[i].clone();  // 깊은 복사
        }
            Deque<int[]> virus =  new ArrayDeque<>(deque);
            while(!virus.isEmpty()){
                int[] cur =virus.remove();
                visited[cur[0]][cur[1]] = true;

                for(int i=0;i<4;i++){
                    int nx = cur[0]+dx[i];
                    int ny = cur[1]+dy[i];
                    if(nx<0 || ny<0|| nx>=temp.length || ny>=temp[0].length){
                        continue;
                    }
                if(temp[nx][ny]==0&&!visited[nx][ny]){
                        virus.addLast(new int[]{nx,ny});
                        temp[nx][ny]=2;
                        visited[nx][ny]=true;
                    }
                }
            }

            return temp;
    }
    public static void  safe(int[][] grid){
            boolean[][]  visited = new boolean[grid.length][grid[0].length];
            int s = 0;
            for(int i=0;i<grid.length;i++){
                for(int j=0;j<grid[0].length;j++){
                    if(!visited[i][j] && grid[i][j]==0){
                        Deque<int[]> sum =  new ArrayDeque<>();

                        sum.addLast(new int[]{i,j});
                        visited[i][j] = true;
                        while(!sum.isEmpty()){
                            int[] cur =sum.remove();
                            s++;
                            for(int in=0;in<4;in++){
                                int nx = cur[0]+dx[in];
                                int ny = cur[1]+dy[in];
                                if(nx<0 || ny<0|| nx>=grid.length || ny>=grid[0].length){
                                    continue;
                                }
                                if(grid[nx][ny]==0 && visited[nx][ny]==false){
                                    sum.addLast(new int[]{nx,ny});
                                    visited[nx][ny] = true;
                                }
                            }
                        }

                        max=Math.max(max, s);
                    }
                }
            }
    }

    public static void backTracking(int[][] grid, int n){
        if(n==3){

            int[][] virusGrid = virusActive(grid);
            safe(virusGrid);
            return;
        }
        for(int i=0;i<grid.length;i++){
            for(int j=0;j<grid[0].length;j++){
                if(grid[i][j]==0){
                    grid[i][j]=1;
                    backTracking(grid,n+1);
                    grid[i][j]=0;
                }
            }
        }
    }
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int[] n = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        int[][] grid = new int[n[0]][];
        for (int i = 0; i < n[0]; i++) {
            grid[i] = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
            for (int j = 0; j < grid[i].length; j++) {
                if(grid[i][j]==2){
                    deque.add(new int[]{i,j});
                }
            }
        }
        backTracking(grid, 0);
        bw.write(String.valueOf(max));

        br.close();
        bw.flush();
        bw.close();
    }
}
