import java.util.*;

class Solution {        
    PriorityQueue<int[]> scores = new PriorityQueue<>((a, b) -> {
            if(a[0] != b[0]) {return a[0]-b[0];}//오름차순
            return a[1]-b[1];//오름차순
        }
    );
    public int[] solution(int target) {
        int[] answer = {};
        int[][] dp = new int[target+1][2];
        for(int[] d:dp){
            d[0] = 999999;
        }
        // 불
        scores.add(new int[]{50, 1});
        
        for(int i=1; i<=3; i++){
            for(int j=1;j<=20;j++){
                int num = i*j;
                
                //싱글
                int sum = 0;
                if(i==1) sum = 1;
                
                scores.add(new int[]{num, sum});
            }
        }
        
        dp[0] = new int[]{0, 0};
        
        for(int i=1;i<=target;i++){
            PriorityQueue<int[]> tmp_s = new PriorityQueue<>(scores);
            while(!tmp_s.isEmpty()){
                int[] s = tmp_s.poll();
                
                if(s[0]>i)break;
                
                int[] tmp = new int[]{dp[i-s[0]][0]+1, dp[i-s[0]][1]+s[1]};
                
                if(tmp[0]<dp[i][0]) dp[i] = tmp;
                else if(tmp[0]==dp[i][0] && tmp[1]>dp[i][1]) dp[i] = tmp;
            }
        }
         
        
        answer = dp[target];
        return answer;
    }
}