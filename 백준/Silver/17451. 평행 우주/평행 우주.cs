long n = long.Parse(Console.ReadLine()), p = 1;
var l = Console.ReadLine().Split().Select(long.Parse).ToList();
l.Reverse();
foreach(var t in l) p = t * ((p / t) + ((p % t)==0?0:1));
Console.Write(p);