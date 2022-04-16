import java.util.*;

public class bj1541 {

    static String str;

    static void solution(){

        StringBuilder sb = new StringBuilder();
        str += " ";
        boolean status = true;
        int result = 0;
        for(char c : str.toCharArray()){
            if(c >= '0' && c <= '9') sb.append(c);
            else{
                if(status) result += Integer.parseInt(sb.toString());
                else result -= Integer.parseInt(sb.toString());
                if(c == '-') status = false;

                sb.delete(0, sb.length());
            }
        }
        System.out.println(result);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        str = sc.next();
        solution();
    }
}
