package org.allan7yin.searching;
import java.util.*;

public class ConcertTickets {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        int m = scanner.nextInt();
        TreeMap<Integer, Integer> nums = new TreeMap<>();

        for (int i = 0; i < n; i++) {
            int num = scanner.nextInt();
            nums.put(num, nums.getOrDefault(num, 0) + 1);
        }

        ArrayList<Integer> customers = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            customers.add(scanner.nextInt());
        }

        for (int customer : customers) {
            Map.Entry<Integer, Integer> entry = nums.floorEntry(customer);
            if (entry != null) {
                System.out.println(entry.getKey());
                if (entry.getValue() == 1) {
                    nums.remove(entry.getKey());
                } else {
                    nums.put(entry.getKey(), entry.getValue() - 1);
                }
            } else {
                System.out.println(-1);
            }
        }

        scanner.close();
    }
}
