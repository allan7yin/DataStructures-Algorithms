package org.allan7yin.searching;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

public class RestaurantCustomers {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        ArrayList<int[]> events = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int first = scanner.nextInt();
            int second = scanner.nextInt();
            events.add(new int[]{first, 1});
            events.add(new int[]{second, -1});
        }

        events.sort((a, b) -> {
            if (a[0] != b[0]) {
                return Integer.compare(a[0], b[0]);
            } else {
                return Integer.compare(a[1], b[1]);
            }
        });

        int maxCount = 0;
        int count = 0;
        for (int[] event : events) {
            if (event[1] == 1) {
                count++;
                maxCount = Math.max(maxCount, count);
            } else {
                count--;
            }
        }

        System.out.println(maxCount);
        scanner.close();
    }

}
