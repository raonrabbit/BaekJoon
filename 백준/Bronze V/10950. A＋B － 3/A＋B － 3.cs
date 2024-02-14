int n = Int32.Parse(Console.ReadLine());
var r = new List<int>();
for(int i = 0; i < n; i++)
{
    var l = Array.ConvertAll(Console.ReadLine().Split(), Int32.Parse);
    r.Add(l[0] + l[1]);
}
foreach (var i in r) Console.WriteLine(i);