class Solution {
    public int solution(int[] arr) {
        int answer = 1;
        
        for(int i=2;i<=100;i++){
            int ch = 0;
            int[] arr2 = new int[arr.length];
            for(int j=0;j<arr.length;j++){
                if(arr[j]%i==0){
                    ch++;
                    arr2[j] = arr[j]/i;
                }else{
                    arr2[j] = arr[j];
                }
            }
            if(ch>=2){
                answer*=i;
                arr = arr2;
                i--;
            } 
        }
        for(int j=0;j<arr.length;j++){ 
            answer*=arr[j];
        }
        
        
        return answer;
    }
}