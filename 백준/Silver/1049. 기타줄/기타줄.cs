var d = Console.ReadLine().Split().Select(int.Parse).ToList();
int a = Int32.MaxValue, b = Int32.MaxValue, result;
for(int i = 0; i < d[1]; i++)
{
    var t = Console.ReadLine().Split().Select(int.Parse).ToList();
    a = Math.Min(a, t[0]);
    b = Math.Min(b, t[1]);
}
if (a > b * 6) result = d[0] * b;
else {
    result = Math.Min(d[0] / 6 * a + d[0] % 6 * b, d[0] / 6 * a + a);
}
Console.WriteLine(result);