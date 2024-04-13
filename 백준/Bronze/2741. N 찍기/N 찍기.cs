using System.Text;

int n = int.Parse(Console.ReadLine());
StringBuilder sb = new StringBuilder();
for (int i = 1; i <= n; i++) sb.AppendLine(i.ToString());
Console.Write(sb.ToString());