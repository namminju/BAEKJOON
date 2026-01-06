class Solution {
    public long solution(int[] sequence) {
        long answer = 0;
        int n = sequence.length;
        int[][] seq  = new int[n][2];
        long[][] DP  = new long[n][2];
        int mul = 1;
        
        for(int i=0;i<n;i++){
            if(i%2==0){mul =1;}else{mul=-1;}
            seq[i][0] =  sequence[i] * mul;
            seq[i][1] =  sequence[i] * mul * -1;
        }
        DP[0][0] = seq[0][0];
        DP[0][1] = seq[0][1];
        answer = Math.max(DP[0][0], DP[0][1]);
        for(int i=1;i<n;i++){
            DP[i][0] = Math.max(seq[i][0], DP[i-1][0] + seq[i][0]);
            DP[i][1] = Math.max(seq[i][1], DP[i-1][1] + seq[i][1]);
            answer = Math.max(answer, Math.max(DP[i][0], DP[i][1]));
        }
        
        return answer;
    }
}