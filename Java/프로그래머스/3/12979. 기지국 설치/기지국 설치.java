import java.util.*;

class Solution {
    public int solution(int n, int[] stations, int w) {
        int answer = 0;

        //Arrays.sort(stations);
        List<Integer> gap = new ArrayList<>();

        int i = 1;
        for (int s : stations) {
            int left = s - w;
            if (left > i) gap.add(left - i);
            i = s + w + 1;
        }

        if (i <= n) gap.add(n - i + 1);

        int cover = 2 * w + 1;
        for (int g : gap) {
            answer += (g + cover - 1) / cover;
        }
        return answer;
    }
}
