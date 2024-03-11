var d = Array.ConvertAll(Console.ReadLine().Split(), Double.Parse);
double p = d[1];
var mr = new List<double>();
var er = new List<double>();
for(int i = 0; i < d[0]; i++)
{
    var t = Array.ConvertAll(Console.ReadLine().Split(), Double.Parse);
    (t[0] == 1 ? mr : er).Add(t[1]);
}
mr.Sort();
er.Sort();
int ei = 0, result = 0;
foreach (var m in mr)
{
    if (p > m)
    {
        p += m;
    }
    else
    {
        while (p <= m && ei != er.Count)
        {
            p *= er[ei++];
            result++;
        }
        if (p > m)
        {
            p += m;
        }
        else break;
    }
    result++;
}
result += er.Count - ei;
Console.WriteLine(result);