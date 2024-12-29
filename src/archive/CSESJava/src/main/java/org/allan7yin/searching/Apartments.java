package org.allan7yin.searching;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.Scanner;

public class Apartments {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        int m = scanner.nextInt();
        int d = scanner.nextInt();

        ArrayList<Integer> people = new ArrayList<>();
        ArrayList<Integer> sizes = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            people.add(scanner.nextInt());
        }

        for (int i = 0; i < m; i++) {
            sizes.add(scanner.nextInt());
        }

        people.sort(Comparator.reverseOrder());
        sizes.sort(Comparator.reverseOrder());

        int count = 0;
        int l = 0, r = 0;

        while (l < people.size() && r < sizes.size()) {
            if (Math.abs(people.get(l) - sizes.get(r)) <= d) {
                count++;
                l++;
                r++;
            } else if (people.get(l) > sizes.get(r)) {
                l++;
            } else {
                r++;
            }
        }

        System.out.println(count);

        scanner.close();
    }
}
