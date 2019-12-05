#define MAX 40960
int * gret[MAX], gret2[MAX][2], gcol[MAX], glen[MAX];
int** palindromePairs(char ** words, int wordsSize, int* returnSize, int** returnColumnSizes){
    int i, j, a, b, m, n, find, guse = 0;  
    for (i = 0; i < wordsSize; i++){
        for (j = 0; j < wordsSize; j++){
            if (i==0){glen[j] = strlen(words[j]);}
            if (i == j)continue;
            for (a = glen[i], b = glen[j], find = 0, m = 0, n = a + b -1; m <= n; m++, n--){
                if (((m >= a)?(words[j][m-a]):(words[i][m])) != ((n >= a)?(words[j][n-a]):(words[i][n]))){
                    break;//nok
                }
            }
            if (n < m){find = 1;}
            if (!find){continue;}
            gret[guse] = gret2[guse];//malloc(sizeof(int)*2);
            gret[guse][0] = i; gret[guse][1] = j;
            gcol[guse++] = 2;
        }
    }

    *returnSize = guse;
    *returnColumnSizes = gcol;
    return gret;
}
