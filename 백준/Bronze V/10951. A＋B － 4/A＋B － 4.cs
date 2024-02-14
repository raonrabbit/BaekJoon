while (true)
{
    var s = Console.ReadLine();
    if (s == null) break;
    var l = Array.ConvertAll(s.Split(), Int32.Parse);
    Console.WriteLine($"{l[0] + l[1]}");
}