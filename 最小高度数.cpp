class Solution {
    public List<Integer> findMinHeightTrees(int n, int[][] edges) {
        List<Integer> list = new ArrayList<>();
        int[] is = new int[n];
        
        Map<Integer,List<Integer>> map = new HashMap<>();
        for(int i=0;i<n;i++){
            map.put(i,new ArrayList<>());
        }
        for(int i=0;i<edges.length;i++){
            map.get(edges[i][0]).add(edges[i][1]);
            map.get(edges[i][1]).add(edges[i][0]);
        }
        is[0] = 1;
        int m1 = help(is,0,map);
        Arrays.fill(is,0);
        is[m1] = 1;
        int m2 = help(is,m1,map);
        
        list.add(m2);
        while(m2!=m1){
            for(int m:map.get(m2)){
                if(is[m]+1==is[m2]){
                    m2 = m;
                    list.add(m2);
                    break;
                }
            }
        }
        int size = list.size();
        if(size%2==0){
            return Arrays.asList(list.get((size-1)>>1),list.get(size>>1));
        }else{
            return Arrays.asList(list.get(size>>1));
        }
    }
    public int help(int[] is,int i,Map<Integer,List<Integer>> map){
        int max = i;
        for(int num:map.get(i)){
            if(is[num]==0){
                is[num] = is[i]+1;
                int r = help(is,num,map);
                if(is[r]>is[max]){
                    max = r;
                }
            }
        }
        return max;
    }
}
