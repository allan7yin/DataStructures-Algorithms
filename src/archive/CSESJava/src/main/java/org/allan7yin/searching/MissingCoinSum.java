package org.allan7yin.searching;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.Scanner;

public class MissingCoinSum {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        ArrayList<Integer> nums = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            nums.add(scanner.nextInt());
        }

        nums.sort(Comparator.naturalOrder());

        long sum = 1;
        for (int num : nums) {
            if (num > sum) {
                break;
            } else {
                sum += num;
            }
        }

        System.out.println(sum);

        scanner.close();
    }
}
