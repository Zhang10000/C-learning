public boolean isAdditiveNumber(String num) {
    if (num.length() < 3) return false;
    int n = num.length();
    for (int i = 1; i <= (n - 1) / 2; i++) {
        if (i > 1 && num.charAt(0) == '0') break;=
        for (int j = i + 1; (n - j) >= i && (n - j) >= j - i; j++) {
            if (j - i > 1 && num.charAt(i) == '0') break;
            long num1 = Long.parseLong(num.substring(0, i));
            long num2 = Long.parseLong(num.substring(i, j));
            if (isAdditive(num.substring(j), num1, num2))
                return true;
        }
    }
    return false;
}

private boolean isAdditive(String remain, long num1, long num2) {
    if (remain.equals("")) return true;
    long sum = num1 + num2;
    String str = String.valueOf(sum);
    if (!remain.startsWith(str)) return false;
    return isAdditive(remain.substring(str.length()), num2, sum);
}
