using System.Data;

string s = Console.ReadLine();
DataTable dt = new DataTable();
var a = s.Split('-').ToList();
int result = (int)dt.Compute(a[0], "");
foreach (string b in a.Skip(1))
{
    var n = (int)dt.Compute(b, "");
    result += (b[0] == '+') ? n : n * -1;
}
Console.WriteLine(result);