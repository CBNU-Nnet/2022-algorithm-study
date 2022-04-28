import java.util.*;
public class bj1283 {
    static String [] options;
    static boolean [] alpha = new boolean [26];

    static void solution() {

        ArrayList<String> resultArray = new ArrayList<>();

        for (String option : options) {
            String[] split = option.split(" ");

            int index = -1;     // 인덱스 번호

            // 각 단어의 첫 글자가 이미 단축키로 설정되었는지 살핀다
            int tmp = 0;
            boolean frontStatus = false;
            for (String s : split) {
                char c = Character.toUpperCase(s.charAt(0));
                if (!alpha[c - 'A']) {
                    alpha[c - 'A'] = true;
                    frontStatus = true;
                    break;
                }
                tmp += (s.length() + 1);
            }
            if (frontStatus) index = tmp;

            // 모든 단어의 첫 글자가 이미 지정되었다면 차례대로 알파벳을 보면서
            boolean backStatus = false;
            if(!frontStatus){
                for(index =0; index < option.length(); index++){
                    if(option.charAt(index) == ' ') continue;
                    else{
                        char t = Character.toUpperCase(option.charAt(index));
                        if(!alpha[t - 'A']){
                            alpha[t - 'A'] = true;
                            backStatus = true;
                            break;
                        }
                    }
                }
            }

            // 어떤한 것도 단축키로 지정할 수 없다면 그냥 놔둔다
            if(backStatus || frontStatus){
                StringBuilder sb = new StringBuilder();
                for(int i =0; i < option.length(); i++){
                    if(i == index){
                        sb.append('[');
                        sb.append(option.charAt(i));
                        sb.append(']');
                    }
                    else sb.append(option.charAt(i));
                }
                resultArray.add(sb.toString());
            }
            else resultArray.add(option);
        }
        for(String str : resultArray)
            System.out.println(str);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = Integer.parseInt(sc.nextLine());
        options = new String [N];
        for(int i =0; i < N; i++)
            options[i] = sc.nextLine();
        solution();
    }
}
