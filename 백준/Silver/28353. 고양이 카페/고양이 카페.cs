var d = Console.ReadLine().Split().Select(int.Parse).ToList();
var t = Console.ReadLine().Split().Select(int.Parse).ToList();
t.Sort();
int l = 0, r = d[0] - 1;
while (l < r) if (t[l] + t[r--] <= d[1])l++;
Console.Write(l);