Func<int[]> c = () => Array.ConvertAll(Console.ReadLine().Split(), Int32.Parse);
var d = c();
var l = new List<int>();
var l2 = new List<int>();
int j = 0;
for(int i = 0; i < d[0]; i++)
{
    foreach (var n in c())
    {
        l.Add(n);
        l2.Add(j++);
    }
}
int t = 0, r = 0;
while(l2.Count != 1)
{
    r = l[l2[t]];
    l2.RemoveAt(t);
    t = (t + (r - 1)) % l2.Count;
}
Console.WriteLine($"{l2[0] / d[1] + 1} {l[l2[0]]}");