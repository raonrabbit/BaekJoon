using System.Text;

int n = int.Parse(Console.ReadLine());
var sb = new StringBuilder();
for(int i = 0; i < n; i++)
{
    int d = int.Parse(Console.ReadLine());
    var s = Console.ReadLine().Split().ToList();
    string min = "Z";
    var l = new LinkedList<string>();
    foreach(var v in s)
    {
        if (string.Compare(v, min) <= 0)
        {
            l.AddFirst(v);
            min = v;
        }
        else l.AddLast(v);
    }
    foreach (var v in l) sb.Append(v);
    sb.AppendLine();
}
Console.WriteLine(sb.ToString());