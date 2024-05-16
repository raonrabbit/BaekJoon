var l = Console.ReadLine().Split().Select(int.Parse).ToList();
var t = Console.ReadLine().Split().Select(int.Parse).ToList();
foreach(int i in t)
{
    if (l[1] > i)
        Console.Write($"{i} ");
}