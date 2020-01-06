int poorPigs(int buckets, int m, int p) 
{
	int cnt = p / m+1;
	int ptr = 0;
	for (; buckets > 1;)
	{
		if (buckets % cnt ==0)
		{
			buckets /= cnt;
			++ptr;
		}
		else
		{
			buckets /= cnt;
			
			++ptr;
			if (buckets == 0)
			{
				break;
			}
			++buckets;
		}
	}
	return ptr;
}
