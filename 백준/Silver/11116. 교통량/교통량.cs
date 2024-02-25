Func<string> r = Console.ReadLine;
var t = Int32.Parse(r());
while(t-- != 0)
{
    int result = 0;
    var n = Int32.Parse(r());
    var ls = new HashSet<int>(Array.ConvertAll(r().Split(), Int32.Parse));
    var rs = new HashSet<int>(Array.ConvertAll(r().Split(), Int32.Parse));
    foreach (var d in ls) if (ls.Contains(d + 500) && rs.Contains(d + 1000) && rs.Contains(d + 1500)) result++;
    Console.WriteLine(result);
}