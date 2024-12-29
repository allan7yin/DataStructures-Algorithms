package org.allan7yin.searching;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

public class DistinctNumbers {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        ArrayList<Integer> nums = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            nums.add(scanner.nextInt());
        }

        nums.sort(Comparator.naturalOrder());

        int count = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (!nums.get(i).equals(nums.get(i - 1))) {
                count++;
            }
        }

        System.out.println(count);

        scanner.close();
    }
}
