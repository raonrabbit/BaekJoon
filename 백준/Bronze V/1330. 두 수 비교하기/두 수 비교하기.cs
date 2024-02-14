var l = Array.ConvertAll(Console.ReadLine().Split(), Int32.Parse);
if (l[0] > l[1]) Console.WriteLine(">");
if (l[0] < l[1]) Console.WriteLine("<");
if (l[0] == l[1]) Console.WriteLine("==");