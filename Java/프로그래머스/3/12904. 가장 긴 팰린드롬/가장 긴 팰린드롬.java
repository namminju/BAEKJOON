class Solution
{
    public int solution(String s)
    {
        int answer = 0;
 
        int left = 0;
        int mid = 0;
        int right = 0;
        
        while(mid!=s.length()){
            left = mid;
            right = mid;
            while (left >= 0 && right < s.length() && s.charAt(left) == s.charAt(right)) {
                left--;
                right++;
            }
            answer = Math.max(right - left - 1, answer);
            
            left = mid;
            right = mid+1;
            while (left >= 0 && right < s.length() && s.charAt(left) == s.charAt(right)) {
                left--;
                right++;
            }
            answer = Math.max(right - left - 1, answer);
            
            mid++; 
        }
       
        
        return answer;
    }
}