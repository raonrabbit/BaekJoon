var d = Array.ConvertAll(Console.ReadLine().Split(), Int32.Parse);
int n = Int32.Parse(Console.ReadLine());
var w = new List<int>() { 0 };
var h = new List<int>() { 0 };
for(int i = 0; i < n; i++)
{
    var t = Array.ConvertAll(Console.ReadLine().Split(), Int32.Parse);
    if (t[0] == 0) h.Add(t[1]);
    else w.Add(t[1]);
}
w.Add(d[0]);
h.Add(d[1]);
w.Sort();
h.Sort();
int result = 0;
for(int i = 0; i < w.Count - 1; i++)
{
    for(int j = 0; j < h.Count - 1; j++)
    {
        result = Math.Max(result, (w[i + 1] - w[i]) * (h[j + 1] - h[j]));
    }
}
Console.WriteLine(result);