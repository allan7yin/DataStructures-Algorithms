package org.allan7yin.intro;

import java.util.ArrayList;
import java.util.Scanner;

public class MissingNumber {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();

        ArrayList<Integer> nums = new ArrayList<>();
        boolean[] seen = new boolean[n + 1];

        for (int i = 0; i < n; i++) {
            int num = scanner.nextInt();
            nums.add(num);
            seen[num] = true;
        }

        for (int i = 1; i <= n; i++) {
            if (!seen[i]) {
                System.out.println(i);
            }
        }

        scanner.close();
    }
}
