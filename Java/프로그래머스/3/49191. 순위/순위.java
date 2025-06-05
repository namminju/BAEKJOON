class Solution {
    public int solution(int n, int[][] results) {
        int answer = 0;
        int[][] grid = new int[n][n];
        
        for(int[] r:results){
            int a=r[0]-1;
            int b=r[1]-1;
            
            grid[a][b]=1;
            grid[b][a]=-1;
        }
        
        for(int k=0;k<n;k++){
            for(int s=0;s<n;s++){
                for(int e=0;e<n;e++){
                    if(grid[s][k]==1 && grid[k][e]==1){
                        grid[s][e]=1;
                    }else if(grid[s][k]==-1 && grid[k][e]==-1){
                        grid[s][e]=-1;
                    }
                }
            }
        }
        
        for(int i=0;i<n;i++){
            boolean can = true;
            for(int j=0;j<n;j++){
                if(i!=j && grid[i][j]==0){
                    can = false;
                    break;
                }
            }
            if(can){
                answer++;
            }
        }
        return answer;
    }
}