import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
    public void solution() throws Exception{
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new OutputStreamWriter(System.out));

        int answer = Integer.parseInt(bufferedReader.readLine());
        int number = 0;
        for(int count = 0; count != answer; number++){
            if(String.valueOf(number).contains("666")) count++;
        }
        bufferedWriter.write(String.valueOf(number-1));
        bufferedWriter.flush();
        bufferedReader.close();
        bufferedWriter.close();
    }
    public static void main(String[] args) throws Exception{
        new Main().solution();
    }
}