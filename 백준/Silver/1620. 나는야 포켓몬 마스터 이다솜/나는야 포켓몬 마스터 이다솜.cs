var l = Array.ConvertAll(Console.ReadLine().Split(), Int32.Parse);
var d = new Dictionary<string, int>();
var t = new List<string>();
var r = new List<string>();
for(int i = 0; i < l[0]; i++)
{
    string name = Console.ReadLine();
    d.Add(name, i + 1);
    t.Add(name);
}
for(int i = 0; i < l[1]; i++)
{
    string name = Console.ReadLine();
    if (d.ContainsKey(name)) r.Add(d[name].ToString());
    else r.Add(t[Int32.Parse(name) - 1]);
}
foreach (string s in r) Console.WriteLine(s);