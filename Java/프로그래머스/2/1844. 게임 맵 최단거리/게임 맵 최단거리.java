import java.util.*; 

class Solution {
    public static final int[] dx = {0, 0, 1, -1};
    public static final int[] dy = {1, -1, 0, 0};
    
    public int solution(int[][] maps) {
        int answer = -1;
        int n = maps.length;
        int m = maps[0].length;
        
        boolean[][] visited = new boolean[n][m];
        
        Deque<int[]> deque = new ArrayDeque<>();
        
        deque.addLast(new int[]{0, 0, 1});
        visited[0][0] = true;
                      
        while(!deque.isEmpty()){
            int[] cur = deque.removeFirst();
            
            if(cur[0]==n-1 && cur[1]==m-1){
                answer = cur[2];
                break;
            }
            
            for(int i=0;i<4;i++){
                int nx = cur[0] + dx[i];
                int ny = cur[1] + dy[i];
                
                if(nx<0 || ny<0 || nx>=n || ny>=m){
                    continue;
                }
                
                if(maps[nx][ny]==1 && !visited[nx][ny]){
                    deque.addLast(new int[]{nx, ny, cur[2]+1});
                    visited[nx][ny]=true;
                }
            }
            
        }
        
        return answer;
    }
}