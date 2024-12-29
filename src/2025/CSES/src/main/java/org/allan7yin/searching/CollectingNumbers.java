package org.allan7yin.searching;
import java.util.Scanner;

public class CollectingNumbers {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        int[] nums = new int[n + 1];

        for (int i = 0; i < n; i++) {
            int num = scanner.nextInt();
            nums[num] = i;
        }

        int count = 1;
        for (int i = 2; i <= n; i++) {
            if (nums[i] < nums[i - 1]) {
                count++;
            }
        }

        System.out.println(count);

        scanner.close();
    }
}
