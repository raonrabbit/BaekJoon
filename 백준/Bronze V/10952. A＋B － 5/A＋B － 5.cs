while (true)
{
    var s = Console.ReadLine();
    if (s == "0 0") break;
    var l = Array.ConvertAll(s.Split(), Int32.Parse);
    Console.WriteLine($"{l[0] + l[1]}");
}