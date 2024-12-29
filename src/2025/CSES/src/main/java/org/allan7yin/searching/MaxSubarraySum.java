package org.allan7yin.searching;
import java.util.ArrayList;
import java.util.Scanner;

public class MaxSubarraySum {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        ArrayList<Long> nums = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            nums.add(scanner.nextLong());
        }

        long maxVal = Long.MIN_VALUE;
        long sum = 0;

        for (int r = 0; r < nums.size(); r++) {
            sum += nums.get(r);
            maxVal = Math.max(maxVal, sum);

            if (sum < 0) {
                sum = 0;
            }
        }

        System.out.println(maxVal);

        scanner.close();
    }
}
