package org.allan7yin.searching;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

public class SumOf2Values {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        int target = scanner.nextInt();

        List<int[]> nums = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int num = scanner.nextInt();
            nums.add(new int[]{num, i});
        }

        nums.sort(Comparator.comparingInt(a -> a[0]));

        boolean found = false;
        int l = 0, r = nums.size() - 1;

        while (l < r) {
            int val = nums.get(l)[0] + nums.get(r)[0];
            if (val == target) {
                System.out.println((nums.get(l)[1] + 1) + " " + (nums.get(r)[1] + 1));
                found = true;
                break;
            } else if (val > target) {
                r--;
            } else {
                l++;
            }
        }

        if (!found) {
            System.out.println("IMPOSSIBLE");
        }

        scanner.close();
    }
}
