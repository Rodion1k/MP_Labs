package com.main;

public class Levenshtein {
    public static int levenshtein(String s, String t, int m, int n) {
        int[][] d = new int[m + 1][n + 1];

        for (int i = 0; i <= m; i++)
            d[i][0] = i;
        for (int j = 1; j <= n; j++)
            d[0][j] = j;

        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                d[i][j] = Math.min(Math.min(d[i - 1][j] + 1, d[i][j - 1] + 1),
                        d[i - 1][j - 1] + ((s.charAt(i - 1) == t.charAt(j - 1)) ? 0 : 1));

        return d[m][n];
    }

    public static int levenshteinRec(String s, String t, int m, int n) {
        if (m == 0)
            return n;
        if (n == 0)
            return m;

        if (s.charAt(m - 1) == t.charAt(n - 1))
            return levenshteinRec(s, t, m - 1, n - 1);
        else
            return 1 + Math.min(Math.min(levenshteinRec(s, t, m, n - 1),
                    levenshteinRec(s, t, m - 1, n)), levenshteinRec(s, t, m - 1, n - 1));
    }
}
