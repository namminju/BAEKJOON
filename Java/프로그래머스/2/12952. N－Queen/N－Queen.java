class Solution {
    int answer = 0;
    boolean[][] visited;
    public void dfs(int n, int x){
        if(x==n){
            answer++;
            return;
        }
        for(int i=0;i<n;i++){
            if(isPossible(x, i, n)){
                visited[x][i] = true;
                dfs(n, x+1);
                visited[x][i] = false;
            }
            
        }
    }
    public boolean isPossible(int x, int y, int n){
        for(int i=0;i<n;i++){
            if(visited[x][i] || visited[i][y]){
                return false;
            }
        }
        for(int i=0; x-i>=0 && y-i>=0 ;i++){
            if(visited[x-i][y-i]){
                return false;
            }
        }
        for(int i=0; x-i>=0 && y+i<n ;i++){
            if(visited[x-i][y+i]){
                return false;
            }
        }
        for(int i=0;x+i<n && y-i>=0 ;i++){
            if(visited[x+i][y-i]){
                return false;
            }
        }
        for(int i=0;x+i<n && y+i<n ;i++){
            if(visited[x+i][y+i]){
                return false;
            }
        }
        return true;

    }
    public int solution(int n) {
        visited = new boolean[n][n];
        dfs(n, 0);
        return answer;
    }
}