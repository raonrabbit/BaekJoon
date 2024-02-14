var n = Int32.Parse(Console.ReadLine());
for (int j = 0; j < n; j++)
{
    var l = Console.ReadLine().Split();
    for (int i = 0; i < l[1].Length; i++)
    {
        for(int t = 0; t < Int32.Parse(l[0]); t++)
        {
            Console.Write(l[1][i]);
        }
    }
    Console.WriteLine();
}