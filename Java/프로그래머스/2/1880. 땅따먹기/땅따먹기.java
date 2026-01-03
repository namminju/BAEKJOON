class Solution {
    int solution(int[][] land) {
        int answer = 0;
        int[][] DP = new int[land.length][4];
        
        for(int i=0;i<4;i++){
            DP[0][i] = land[0][i];
        }
        
        for(int i=1;i<land.length;i++){ 
            for(int k=0;k<4;k++){
                int max = 0;
                for(int j=0;j<4;j++){
                    if(j!=k) max = Math.max(DP[i-1][j], max);
                }
                DP[i][k] = land[i][k] + max;
            }
        }
        
        for(int k=0;k<4;k++){
            answer = Math.max(DP[land.length-1][k], answer);
        }
        return answer;
    }
}