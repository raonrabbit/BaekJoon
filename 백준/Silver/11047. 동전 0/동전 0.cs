var d = Console.ReadLine().Split().Select(int.Parse).ToList();
var l = new List<int>();
int r = 0;
for(int i = 0; i < d[0]; i++)
{
    l.Add(int.Parse(Console.ReadLine()));
}
l.Reverse();
for(int i = 0; i < d[0]; i++)
{
    int t = d[1] / l[i];
    if (t > 0)
    {
        r += t;
        d[1] -= l[i] * t;
    } 
}
Console.Write(r);