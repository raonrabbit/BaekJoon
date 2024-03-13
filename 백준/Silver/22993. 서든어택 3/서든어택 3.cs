Console.ReadLine();
var d = Console.ReadLine().Split().Select(double.Parse).ToList();
var n = d[0];
d.RemoveAt(0);
d.Sort();
bool result = true;
foreach (var t in d)
{
    if (t < n) n += t;
    else
    {
        result = false;
        break;
    }
}
Console.WriteLine(result ? "Yes" : "No");