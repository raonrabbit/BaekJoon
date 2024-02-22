var l = Array.ConvertAll(Console.ReadLine().Split(), Int32.Parse);
var q = new Queue<int>();
var s = new HashSet<int>();
int num;
for (int i = 0; i < l[1]; i++, s.Add(Int32.Parse(Console.ReadLine())));
for (int i = 0; i < l[2]; i++) {
    if (s.Count == 0) break;
    foreach(var n in s)
    {
        q.Enqueue(n == 0 ? l[0] - 1 : n - 1);
        q.Enqueue((n + 1) % l[0]);
    }
    s.Clear();
    while(q.Count != 0)
    {
        num = q.Dequeue();
        if (s.Contains(num)) s.Remove(num);
        else s.Add(num);
    }
}

Console.WriteLine(s.Count);