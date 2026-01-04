class Solution {
    public int[] solution(int n, int s) {
        int[] answer = new int[n];
        int plusOne = s%n;
        for(int i=0;i<n-plusOne;i++){
            answer[i] = s/n;
        }
        for(int i=n-plusOne;i<n;i++){
            answer[i] = s/n + 1;
        }
        
        if(answer[0]<1){
            return new int[]{-1};
        }
        return answer;
    }
}