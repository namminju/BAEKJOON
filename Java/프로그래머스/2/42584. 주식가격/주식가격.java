class Solution {
    public int[] solution(int[] prices) {
        int n = prices.length;
        int[] answer = new int[n];
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(prices[i]>prices[j]){
                    answer[i]++;
                    break;
                }
                answer[i]++;
            }
        }
        
        return answer;
    }
}