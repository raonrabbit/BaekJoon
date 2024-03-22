using System.Text;

int n = int.Parse(Console.ReadLine());
var s = new Stack<string>();
var sb = new StringBuilder();
while (n-- != 0)
{
    var c = Console.ReadLine().Split();
    if (c.Length == 2)
    {
        s.Push(c[1]);
        continue;
    }
    if (c[0][0] == 'p')
    {
        string z = s.Count() > 0 ? s.Pop() : "-1";
        sb.AppendLine(z);
        continue;
    }
    if (c[0][0] == 'e') {
        string z = s.Count > 0 ? "0" : "1";
        sb.AppendLine(z);
        continue;
    }
    if (c[0][0] == 's') sb.AppendLine($"{s.Count()}");
    if (c[0][0] == 't') {
        string z = s.Count() > 0 ? s.Peek() : "-1";
        sb.AppendLine(z);
    }
}
Console.WriteLine(sb.ToString());