import java.util.*;

class Solution {
    public int[] dx = {0, 0, -1, 1};
    public int[] dy = {-1, 1, 0, 0};
    public boolean[][] visited;
    public int solution(int[][] maps) {
        int answer = -1;
        int n = maps.length;
        int m = maps[0].length;
        
        visited = new boolean[n][m];
        
        Deque<int[]> deque = new ArrayDeque<>();
   
        //x,y, 이동 거리
        deque.add(new int[]{0, 0, 1});
        visited[0][0] = true;
        
        while(!deque.isEmpty()){
            int[] cur = deque.removeFirst();
            
            //System.out.println(cur[0]+"," +cur[1]+": "+cur[2]);
            
            if(cur[0] == n-1 && cur[1] == m-1){
                answer = cur[2];
                break;
            }
            
            for(int i=0;i<4;i++){
                int nx = cur[0] + dx[i];
                int ny = cur[1] + dy[i];
                
                if(nx<0 || nx>=n || ny<0 || ny>=m){
                    continue;
                }
                
                if(!visited[nx][ny] && maps[nx][ny]==1){
                    deque.addLast(new int[]{nx, ny, cur[2]+1});
                    visited[nx][ny] = true;
                }
            }
        }
        return answer;
    }
}

// [1, 0, 1, 1, 1]
// [1, 0, 1, 0, 1]
// [1, 0, 1, 1, 1]
// [1, 1, 1, 0, 1]
// [0, 0, 0, 0, 1]