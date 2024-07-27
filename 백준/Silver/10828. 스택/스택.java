import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws IOException {
		int[] stack = new int[10001];
		stack[0] = -1;
		int curIndex = 0;
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int N = Integer.parseInt(br.readLine());
		
		StringTokenizer st;
		for(int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			
			switch(st.nextToken()) {
			case "push":
				stack[++curIndex] = Integer.parseInt(st.nextToken());
				break;
			case "pop":
				System.out.println(stack[curIndex]);
				if(curIndex > 0) curIndex--;
				break;
			case "top":
				System.out.println(stack[curIndex]);
				break;
			case "size":
				System.out.println(curIndex);
				break;
			case "empty":
				if(curIndex <= 0) System.out.println(1);
				else System.out.println(0);
				break;
			}
		}
	}
}
