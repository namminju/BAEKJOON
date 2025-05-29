class Solution {
    public int[] solution(int[] sequence, int k) {
        int[] answer = {0,0};
        
        int start = 0;
        int end = 0;
        int sum = sequence[start];
        
        int min = sequence.length;
        
        while(true){
            if(sum==k && min > end - start){
                answer[0] = start;
                answer[1] = end;
                min=end-start;
            }
            
            if(end > sequence.length-1 || start>end){
                break;
            }
            
            if(sum >=k){
                sum-=sequence[start];
                start++;
            }else{
                end++;
                if(end > sequence.length-1){
                    break;
                }
                sum+=sequence[end];
            }
        }
        return answer;
    }
}