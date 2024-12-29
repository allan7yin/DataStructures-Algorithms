package org.allan7yin.searching;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.Scanner;

public class MovieFestival {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        ArrayList<int[]> movies = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            int start = scanner.nextInt();
            int end = scanner.nextInt();
            movies.add(new int[]{start, end});
        }

        movies.sort((a, b) -> {
            if (a[1] != b[1]) {
                return Integer.compare(a[1], b[1]);
            } else {
                return Integer.compare(b[0], a[0]);
            }
        });

        int prevTime = -1;
        int count = 0;

        for (int[] movie : movies) {
            if (movie[0] >= prevTime) {
                prevTime = movie[1];
                count++;
            }
        }

        System.out.println(count);

        scanner.close();
    }
}
