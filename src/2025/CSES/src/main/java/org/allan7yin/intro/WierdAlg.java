package org.allan7yin.intro;
import java.util.ArrayList;
import java.util.Scanner;


public class WierdAlg {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextLong();
        ArrayList<Long> nums = new ArrayList<>();
        nums.add(n);

        while (nums.get(nums.size() - 1) != 1) {
            long last = nums.get(nums.size() - 1);
            if (last % 2 == 0) {
                nums.add(last / 2);
            } else {
                nums.add(last * 3 + 1);
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            System.out.print(nums.get(i));
            if (i != nums.size() - 1) {
                System.out.print(" ");
            }
        }

        scanner.close();
    }
}
