var count = new List<int>() { 0, 1, 2, 1};
var a = new List<string>();
var b = new List<string>();
int n = Int32.Parse(Console.ReadLine());

for(int i = 0; i < n; i++)
{
    a.Add(Console.ReadLine());
}

for(int i = 0; i < n; i++)
{
    b.Add(Console.ReadLine());
}

for(int i = 0; i < n; i++)
{
    for(int j = 0; j < n; j++)
    {
        if (a[i][j] != b[i][j]) count[0]++;
        if (a[i][j] != b[n-j-1][i]) count[1]++;
        if (a[i][j] != b[n-i-1][n-j-1]) count[2]++;
        if (a[i][j] != b[j][n - i - 1]) count[3]++;
    }
}
Console.WriteLine(count.Min());