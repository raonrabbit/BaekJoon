import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
    public void solution() throws Exception{
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new OutputStreamWriter(System.out));

        while(true){
            String inputData = bufferedReader.readLine();
            if(inputData.equals("0")) break;
            String reversedData = new StringBuffer(inputData).reverse().toString();
            if(inputData.equals(reversedData)){
                bufferedWriter.write("yes");
                bufferedWriter.newLine();
            }
            else{
                bufferedWriter.write("no");
                bufferedWriter.newLine();
            }
        }

        bufferedWriter.flush();
        bufferedReader.close();
        bufferedWriter.close();
    }
    public static void main(String[] args) throws Exception{
        new Main().solution();
    }
}