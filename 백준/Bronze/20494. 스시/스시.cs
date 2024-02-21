int n = Int32.Parse(Console.ReadLine()), result = 0;
for(int i = 0; i < n; i++) result += Console.ReadLine().Count();
Console.WriteLine(result);