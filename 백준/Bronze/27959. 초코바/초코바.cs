var l = Console.ReadLine().Split().Select(int.Parse).ToList();
Console.Write(l[0] * 100 < l[1] ? "No" : "Yes");