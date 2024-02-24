var l = Array.ConvertAll(Console.ReadLine().Split(), Int32.Parse);
var r = new List<int[]>();
var s = new List<int[]>();
int result = 1;
for (int i = 0; i < l[0]; i++)
{
    r.Add(Array.ConvertAll(Console.ReadLine().Split(), Int32.Parse));
    s.Add(new int[] { 0, 0 });
}
for(int i = 0; i < l[1]; i++)
{
    int score = 0;
    for(int j = 0; j < l[0]; j++)
    {
        if (r[j][i] == 0) score++;
    }
    for (int j = 0; j < l[0]; j++)
    {
        if (r[j][i] == 1)
        {
            s[j][0] += score;
            s[j][1]++;
        }
    }
}
for(int i = 0; i < l[0]; i++){ 
    if (i == l[2] - 1) continue;
    if (s[i][0] > s[l[2] - 1][0])
    {
        result++;
        continue;
    }
    if (s[i][0] == s[l[2] - 1][0] && s[i][1] > s[l[2] - 1][1])
    {
        result++;
        continue;
    }
    if (s[i][0] == s[l[2] - 1][0] && s[i][1] == s[l[2] - 1][1] && i < l[2]) result++;
}
Console.WriteLine($"{s[l[2] - 1][0]} {result}");