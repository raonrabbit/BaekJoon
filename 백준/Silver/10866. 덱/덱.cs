using System.Text;

var ll = new LinkedList<string>();
var n = int.Parse(Console.ReadLine());
var sb = new StringBuilder();
while (n-- != 0)
{
    var s = Console.ReadLine().Split().ToList();
    if (s[0] == "push_front") ll.AddFirst(s[1]);
    else if (s[0] == "push_back") ll.AddLast(s[1]);
    else if (s[0] == "pop_front")
    {
        if(ll.Count == 0) sb.AppendLine("-1");
        else
        {
            sb.AppendLine(ll.First());
            ll.RemoveFirst();
        }
    }
    else if (s[0] == "pop_back")
    {
        if(ll.Count == 0) sb.AppendLine("-1");
        else
        {
            sb.AppendLine(ll.Last());
            ll.RemoveLast();
        }
    }
    else if (s[0] == "size") sb.AppendLine(ll.Count().ToString());
    else if (s[0] == "empty")
    {
        if (ll.Count == 0) sb.AppendLine("1");
        else sb.AppendLine("0");
    }
    else if (s[0] == "front")
    {
        if (ll.Count == 0) sb.AppendLine("-1");
        else sb.AppendLine(ll.First());
    }
    else if (s[0] == "back")
    {
        if (ll.Count == 0) sb.AppendLine("-1");
        else sb.AppendLine(ll.Last());
    }
}
Console.WriteLine(sb.ToString());