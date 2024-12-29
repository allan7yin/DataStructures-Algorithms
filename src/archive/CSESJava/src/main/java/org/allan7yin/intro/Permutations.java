package org.allan7yin.intro;
import java.util.ArrayList;
import java.util.Scanner;


public class Permutations {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        ArrayList<Integer> nums = new ArrayList<>();

        for (int i = 2; i <= n; i += 2) {
            nums.add(i);
        }
        for (int i = 1; i <= n; i += 2) {
            nums.add(i);
        }

        boolean found = true;
        for (int i = 0; i < n - 1; i++) {
            if (Math.abs(nums.get(i) - nums.get(i + 1)) <= 1) {
                found = false;
                break;
            }
        }

        if (found) {
            for (int num : nums) {
                System.out.print(num + " ");
            }
        } else {
            System.out.println("NO SOLUTION");
        }

        scanner.close();
    }
}
