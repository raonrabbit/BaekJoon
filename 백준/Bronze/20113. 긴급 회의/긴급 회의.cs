class Program
{
    public static void Main(string[] args)
    {
        List<int> vc = new List<int>(new int[Int32.Parse(Console.ReadLine())]);
        foreach(int v in Array.ConvertAll(Console.ReadLine().Split(' '), Int32.Parse)) if(v != 0) vc[v - 1] += 1;
        int r = vc.IndexOf(vc.Max()) + 1;
        var sl = vc.OrderByDescending(x => x).ToList();
        Console.WriteLine((sl[0] == sl[1]) ? "skipped" : r);
    }
}