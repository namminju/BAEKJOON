import java.util.*;

class Solution {
    PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> {
        if (a[0] == b[0]) return Integer.compare(a[1], b[1]);
        return Integer.compare(a[0], b[0]);
    });

    public int solution(int[][] routes) {
        int answer = 0;

        for (int[] r : routes) pq.add(r);

        int fin;
        int[] cur = pq.poll();              // 첫 구간 꺼냄

        while (cur != null) {               // ✅ 마지막 그룹까지 처리
            fin = cur[1];
            answer++;

            // ✅ “다음 구간”이 현재 fin과 겹치면 같은 카메라로 커버 가능
            while (!pq.isEmpty() && pq.peek()[0] <= fin) {
                cur = pq.poll();
                fin = Math.min(fin, cur[1]);
            }

            // 다음 그룹 시작
            cur = pq.isEmpty() ? null : pq.poll();
        }

        return answer;
    }
}
