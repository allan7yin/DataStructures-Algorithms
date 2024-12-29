package org.allan7yin.intro;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class NumberSpiral {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = Integer.parseInt(scanner.nextLine());
        List<List<Long>> rows = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            String line = scanner.nextLine();
            String[] tokens = line.split(" ");
            List<Long> row = new ArrayList<>();

            for (String token : tokens) {
                row.add(Long.parseLong(token));
            }

            rows.add(row);
        }

        long dimensions = 0;
        for (List<Long> p : rows) {
            dimensions = Math.max(dimensions, Math.max(p.get(1), p.get(0)));
        }

        scanner.close();
    }
}
