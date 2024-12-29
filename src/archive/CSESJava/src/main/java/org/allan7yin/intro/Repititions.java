package org.allan7yin.intro;
import java.util.ArrayList;
import java.util.Scanner;


public class Repititions {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input = scanner.next();

        int maxLength = 0;
        int l = 0;

        for (int r = 0; r < input.length(); r++) {
            if (input.charAt(r) != input.charAt(l)) {
                maxLength = Math.max(maxLength, r - l);
                l = r;
                continue;
            }

            if (r == input.length() - 1) {
                maxLength = Math.max(maxLength, r - l + 1);
            }
        }

        System.out.println(maxLength);
        scanner.close();
    }
}
