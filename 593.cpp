class Solution {
    public boolean validSquare(int[] p1, int[] p2, int[] p3, int[] p4) {
        Set<Integer> set = new HashSet<Integer>();
        set.add(distanceSquare(p1, p2));
        set.add(distanceSquare(p1, p3));
        set.add(distanceSquare(p1, p4));
        set.add(distanceSquare(p2, p3));
        set.add(distanceSquare(p2, p4));
        set.add(distanceSquare(p3, p4));
        return set.size() == 2 && !set.contains(0);
    }
    
    private static int distanceSquare(int[] a, int[] b) {
        int i = a[0] - b[0];
        int j = a[1] - b[1];
        return i * i + j * j;
    }
}
