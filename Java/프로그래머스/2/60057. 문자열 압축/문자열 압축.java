class Solution {
    public int solution(String s) {
        int minLen = s.length(); // 최대 길이로 초기화

        // 자를 단위: 1 ~ s.length() / 2
        for (int size = 1; size <= s.length() / 2; size++) {
            StringBuilder compressed = new StringBuilder();
            String prev = s.substring(0, size); // 첫 조각
            int count = 1;

            // size 단위로 문자열 자르기
            for (int i = size; i <= s.length(); i += size) {
                // 다음 조각 추출 (범위 초과 방지)
                String current = i + size <= s.length() ? s.substring(i, i + size) : s.substring(i);

                if (prev.equals(current)) {
                    count++; // 반복되는 경우
                } else {
                    // 반복 끝났을 때 압축 문자열 추가
                    if (count > 1) compressed.append(count);
                    compressed.append(prev);
                    prev = current; // 비교 대상 갱신
                    count = 1;
                }
            }

            // 마지막 남은 조각 처리
            if (count > 1) compressed.append(count);
            compressed.append(prev);

            // 최소 길이 갱신
            minLen = Math.min(minLen, compressed.length());
        }

        return minLen;
    }
}
