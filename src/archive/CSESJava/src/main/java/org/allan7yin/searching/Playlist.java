//package org.allan7yin.searching;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;

public class Playlist {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        ArrayList<Long> songs = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            songs.add(scanner.nextLong());
        }

        HashMap<Long, Integer> map = new HashMap<>();

        Long maxLength = 0L;
        int l = 0;

        for (int i = 0; i < n; i++) {
            Long song = songs.get(i);
            if (!map.containsKey(song)) {
                map.put(song, i);
            } else {
                if (map.get(song) >= l) {
                    l = map.get(song) + 1;
                }

                map.put(song, i);
            }

            // Update maxLength with the current window size
            maxLength = Math.max(maxLength, i - l + 1);
        }

        System.out.println(maxLength);
    }
}