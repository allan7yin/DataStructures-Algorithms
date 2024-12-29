package org.allan7yin.searching;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

public class StickLengths {
    public static long findMedian(List<Long> nums) {
        int size = nums.size();
        if (size % 2 == 1) {
            int mid = size / 2;
            return nums.get(mid);
        } else {
            int mid1 = size / 2;
            int mid2 = size / 2 - 1;
            return (nums.get(mid1) + nums.get(mid2)) / 2;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        List<Long> nums = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            nums.add(scanner.nextLong());
        }

        nums.sort(Comparator.naturalOrder());

        long med = findMedian(nums);
        long cost = 0;
        for (long num : nums) {
            cost += Math.abs(num - med);
        }

        System.out.println(cost);

        scanner.close();
    }
}
