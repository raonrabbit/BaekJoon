Console.ReadLine();
var l = Console.ReadLine().Split('W');
if (l.Length < 3) Console.WriteLine(0);
else if (l[1].Length != 0) Console.WriteLine(6);
else Console.WriteLine(l[0].Length % 2 == 0 ? 5 : 1);