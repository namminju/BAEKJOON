class Solution {
    private int linearMax(int[] a, int start, int end) {
        int prev2 = 0; // dp[i-2]
        int prev1 = 0; // dp[i-1]

        for (int i = start; i <= end; i++) {
            int cur = Math.max(prev1, prev2 + a[i]);
            prev2 = prev1;
            prev1 = cur;
        }
        return prev1;
    }

    public int solution(int[] sticker) {
        int n = sticker.length;
        if (n == 1) return sticker[0];

        int case1 = linearMax(sticker, 0, n - 2); // 0 포함 -> n-1 제외
        int case2 = linearMax(sticker, 1, n - 1); // 0 제외 -> n-1 포함 가능

        return Math.max(case1, case2);
    }
}
