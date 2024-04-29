var l = Console.ReadLine().Split().Select(int.Parse).ToList();
Console.WriteLine((l[0]+l[1])%l[2]);
Console.WriteLine(((l[0]%l[2])+(l[1] % l[2]))%l[2]);
Console.WriteLine((l[0]*l[1])%l[2]);
Console.WriteLine(((l[0]%l[2])*(l[1]%l[2]))%l[2]);