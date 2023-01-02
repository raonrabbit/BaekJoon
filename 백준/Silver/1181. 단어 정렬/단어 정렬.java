import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

public class Main {
    public void solution() throws Exception {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new OutputStreamWriter(System.out));

        int numberOfWords = Integer.parseInt(bufferedReader.readLine());
        ArrayList<String> arrayList = new ArrayList<String>();

        for (int i = 0; i < numberOfWords; i++){
            arrayList.add(bufferedReader.readLine());
        }

        Set<String> set = new HashSet<String>(arrayList);
        arrayList = new ArrayList<String>(set);

        Collections.sort(arrayList);
        arrayList.sort((String s1, String s2) -> s1.length() - s2.length());

        for (String s : arrayList) {
            bufferedWriter.write(s);
            bufferedWriter.newLine();
        }

        bufferedWriter.flush();
        bufferedReader.close();
        bufferedWriter.close();
    }

    public static void main(String[] args) throws Exception{
        new Main().solution();
    }
}