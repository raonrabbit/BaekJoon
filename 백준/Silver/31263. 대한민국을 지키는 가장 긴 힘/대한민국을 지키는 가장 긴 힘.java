import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int N;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        String s = br.readLine();

        int result = 1;
        int temp = 0;
        for(int i = 0; i < N; i++){
            int t = s.charAt(i) - '0';
            temp = temp * 10 + t;
            if(temp > 614) {
                result++;
                if(t == 0){
                    result++;
                    i++;
                }
                temp = t;
            }
        }

        System.out.print(result);
    }
}
