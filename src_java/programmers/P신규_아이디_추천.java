package programmers;

public class P신규_아이디_추천 {
    static boolean isValidChar(char c) {
        if('a' <= c && c <= 'z') return true;
        if('0' <= c && c <= '9') return true;
        if('-' == c || '_' == c || '.' == c) return true;
        return false;
    }

    static String solution(String new_id) {
        //1단계 new_id의 모든 대문자를 대응되는 소문자로 치환합니다.
        new_id = new_id.toLowerCase();

        String temp = "";
        //2단계 new_id에서 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.)를 제외한 모든 문자를 제거합니다.
        for(int i = 0; i < new_id.length(); i++) {
            if(isValidChar(new_id.charAt(i))) {
                temp += new_id.charAt(i);
            }
        }

        String ans = "";
        //3단계 new_id에서 마침표(.)가 2번 이상 연속된 부분을 하나의 마침표(.)로 치환합니다.
        for(int i = 0; i < temp.length(); i++) {
            if(temp.charAt(i) == '.' && i != temp.length() - 1) {
                if(temp.charAt(i+1) != '.') {
                    ans += temp.charAt(i);
                }
            } else {
                ans += temp.charAt(i);
            }
        }

        //4단계 new_id에서 마침표(.)가 처음이나 끝에 위치한다면 제거합니다.
        if(ans.startsWith(".")) {
            ans = ans.substring(1, ans.length());
        }

        if(ans.endsWith(".")) {
            ans = ans.substring(0, ans.length() - 1);
        }

        //5단계 new_id가 빈 문자열이라면, new_id에 "a"를 대입합니다.
        if(ans.isBlank()) {
            ans += "a";
        }

        //6단계 new_id의 길이가 16자 이상이면, new_id의 첫 15개의 문자를 제외한 나머지 문자들을 모두 제거합니다.
        //만약 제거 후 마침표(.)가 new_id의 끝에 위치한다면 끝에 위치한 마침표(.) 문자를 제거합니다.
        if(ans.length() >= 16) {
            ans = ans.substring(0, 15);
        }
        if(ans.endsWith(".")) {
            ans = ans.substring(0, 13);
        }

        //7단계 new_id의 길이가 2자 이하라면, new_id의 마지막 문자를 new_id의 길이가 3이 될 때까지 반복해서 끝에 붙입니다.
        if(ans.length() <= 2) {
            String str = ans.charAt(ans.length() - 1) + "";
            if(ans.length() == 2) {
                ans += str;
            } else {
                ans += str + str;
            }
        }

        return ans;
    }

    public static void main(String[] args) {
        System.out.println(solution("=.="));
    }
}
