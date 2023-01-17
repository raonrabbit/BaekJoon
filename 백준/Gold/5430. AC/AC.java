import java.io.*;
import java.util.*;

public class Main {
    private int dataCount;
    public void solution() throws Exception{
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new OutputStreamWriter(System.out));
        Deque<String> data = new LinkedList<>();

        int testcase = Integer.parseInt(bufferedReader.readLine());
        boolean isReversed, isError;

        for(int i = 0; i < testcase; i++){
            isReversed = false;
            isError = false;
            String commandStr = bufferedReader.readLine();

            int arraySize = Integer.parseInt(bufferedReader.readLine());

            String dataStr = bufferedReader.readLine();
            dataStr = dataStr.substring(1, dataStr.length() - 1);
            StringTokenizer tk = new StringTokenizer(dataStr, ",");
            while(tk.hasMoreTokens()){
                data.add(tk.nextToken());
            }

            for(int j = 0; j < commandStr.length(); j++){
                if(commandStr.charAt(j) == 'D'){
                    if(arraySize == 0){
                        bufferedWriter.write("error\n");
                        isError = true;
                        break;
                    }
                    if(isReversed) data.removeLast();
                    else data.removeFirst();
                    arraySize--;
                }
                else if(commandStr.charAt(j) == 'R'){
                    isReversed = !isReversed;
                }
            }
            if(isError) continue;
            bufferedWriter.write("[");
            if(isReversed){
                if(!data.isEmpty()) bufferedWriter.write(data.removeLast());
                while(!data.isEmpty()){
                    bufferedWriter.write("," + data.removeLast());
                }
            }
            else{
                if(!data.isEmpty()) bufferedWriter.write(data.removeFirst());
                while(!data.isEmpty()){
                    bufferedWriter.write("," + data.removeFirst());
                }
            }
            bufferedWriter.write("]\n");
        }

        bufferedWriter.flush();
        bufferedReader.close();
        bufferedWriter.close();
    }

    public static void main(String[] args) throws Exception {
        new Main().solution();
    }
}