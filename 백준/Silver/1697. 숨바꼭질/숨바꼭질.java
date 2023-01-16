import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main{
    private final Queue<Integer> queue = new LinkedList<Integer>();
    private final int[] visitedCheck = new int[110000];
    private int start, goal;
    public void solution() throws Exception{
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(bufferedReader.readLine());
        BufferedWriter bufferedWriter = new BufferedWriter(new OutputStreamWriter(System.out));

        start = Integer.parseInt(st.nextToken());
        goal = Integer.parseInt(st.nextToken());
        int temp;

        queue.add(start);
        visitedCheck[start] = 1;
        while(!queue.isEmpty()) {
            temp = queue.poll();
            if(addTemp(temp,temp - 1)) break;
            if(addTemp(temp,temp + 1)) break;
            if(addTemp(temp,temp * 2)) break;
        };

        bufferedWriter.write(String.valueOf(visitedCheck[goal] - 1));
        bufferedWriter.flush();
        bufferedReader.close();
        bufferedWriter.close();
    }

    private boolean addTemp(int temp, int next){
        if(next >= 0 && next < visitedCheck.length && visitedCheck[next] == 0)
        {
            queue.add(next);
            visitedCheck[next] = visitedCheck[temp] + 1;
        }
        return next == goal;
    }

    public static void main(String[] args) throws Exception{
        new Main().solution();
    }
}