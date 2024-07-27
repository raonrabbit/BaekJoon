import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	
		int N = Integer.parseInt(br.readLine());
		int[] queue = new int[10000];
		
		int front = 0, back = 0;
		
		for(int i = 0; i < N; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			String inst = st.nextToken();
			
			switch(inst) {
			case "push":
				int n = Integer.parseInt(st.nextToken());
				queue[back++] = n;
				break;
			case "pop":
				if(back - front == 0) System.out.println(-1);
				else System.out.println(queue[front++]);
				break;
			case "size":
				System.out.println(back - front);
				break;
			case "empty":
				if(back - front == 0) System.out.println(1);
				else System.out.println(0);
				break;
			case "front":
				if(back - front == 0) System.out.println(-1);
				else System.out.println(queue[front]);
				break;
			case "back":
				if(back - front == 0) System.out.println(-1);
				else System.out.println(queue[back - 1]);
				break;
			}
		}
	}

}
