class Solution {
    boolean[][] visited;
    int count=0;
    public boolean isPossible(int x, int y, int n){
        for(int i=0;i<n;i++){
            if(visited[x][i] || visited[i][y]){
                return false;
            }
        }
        for(int i=1;x-i>=0 && y-i>=0;i++){//왼 위
            if(visited[x-i][y-i]){
                return false;
            }
        }
        for(int i=1;x+i<n && y+i<n;i++){//오 아래
            if(visited[x+i][y+i]){
                return false;
            }
        }
        for(int i=1;x+i<n && y-i>=0;i++){//오 위
            if(visited[x+i][y-i]){
                return false;
            }
        }
        for(int i=1;x-i>=0 && y+i<n;i++){//왼 아래
            if(visited[x-i][y+i]){
                return false;
            }
        }
        return  true;
    }
    public void dfs(int n, int x){
        if(x==n){
            count++;
            return;
        }
        for(int i=0;i<n;i++){
            if(isPossible(x, i, n)){//놓을 수 있으면
                visited[x][i] = true;
                dfs(n, x+1);
                visited[x][i] = false;
            }       
        }

    }
    public int solution(int n) {
        int answer = 0;
        visited = new boolean[n][n];
        dfs(n, 0);
        return count;
    }
}