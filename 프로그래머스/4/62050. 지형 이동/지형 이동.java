import java.util.*;

class Solution {
    //x, y, 이동값
    PriorityQueue<int[]> pq = new PriorityQueue<>(
        (a, b) -> {return a[2] - b[2];}
    );
    
    boolean[][] visited;
    int answer = 0;
    
    int[] dx = new int[]{0, 0, 1, -1};
    int[] dy = new int[]{1, -1, 0, 0};
    
    public int solution(int[][] land, int height) {
        int n = land.length;
        visited = new boolean[n][n];
        
        pq.add(new int[]{0, 0, 0});
        
        while(!pq.isEmpty()){
            int[] cur = pq.remove();
            
            
            if(cur[2] > height && !visited[cur[0]][cur[1]]){
                answer += cur[2];
            }
            
            visited[cur[0]][cur[1]] = true;
            for(int i=0;i<4;i++){
                int nx = cur[0] +dx[i];
                int ny = cur[1] +dy[i];
                
                if(nx<0 || ny<0 || nx>=n || ny>=n){
                    continue;
                }
                
                if(!visited[nx][ny]){
                    pq.add(new int[]{nx, ny, Math.abs(land[nx][ny] - land[cur[0]][cur[1]])});
                }
            }
            
        }
        

        return answer;
    }
}















