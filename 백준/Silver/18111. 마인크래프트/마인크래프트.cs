var d = Console.ReadLine().Split().Select(int.Parse).ToList();
var sd = new SortedDictionary<int, int>();
int min = int.MaxValue, max = -1;
for(int i = 0; i < d[0]; i++)
{
    var t = Console.ReadLine().Split().Select(int.Parse).ToList();
    foreach(var n in t)
    {
        if (sd.ContainsKey(n)) sd[n]++;
        else sd.Add(n, 1);
        min = min > n ? n : min;
        max = max < n ? n : max;
    }
}
var result1 = int.MaxValue;
var result2 = int.MaxValue;
for(int n = min; n <= max; n++)
{
    int blockCount = d[2];
    int r = 0;
    foreach (var b in sd)
    {
        if (n == b.Key) continue;
        if (b.Key > n) {
            r += (b.Key - n) * b.Value * 2;
            blockCount += (b.Key - n) * b.Value;
        }
        else
        {
            r += (n - b.Key) * b.Value * 1;
            blockCount -= (n - b.Key) * b.Value;
        }
    }
    if (blockCount < 0) continue;
    if (result1 == r && result2 > n) continue;
    if(result1 >= r)
    {
        result1 = r;
        result2 = n;
    }
}

Console.WriteLine($"{result1} {result2}");