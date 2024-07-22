import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Iterator;
import java.util.Set;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int n = Integer.parseInt(br.readLine());
		Set<Integer> set = Stream.of(br.readLine().split(" "))
				.mapToInt(Integer::parseInt)
				.boxed()
				.collect(Collectors.toSet());
		int x = Integer.parseInt(br.readLine());
		int result = 0;
		
		Iterator<Integer> iter = set.iterator();
		while(iter.hasNext()) {
			int num = iter.next();
			if(set.contains(x - num)) {
				result++;
			}
		}
		
		System.out.print(result / 2);
	}

}
