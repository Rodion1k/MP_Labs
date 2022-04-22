package com.main;

public class LCS {

    public static String lcs(String s1, String s2) {
        int[][] lcs = new int[s1.length() + 1][s2.length() + 1];
        for (int i = 0; i <= s1.length(); i++) {
            for (int j = 0; j <= s2.length(); j++) {
                if (i == 0 || j == 0) {
                    lcs[i][j] = 0;
                } else if (s1.charAt(i - 1) == s2.charAt(j - 1)) {
                    lcs[i][j] = lcs[i - 1][j - 1] + 1;
                } else {
                    lcs[i][j] = Math.max(lcs[i - 1][j], lcs[i][j - 1]);
                }
            }
        }
        StringBuilder result = new StringBuilder();
        int i = s1.length();
        int j = s2.length();
        while (i > 0 && j > 0) {
            if (s1.charAt(i - 1) == s2.charAt(j - 1)) {
                result.insert(0, s1.charAt(i - 1));
                i--;
                j--;
            } else if (lcs[i - 1][j] > lcs[i][j - 1]) {
                i--;
            } else {
                j--;
            }
        }
        return result.toString();
    }

    public static int lcsRec(String s1, String s2, int i, int j) {
        if (i == 0 || j == 0) {
            return 0;
        }
        if (s1.charAt(i - 1) == s2.charAt(j - 1)) {
            return lcsRec(s1, s2, i - 1, j - 1) + 1;
        } else {
            return Math.max(lcsRec(s1, s2, i - 1, j), lcsRec(s1, s2, i, j - 1));
        }
    }
}
