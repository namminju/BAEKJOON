import java.util.*;

class Solution {
    public static final int[] dx = {0, 0, 1, -1};
    public static final int[] dy = {1, -1, 0, 0};
    public int solution(int[][] maps) {
        int answer = -1;
        Deque<int[]> deque = new ArrayDeque<>();
        boolean[][] visited = new boolean[maps.length][maps[0].length];
        
        deque.addLast(new int[]{0, 0, 1});//x좌표, y좌표, dep
        visited[0][0] = true;
        
        while(!deque.isEmpty()){
            int[] now = deque.removeFirst();
            
            if(now[0]==maps.length-1 && now[1]==maps[0].length-1){
                answer = now[2];
                break;
            }
            
            for(int i=0;i<4;i++){
                int nx = now[0] + dx[i];
                int ny = now[1] + dy[i];
                
                // 맵에 해당하지 않는 위치는 검사x
                if(nx < 0 || ny < 0 || nx >= maps.length || ny >= maps[0].length){
                    continue;
                }
                
                if(maps[nx][ny]==1 && !visited[nx][ny]){
                    deque.addLast(new int[]{nx, ny, now[2] + 1});
                    visited[nx][ny] =true;
                }
            }
            
        }
        
        return answer;
    }
}
 