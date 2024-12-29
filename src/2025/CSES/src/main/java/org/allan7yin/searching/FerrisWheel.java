package org.allan7yin.searching;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.Scanner;

public class FerrisWheel {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        int m = scanner.nextInt();

        ArrayList<Integer> nums = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            nums.add(scanner.nextInt());
        }

        nums.sort(Comparator.naturalOrder());

        int l = 0, r = nums.size() - 1;
        int count = 0;

        while (l <= r) {
            if (nums.get(l) + nums.get(r) <= m) {
                l++;
                r--;
            } else {
                r--;
            }
            count++;
        }

        System.out.println(count);

        scanner.close();
    }
}
