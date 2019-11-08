import java.util.HashMap;
import java.util.Hashtable;
import java.util.Map;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        for(int i = 1; i <= t; i++){
            int ans = solveProblem(scanner);
            System.out.println(ans);
        }
    }

    public static int solveProblem(Scanner scanner){
        int n = scanner.nextInt();
        int[] arr = new int[2010];
        Hashtable<Integer, Integer> kol = new Hashtable<Integer, Integer>();
        for(int i = 1; i <= n; i++){
            arr[i] = scanner.nextInt();
            kol.put(arr[i], kol.getOrDefault(arr[i], 0) + 1);
        }

        int ans = 0;
        for(int i = 1; i <= n; i++){
            kol.put(arr[i], kol.get(arr[i]) - 1);
            for(int j = i + 1; j < n; j++){
                kol.put(arr[j], kol.get(arr[j]) - 1);
                int x = 2 * arr[j] - arr[i];
                ans += kol.getOrDefault(x, 0);
            }
            for(int j = i + 1; j < n; j++){
                kol.put(arr[j], kol.get(arr[j]) + 1);
            }
        }
        return ans;
    }
}
/**
 4
 5
 1 2 1 2 1
 3
 30 20 10
 5
 1 2 2 3 4
 9
 3 1 4 1 5 9 2 6 5
 */
