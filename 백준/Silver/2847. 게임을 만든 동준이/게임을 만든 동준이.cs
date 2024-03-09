var d = Int32.Parse(Console.ReadLine());
var l = new List<int>();
for(int i = 0; i < d; i++, l.Add(Int32.Parse(Console.ReadLine())));
var t = l[d - 1] - 1;
var result = 0;
for(int i = d - 2; i >= 0; i--, t--)
{
    if (l[i] > t) result += (l[i] - t);
    else t = l[i];
}
Console.WriteLine(result);