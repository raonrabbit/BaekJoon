var l = new List<List<char>>();
for (int i = 0; i < 5; i++) {
    var s = Console.ReadLine();
    for(int j = 0; j < s.Length; j++)
    {
        if (j >= l.Count) l.Add(new List<char>());
        l[j].Add(s[j]);
    }
}
foreach(var a in l) { Console.Write(String.Concat(a)); }