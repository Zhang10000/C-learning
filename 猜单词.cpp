int wordmatchnum(char* word1, char* word2)
{
    int     num=0;
    int     j;
    
    for(j = 0; j < 6; j++)
    {
        if(word1[j] == word2[j])
            num++;
    }
    
    return num;
}

//选出相似度最高的一个词
void wordsort(char** wordlist, int wordlistSize)
{
    char*   word1;
    char*   word2;
    int     same_num, tmp_same_num, tmp_i = 0;
    int     i, j;
    
    same_num = 0;
    
    for (i = 0; i < wordlistSize; i++)
    {
        tmp_same_num = 0;
        word1 = wordlist[i];
        for (j = 0; j < wordlistSize; j++)
        {
            word2 = wordlist[j];
            
            if (wordmatchnum(word1, word2) > 0)
                tmp_same_num++;
        }
        
        if (tmp_same_num > same_num)
        {
            same_num = tmp_same_num;
            tmp_i = i;
        }
    }
    
    //把第i个单词放在开头
    word1 = wordlist[tmp_i];
    wordlist[tmp_i] = wordlist[0];
    wordlist[0] = word1;
}

int resetwordlist(char** wordlist, int* wordlistSize, Master* master)
{
    int     match_num;
    int     i;
    int     tmp_num=0;
    char*   word;
    
    //把相似度最高的放在开头
    wordsort(wordlist, *wordlistSize);
    
    //选第一个
    word = wordlist[0];
    
    //获取当前匹配值
    match_num = guess(master, word);
    
    //如果是6说明成功，则返回6
    if(match_num == 6)
        return match_num;
    //把与word相同字符数为match_num的单词重新放在wordlist
    else
    {
        for(i = 1; i < *wordlistSize; i++)
        {
            if(wordmatchnum(word, wordlist[i]) == match_num)
                wordlist[tmp_num++] = wordlist[i];
        }
    }
    
    *wordlistSize = tmp_num;
    
    return match_num;
}

void findSecretWord(char** wordlist, int wordlistSize, Master* master) {
    int     match_num;
    char*   tmp_wordlist[100];

    memcpy(tmp_wordlist, wordlist, sizeof(char*) * wordlistSize);
    
    while(true)
    {
        match_num = resetwordlist(tmp_wordlist, &wordlistSize, master);        
        if(match_num == 6)
            break;
    }
    
    return;
}
