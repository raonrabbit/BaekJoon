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
int maxX = 0, maxY = 0;
for (int i = 0; i < w.Count - 1; i++) maxX = Math.Max(maxX, w[i + 1] - w[i]);
for (int i = 0; i < h.Count - 1; i++) maxY = Math.Max(maxY, h[i + 1] - h[i]);
Console.WriteLine(maxX * maxY);