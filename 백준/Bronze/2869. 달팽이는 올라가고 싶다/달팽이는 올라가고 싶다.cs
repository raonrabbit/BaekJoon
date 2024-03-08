var d = Array.ConvertAll(Console.ReadLine().Split(), Int32.Parse);
int result = (d[2] - d[0]) / (d[0] - d[1]) + ((d[2] - d[0]) % (d[0] - d[1]) != 0?1:0) + 1;
Console.WriteLine(result);