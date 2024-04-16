var l = Console.ReadLine().Split().Select(int.Parse).ToList();
double n = 0;
foreach(var d in l) n += Math.Pow(d, 2);
Console.WriteLine(n % 10);