var d = Console.ReadLine().Split().Select(int.Parse).ToList();
var l = new List<int>();
for (int i = 0; i < d[1]; i++, l.Add(Int32.Parse(Console.ReadLine())));
l.Sort();
var result = new List<int>() { 0, 0 };

for(int i = 0; i < l.Count; i++)
{
    int a = l.Count - i < d[0] ? l.Count - i : d[0];
    if (result[1] < l[i] * a)
    {
        result[1] = l[i] * a;
        result[0] = l[i];
    }
}
Console.WriteLine($"{result[0]} {result[1]}");