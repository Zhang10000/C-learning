class Solution {
    public int strongPasswordChecker(String s) {
     //长度判断
        boolean longer;
        boolean shorter;
        longer=s.length() > 20;
        shorter=s.length()<6;

        int charJug=0;
        char[]chars=s.toCharArray();
        for(char c:chars){
            if(c<='Z'&&c>='A'){
                charJug+=1;
                break;
            }
        }
        for(char c:chars){
            if(c<='z'&&c>='a'){
                charJug+=1;
                break;
            }
        }
        for(char c:chars){
            if(c<='9'&&c>='0'){
                charJug+=1;
                break;
            }
        }

        int triSameCount=0;
        List<Integer> list=new ArrayList<>();
        for(int i=0;i<chars.length-2;){
            int j=1;
            while (j+i<chars.length){
                if(chars[i]==chars[i+j])
                    j++;
                else
                    break;
            }
            triSameCount+=j/3;
            if(j-2>0)
                list.add(j-2);
            i+=j;
        }
        if(triSameCount==0&&charJug==3&&!longer&&!shorter)
            return 0;
        int lengthLeast=0;
        if(longer){
            int temp=s.length()-20;
            lengthLeast=temp;
            int count2=0;
            int m=1;
            while (list.size()>0){
                int temp2=lengthLeast;
                for(int i=m;lengthLeast>=i;) {
                    for (int j = 0; j < list.size(); j++) {
                         if (lengthLeast>=i&&(list.get(j) + 2) / 3 - (list.get(j) + 2 - i) / 3 > 0) {
                            list.set(j, list.get(j) - i);
                            lengthLeast -= i;
                            count2++;
                        }
                    }
                    if(i<3)
                        i++;
                }
                m=3;
                if(temp2==lengthLeast)
                    break;
            }

            lengthLeast=temp+Math.max(triSameCount-count2,3-charJug);
        }
        if(shorter) {
            lengthLeast = 6 - s.length();
            lengthLeast= Math.max(lengthLeast, 3-charJug);

        }
        if(!longer&&!shorter){
            lengthLeast= Math.max(triSameCount, 3-charJug);
        }
        return lengthLeast;
    }
}
