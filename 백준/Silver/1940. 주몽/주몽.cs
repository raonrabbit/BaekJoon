Func<string> f = Console.ReadLine;
int N = Int32.Parse(f()), M = Int32.Parse(f()), result = 0;
var s = new HashSet<int>();
var t = f().Split().Select(int.Parse).ToList();
foreach (var d in t)
{
    if (s.Contains(d)) result++;
    else s.Add(M - d);
}
Console.WriteLine(result);