var l = Console.ReadLine().Split().Select(int.Parse).ToList();
Console.Write($"{l[1] - l[0]} {l[1]}");