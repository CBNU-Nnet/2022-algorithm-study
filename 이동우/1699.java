import java.util.*;

public class bj1699 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        int [] d = new int [n+1];
        for(int i =1; i < n+1; i++){                        // dp 배열을 1~n까지를 채운다
            d[i] = i;
            for(int j = 1; j*j <= i; j++){                   // dp 배열에 들어가는 최솟값을 구하는 반복문
                if(d[i] > d[i-j*j]+1)   d[i] = d[i-j*j]+1;  // 최솟값은 결국에는 제곱수 하나를 뺴고 나머지(앞에서 채워넣은 dp 배열) + 1의 값이다
            }
        }
        System.out.println(d[n]);
    }
}
