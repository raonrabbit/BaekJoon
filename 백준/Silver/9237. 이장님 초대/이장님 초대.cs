Console.ReadLine();
var d = Console.ReadLine().Split().Select(int.Parse).ToList();
d.Sort();
d.Reverse();
for (int i = 0; i < d.Count; i++)d[i] += (i + 1);
Console.Write(d.Max() + 1);