import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Something {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt();
        List<int[]> events = new ArrayList<>();

        // Read input and create events
        for (int i = 0; i < n; i++) {
            int start = sc.nextInt();
            int end = sc.nextInt();
            events.add(new int[]{start, 1}); // Arrival event
            events.add(new int[]{end, -1}); // Departure event
        }

        // Sort events by time, with tie-breaker for event type
        events.sort((a, b) -> {
            if (a[0] != b[0]) {
                return Integer.compare(a[0], b[0]); // Primary sort by time
            } else {
                return Integer.compare(b[1], a[1]); // Secondary sort: -1 (departure) before +1 (arrival)
            }
        });

        int maxCount = 0;
        int count = 0;

        // Process events
        for (int[] event : events) {
            count += event[1]; // Increment or decrement count
            maxCount = Math.max(maxCount, count);
        }

        System.out.println(maxCount);
        sc.close();
    }
}