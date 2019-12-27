public class AllOne
{

    public class Bucket
    {
        //相关联的前后指针
        public Bucket pre, next;
        //当前的层级
        public int val;
        //当前层级所对应的 hash
        public HashSet<string> hash;

        public Bucket(int val)
        {
            this.val = val;
            hash = new HashSet<string>();
            next = pre = null;
        }
    }

    /// <summary>
    /// 存储对应的数据
    /// </summary>
    private Dictionary<string, Bucket> _dic;

    /// <summary>
    /// 头部指针（最小值）
    /// </summary>
    private Bucket _head;

    /// <summary>
    /// 尾部指针（最大值）
    /// </summary>
    private Bucket _tail;


    /** Initialize your data structure here. */
    public AllOne()
    {
        _dic = new Dictionary<string, Bucket>();

        _head = _tail = null;
    }

    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    public void Inc(string key)
    {
        if(_dic.ContainsKey(key))
        {
            //获取当前所在的bucket中
            var bucket = _dic[key];
            //获取之前的bucket的数据
            var val = bucket.val;
            //移除数据
            bucket.hash.Remove(key);

            //在新的bucket中添加此数据
            if(bucket.next == null || bucket.next.val != val + 1)
            {
                //没有符合条件的 bucket,需要新插入一条
                var newBucket = new Bucket(val + 1);

                //把新的bucket插入相应的位置
                newBucket.pre = bucket;
                newBucket.next = bucket.next;
                bucket.next = newBucket;

                if (newBucket.next != null)
                    newBucket.next.pre = newBucket;
            }

            //添加存储数据
            bucket.next.hash.Add(key);
            _dic[key] = bucket.next;

            //更新head结点
            if(bucket.hash.Count == 0)
            {
                if (bucket == _head)
                    _head = bucket.next;
                //把bucket结点移除
                bucket.next.pre = bucket.pre;
                if (bucket.pre != null)
                    bucket.pre.next = bucket.next;
            }

            //更新tail结点
            if (_tail == bucket)
                _tail = bucket.next;
        }
        else
        {
            //数据不存在，那么就插入到当前的最小队列中

            if(_head == null || _head.val > 1)
            {
                //需要重新创建
                var bucket = new Bucket(1);
                //把数据放在最前面
                bucket.next = _head;
                if (_head != null)
                    _head.pre = bucket;
                _head = bucket;

                //如果_tail 没有数据，那么当前就作为_tail数据保存
                if (_tail == null)
                    _tail = bucket;
            }

            _head.hash.Add(key);
            _dic[key] = _head;
        }


    }

    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    public void Dec(string key)
    {
        //如果没有此条数据，那么就直接返回
        if (!_dic.ContainsKey(key))
            return;

        //获取对应bucket
        var bucket = _dic[key];
        //获取对应数据val
        var val = bucket.val;
        //移除相应信息
        bucket.hash.Remove(key);

        //如果是在头部，那么移除之后就需要更新 heal 和 tail
        if(val == 1)
        {
            //数据需要移除，那么需要检测更新
            if(bucket.hash.Count == 0)
            {
                if (_head == bucket)
                    _head = bucket.next;

                if (_head != null)
                    _head.pre = null;

                if (_tail == bucket)
                    _tail = null;
            }
        }
        else
        {
            //不存在符合条件的bucket,需要新加
            if(bucket.pre == null || bucket.pre.val != val - 1)
            {
                var newBucket = new Bucket(val - 1);
                newBucket.next = bucket;
                newBucket.pre = bucket.pre;
                bucket.pre = newBucket;

                if (newBucket.pre != null)
                    newBucket.pre.next = newBucket;
            }

            bucket.pre.hash.Add(key);
            _dic[key] = bucket.pre;

            //更新head
            if (_head == bucket)
                _head = bucket.pre;

            //更新tail
            if(bucket.hash.Count == 0)
            {
                if (bucket == _tail)
                    _tail = bucket.pre;

                bucket.pre.next = bucket.next;
                if (bucket.next != null)
                    bucket.next.pre = bucket.pre;
            }
        }
    }

    /** Returns one of the keys with maximal value. */
    public string GetMaxKey()
    {

        if (_tail == null)
        {
            return "";
        }
        else
        {
            var itor = _tail.hash.GetEnumerator();
            //下标需要先移位，才能取到正确数据
            itor.MoveNext();

            return itor.Current;
        }
    }

    /** Returns one of the keys with Minimal value. */
    public string GetMinKey()
    {
        if (_head == null)
        {
            return "";
        }
        else
        {
            var itor = _head.hash.GetEnumerator();
            //下标需要先移位，才能取到正确数据
            itor.MoveNext();

            return itor.Current;
        }
    }
}
