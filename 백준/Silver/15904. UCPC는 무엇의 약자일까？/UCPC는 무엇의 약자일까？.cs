var s = Console.ReadLine();
var r = new List<char>();
bool result;
foreach(var c in s)
{
    if(c == 'U' && r.Count == 0) r.Add(c);
    if (c == 'C' && r.Count == 1) r.Add(c);
    if (c == 'P' && r.Count == 2) r.Add(c);
    if (c == 'C' && r.Count == 3) r.Add(c);
}
Console.Write(r.Count == 4 ? "I love UCPC" : "I hate UCPC");