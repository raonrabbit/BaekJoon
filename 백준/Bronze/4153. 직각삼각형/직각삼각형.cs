while (true)
{
    var d = Console.ReadLine().Split().Select(int.Parse).ToList();
    if (d.Sum() == 0) break;
    int m = d.Max();
    d.Remove(m);
    Console.WriteLine(Math.Pow(m, 2) == (Math.Pow(d[0], 2) + Math.Pow(d[1], 2)) ? "right" : "wrong");
}