using StreamWriter sw = new(Console.OpenStandardOutput());

int n = Int32.Parse(Console.ReadLine()!);
var d = new Dictionary<int, int>();
for (int i = 0; i < n; i++)
{
    var l = Array.ConvertAll(Console.ReadLine()!.Split(), Int32.Parse);
    if (l[0] == 1) d.Add(l[2], l[1]);
    else sw.WriteLine(d[l[1]]);
}