import java.util.*;

class Solution {
    Set<String> gem = new HashSet<>();
    int[] answer = new int[2];
    Map<String, Integer> map = new HashMap<>();
    int total = 0;

    public int[] solution(String[] gems) {
        int n = gems.length;

        for (String g : gems) gem.add(g);
        total = gem.size();

        // 초기값: 최악 길이
        answer[0] = 1;
        answer[1] = n;

        int s = 0, e = 0;
        int kind = 1;
        map.put(gems[0], 1);

        while (true) {
            // 현재 구간이 모든 종류 포함이면 갱신
            if (kind == total && (e - s) < (answer[1] - answer[0])) {
                answer[0] = s + 1;
                answer[1] = e + 1;
            }

            // e가 끝이면 더 확장 불가 -> 종료
            if (e == n - 1) break;

            // 확장
            e++;
            int in = map.getOrDefault(gems[e], 0);
            if (in == 0) kind++;
            map.put(gems[e], in + 1);

            // 축소
            while (s < e && map.get(gems[s]) > 1) {
                map.put(gems[s], map.get(gems[s]) - 1);
                s++;
            }
        }

        return answer;
    }
}
