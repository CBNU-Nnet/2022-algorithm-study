import java.util.*;

public class bj16503 {

    static int transOperator(char operator, int num1, int num2){
        int result = 0;
        switch (operator) {
            case '+' :
                result  = num1 + num2;
                break;
            case '-' :
                result = num1 - num2;
                break;
            case '/' :
                result = num1 / num2;
                break;
            case '*' :
                result = num1 * num2;
                break;
        };
        return result;
    }

    static int calc(int k1, char o1, int k2, char o2, int k3, int i){
        int result = transOperator(o1, k1, k2);
        if(i == 0)  return transOperator(o2, result, k3);
        else return transOperator(o2, k3, result);
    }

    static void printFunc(int n1, int n2){
        System.out.println(n1);
        System.out.println(n2);
    }

    public static void solution(String input){

        int [] result = new int[2];
        ArrayList<Character> operator = new ArrayList<>();
        ArrayList<Integer> operands = new ArrayList<>();

        // #1 연산자와 숫자를 분리
        String[] split = input.split(" ");
        for(String s : split){
            if(Character.isDigit(s.charAt(0))) operands.add(Integer.valueOf(s));
            else operator.add(s.charAt(0));
        }

        // #2 총 연산의 횟수를 구하고 연산자의 차례대로 계산한다
        result[0] = calc(operands.get(0), operator.get(0), operands.get(1), operator.get(1), operands.get(2), 0);
        result[1] = calc(operands.get(1), operator.get(1), operands.get(2), operator.get(0), operands.get(0), 1);

        if(result[0] > result[1]) printFunc(result[1], result[0]);
        else printFunc(result[0], result[1]);
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String input = sc.nextLine();
        solution(input);
    }
}
