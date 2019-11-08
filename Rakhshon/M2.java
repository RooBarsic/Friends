import javax.lang.model.type.IntersectionType;
import java.awt.image.BufferedImage;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int t = Integer.parseInt(st.nextToken());
        for(int i = 1; i <= t; i++){
            int ans = solveProblem(br);
            System.out.println(ans);
        }
    }

    public static int solveProblem(BufferedReader br) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int[] arr = new int[2010];
        HashMap<Integer, Integer> kol = new HashMap<>();
        st = new StringTokenizer(br.readLine());
        for(int i = 1; i <= n; i++){
            arr[i] = Integer.parseInt(st.nextToken());
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
