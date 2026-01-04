import java.util.*;

class Solution {
    public int solution(int n, int[] stations, int w) {
        int answer = 0;
        int cover = 2 * w + 1;

        int idx = 1; // 아직 커버되지 않은 가장 왼쪽(1-based)

        for (int s : stations) {
            int left = s - w;          // 현재 기지국 커버 시작
            if (left > idx) {          // 빈 구간 존재
                int gap = left - idx;
                answer += (gap + cover - 1) / cover;
            }
            idx = s + w + 1;           // 다음 미커버 시작점
        }

        if (idx <= n) {                // 마지막 꼬리 구간
            int gap = n - idx + 1;
            answer += (gap + cover - 1) / cover;
        }

        return answer;
    }
}
