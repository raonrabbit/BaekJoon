using System.Text;

var l = Array.ConvertAll(Console.ReadLine().Split(), Int32.Parse);
var s = Console.ReadLine();
int index = l[1] - 1;
StringBuilder sb = new StringBuilder();
if ((l[0] % 2 == 0 && l[1] % 2 == 0) || (l[0] % 2 != 0 && l[1] % 2 != 0))
{
    sb.Append(s[index..]);
    for (int i = index - 1; i >= 0; i--) sb.Append(s[i]);
}
else
{
    sb.Append(s[index..]);
    sb.Append(s[..index]);
}
Console.Write(sb.ToString());