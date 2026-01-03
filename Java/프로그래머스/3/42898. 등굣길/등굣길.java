class Solution {
    int div = 1000000007;
    public int solution(int m, int n, int[][] puddles) {
        int answer = 0;
        int[][] DP = new int[m+1][n+1];
        boolean[][] pud = new boolean[m+1][n+1];
        
        for(int[] p: puddles){
            pud[p[0]][p[1]] = true;
        }
        for(int i=1;i<=m;i++){
            DP[i][1] = 1;
        }
        for(int i=1;i<=n;i++){
            DP[0][1] = 1;
        }
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                int l = !pud[i-1][j]?DP[i-1][j]:0;
                int t = !pud[i][j-1]?DP[i][j-1]:0;
                DP[i][j] = (l + t)%div;
            }
        }       
        
        
        
        return DP[m][n];
    }
}