int n = Int32.Parse(Console.ReadLine()), result = 0;
var l = new List<string>();
for (int i = 0; i < n; i++) l.Add(Console.ReadLine());
for (int i = 0; i < n - 1; i++)
{
    for (int j = i + 1; j < n; j++)
    {
        int minLength = Math.Min(l[i].Length, l[j].Length);
        for (int k = 1; k <= minLength; k++)
        {
            int l1Index = l[i].Length - k;
            int l2Index = l[j].Length - k;
            if (l[i][l1Index..] == l[j][..k] || l[j][l2Index..] == l[i][..k])
            {
                result++;
                break;
            }
        }
    }
}
Console.WriteLine(result);