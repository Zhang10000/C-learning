
class Solution {
    class node{
        int x,y,l,r;
        public node(int x, int y, int l, int r) {
            this.x = x;
            this.y = y;
            this.l = l;
            this.r = r;
        }
    }
    private TreeMap<Integer,node> t = new TreeMap<Integer, node>();
    private int sum = 0;
    public Solution(int[][] rects) {

        for (int[] rect : rects) {
            t.put(sum,new node(rect[0],rect[1],rect[2]-rect[0],rect[3]-rect[1]));
            sum+= (rect[2]-rect[0]) * (rect[3]-rect[1]);
        }
    }

    public int[] pick() {
        Random r = new Random();
        int i = r.nextInt(sum);
        node in = t.get(t.floorKey(i));
        return new int[]{ in.x + r.nextInt(in.l)  ,
                in.y + r.nextInt(in.r)
        };
    }
}
