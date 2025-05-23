import java.io.*;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Deque;

public class Main {
    public static final int[] dx = {0, 0, -1, 1};
    public static final int[] dy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        int answer = 0;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int[] input = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        //0: 세로 수 , 1: 가로 수

        String[][] grid = new String[input[0]][input[1]];
        int[] red = new int[2], blue = new int[2], hole = new int[2];
        for (int i = 0; i < input[0] ; i++) {
            grid[i] = br.readLine().split("");
            for(int j= 0; j < grid[i].length ; j++){
                String s = grid[i][j];
                if(s.equals("R")){
                    red= new int[]{i, j};
                    //빨간공(나가야함)
                }else if(s.equals("B")){
                    blue= new int[]{i, j};
                    //파란공(나가면 안됨)
                } else if (s.equals("O")) {
                    hole= new int[]{i, j};
                    //구멍
                }
            }
        }

        Deque<int[]> deque = new ArrayDeque<>();
        //초기값 넣기, visited update
        // redX, redY, blueX, blueY, depth
        deque.addLast(new int[]{red[0], red[1], blue[0], blue[1], 0});
        //visited update

        while (!deque.isEmpty()){
            int[] cur = deque.removeFirst();
            int rx = cur[0],  ry = cur[1];
            int bx = cur[2], by = cur[3];
            
            //이동 횟수 10 번 이상 제거
            if(cur[4]>=10){
                continue;
            }
            
            for (int i = 0; i <4 ; i++) {
                int nrx = cur[0],  nry = cur[1];
                int nbx = cur[2], nby = cur[3];
                boolean isRed = false;
                boolean isBlue = false;
     
                //빨간공 더는 움직일 수 없을 때까지 이동 + 빨간공 구멍 나가는 여부 판별 필요
                while(true){
                    if(grid[nrx+dx[i]][nry+dy[i]].equals("#")){
                        break;
                    }
                    nrx+=dx[i];
                    nry+=dy[i];

                    if(grid[nrx][nry].equals("O")){
                        isRed = true;
                        break;
                    }
                }
                //파란공 더는 움직일 수 없을 때까지 이동 + 파란공 구멍 나가는 여부 판별 필요
                while(true){
                    if(grid[nbx+dx[i]][nby+dy[i]].equals("#")){
                        break;
                    }

                    nbx+=dx[i];
                    nby+=dy[i];

                    if(grid[nbx][nby].equals("O")){
                        isBlue = true;
                        break;
                    }
                }

                //  파란공 O -> 제외
                if(isBlue){
                    continue;
                }
                //  빨간공 O (&&  파란공 X )-> 정답(answer = 1;) : 정지
                if(isRed){
                    answer = 1;
                    break;
                }
                // 빨간공 X (&&  파란공 X) -> deque에 넣고 반복(visited 확인 필요)
            
                //서로 영향을 받는 경우 고려 필요
                 
                    if(nrx == nbx && nry == nby){
                        if(dx[i]<0){
                            if(rx>bx){
                                nrx++;
                            }else {
                                nbx++;
                            }
                        }else if(dx[i]>0){
                            if(rx>bx){
                                nbx--;
                            }else {
                                nrx--;
                            }
                        } else if (dy[i]<0) {
                            if(ry>by){
                                nry++;
                            }else {
                                nby++;
                            }
                        }else if(dy[i]>0){
                            if(ry>by){
                                nby--;
                            }else {
                                nry--;
                            }
                        }
                    }

                    deque.addLast(new int[]{nrx, nry, nbx, nby, cur[4]+1});
                 
            }
        }
        bw.write(String.valueOf(answer));
        br.close();
        bw.flush();
        bw.close();
    }
}
//visited 로직 추가
//공이 서로 영향을 미치는 경우 고려 필요