int n = int.Parse(Console.ReadLine());
var l = new List<int>();
for (int i = 0; i < n; i++) l.Add(int.Parse(Console.ReadLine()));
l.Sort();
l.Reverse();
int result = 0;
for(int i = 1; i <= n; i++) if (i % 3 != 0) result += l[i - 1];
Console.Write(result);