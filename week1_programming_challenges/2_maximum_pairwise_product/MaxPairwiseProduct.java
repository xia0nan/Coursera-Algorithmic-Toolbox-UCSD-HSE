import java.util.*;
import java.io.*;

public class MaxPairwiseProduct {
    static long getMaxPairwiseProduct(int[] numbers) {
        int n = numbers.length;
        int max_index1 = -1;
        int max_index2 = -1;

        for (int first = 0; first < n; first++) {
            if ((max_index1 == -1) || (numbers[first] > numbers[max_index1])) {
                max_index1 = first;
            }
        }

        for (int second = 0; second < n; ++second) {
            if (((max_index2 == -1) || (numbers[second] > numbers[max_index2])) && (second != max_index1)) {
                max_index2 = second;
            }
        }
        
        long product = (long) numbers[max_index1] * numbers[max_index2];
        return product;
    }

    public static void main(String[] args) {
        FastScanner scanner = new FastScanner(System.in);
        int n = scanner.nextInt();
        int[] numbers = new int[n];
        for (int i = 0; i < n; i++) {
            numbers[i] = scanner.nextInt();
        }
        System.out.println(getMaxPairwiseProduct(numbers));
    }

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(InputStream stream) {
            try {
                br = new BufferedReader(new
                    InputStreamReader(stream));
            } catch (Exception e) {
                e.printStackTrace();
            }
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }
    }

}
