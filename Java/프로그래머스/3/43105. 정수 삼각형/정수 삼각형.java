class Solution {
    public int solution(int[][] triangle) {
        int answer = 0;
        int n=triangle.length;
        int[][] DP = new int[n][]; 
        
        for(int i=0;i<n;i++){
            DP[i] = new int[triangle[i].length];
        }
        
        DP[0][0] = triangle[0][0];
        
        for(int i=1;i<n;i++){
            for(int j=0;j<triangle[i].length;j++){
                int l = j==0?0:DP[i-1][j-1];
                int r =  j==i?0:DP[i-1][j];
                
                DP[i][j] = Math.max(l, r) + triangle[i][j];
            }
        }
    
        for(int j=0;j<triangle[n-1].length;j++){
                answer = Math.max(answer,  DP[n-1][j]);
        }
        return answer;
    }
}