var count = Int32.Parse(Console.ReadLine());
var l1 = new List<string>();
var l2 = Enumerable.Range(0, count).Select(_ => new List<char>()).ToList();
int Wresult = 0, Hresult = 0;
for(int i = 0; i < count; i++)
{
    l1.Add(Console.ReadLine());
    foreach(var s in l1[i].Split('X')) if (s.Length >= 2) Wresult++;
    int j = 0;
    foreach (var c in l1[i]) l2[j++].Add(c);
}
foreach (var l in l2) foreach (var s in String.Concat(l).Split('X')) if (s.Length >= 2) Hresult++;
Console.WriteLine($"{Wresult} {Hresult}");