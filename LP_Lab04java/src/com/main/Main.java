package com.main;

import java.util.Random;

public class Main {

    public static void main(String[] args) {
        // 1 task

        String s1 = generateString(300);
        String s2 = generateString(250);
        System.out.println(s1);
        System.out.println(s2);
        System.out.println("Бес " + " Блеск");
        System.out.println(Levenshtein.levenshtein("Бес", "Блеск",3,5));
        // 2 task
        int[] size1 = new int[]{12, 15, 20, 30, 60, 150, 300};
        int[] size2 = new int[]{10, 13, 17, 25, 50, 125, 250};
        int[] size1rec = new int[]{4, 6, 8, 10, 12, 14, 16};
        int[] size2rec = new int[]{2, 4, 6, 8, 10, 12, 14};

        long[] times = new long[size1.length];
        long[] times2 = new long[size1.length];
        for (int i = 0; i < size1.length; i++) {
            long start = System.currentTimeMillis();
            Levenshtein.levenshtein(s1, s2, size1[i], size2[i]);
            long finish = System.currentTimeMillis();
            times[i] = finish - start;
            start = System.currentTimeMillis();
            Levenshtein.levenshteinRec(s1, s2, size1rec[i], size2rec[i]);
            finish = System.currentTimeMillis();
            times2[i] = finish - start;

        }
        for (int i = 0; i < size1.length; i++) {
            System.out.println(size1[i] + " " + size2[i] + " time: " + times[i]);
        }
        System.out.println("\nRecursive time: \n");
        for (int i = 0; i < size1.length; i++) {
            System.out.println(size1rec[i] + " " + size2rec[i] + " time: " + times2[i]);
        }


        // 5 task
        String s3 = "ALBDACD";// ALBDACD
        String s4 = "CDLDCA";//"CDLDCA";
        long start = System.currentTimeMillis();
        System.out.println("Dynamic subsequence: " + LCS.lcs(s3, s4));
        long finish = System.currentTimeMillis();
        System.out.println("Time: " + (finish - start));
        start = System.currentTimeMillis();
        System.out.println("Recursive subsequence: " + LCS.lcsRec(s3, s4, s3.length(), s4.length()));
        finish = System.currentTimeMillis();
        System.out.println("Time: " + (finish - start));

    }

    private static String generateString(int length) {
        StringBuilder sb = new StringBuilder(length);
        for (int i = 0; i < length; i++) {
            sb.append(getRandomChar());
        }
        return sb.toString();
    }

    private static char getRandomChar() {
        int leftLimit = 48; // numeral '0'
        int rightLimit = 122; // letter 'z'
        Random random = new Random();
        return (char) random.ints(leftLimit, rightLimit + 1)
                .filter(i -> (i <= 57 || i >= 65) && (i <= 90 || i >= 97))
                .findFirst().getAsInt();
    }
}
