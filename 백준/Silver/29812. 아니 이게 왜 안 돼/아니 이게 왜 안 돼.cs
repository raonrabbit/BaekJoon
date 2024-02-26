int count = Int32.Parse(Console.ReadLine());
var s = Console.ReadLine();
var l = Array.ConvertAll(Console.ReadLine().Split(), Int32.Parse);
int result = 0;
int d = 0;
Dictionary<char, int> dic = new Dictionary<char, int>();
dic.Add('H', 0);
dic.Add('Y', 0);
dic.Add('U', 0);
foreach (var c in s)
{
    if(c != 'H' && c != 'Y' && c != 'U')
    {
        d++;
    }
    else
    {
        dic[c]++;
        result += d * l[0] > l[1] + l[0] ? l[1] + l[0] : d * l[0];
        d = 0;
    }
}
result += d * l[0] > l[1] + l[0] ? l[1] + l[0] : d * l[0];
Console.WriteLine(result == 0 ? "Nalmeok" : result);
int min = dic.Values.ToList().Min();
Console.WriteLine(min == 0 ? "I love HanYang University" : min);