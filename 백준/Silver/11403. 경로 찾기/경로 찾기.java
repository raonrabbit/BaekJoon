import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.stream.Stream;



public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int N = Integer.parseInt(br.readLine());
		
		int[][] graph = new int[N][];
		
		StringTokenizer st;
		for(int i = 0; i < N; i++) {
			graph[i] = Stream.of(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
		}
		
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				if(graph[i][j] == 1) {
					for(int t = 0; t < N; t++) {
						graph[i][t] = graph[i][t] | graph[j][t];
					}
				}
			}
		}
		
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				if(graph[i][j] == 1) {
					for(int t = 0; t < N; t++) {
						graph[i][t] = graph[i][t] | graph[j][t];
					}
				}
			}
		}
		
		StringBuilder sb = new StringBuilder();
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				sb.append(graph[i][j]).append(' ');
			}
			sb.append('\n');
		}
		
		System.out.print(sb);
	}

}
