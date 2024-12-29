package org.allan7yin.intro;

import java.util.ArrayList;
import java.util.Scanner;

public class IncreasingArray {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        ArrayList<Long> nums = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            nums.add(scanner.nextLong());
        }

        long cost = 0;
        long prev = -1;

        for (int i = 0; i < n; i++) {
            long current = nums.get(i);
            if (current < prev) {
                cost += (prev - current);
                nums.set(i, prev);
            }
            prev = nums.get(i);
        }

        System.out.println(cost);

        scanner.close();
    }
}
