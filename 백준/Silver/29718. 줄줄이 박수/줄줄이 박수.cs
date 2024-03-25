var d = Console.ReadLine().Split().Select(int.Parse).ToList();
var l = new List<int>(new int[d[1]]);
for(int i = 0; i < d[0]; i++)
{
    var s = Console.ReadLine().Split().Select(int.Parse).ToList();
    for (int j = 0; j < d[1]; j++)
    {
        l[j] += s[j];
    }
}
int n = int.Parse(Console.ReadLine()), max, sum = 0;
for(int i = 0; i < n; i++)
{
    sum += l[i];
}
max = sum;
for (int i = 1; i <= d[1] - n; i++)
{
    sum -= l[i - 1];
    sum += l[i + n - 1];
    max = Math.Max(max, sum);
}
Console.Write(max);