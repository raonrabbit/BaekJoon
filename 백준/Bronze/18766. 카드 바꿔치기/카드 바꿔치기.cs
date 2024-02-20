int testcase = Int32.Parse(Console.ReadLine());
while(testcase-- != 0)
{
    Console.ReadLine();
    if (Enumerable.SequenceEqual(Console.ReadLine().Split().OrderBy(a => a), Console.ReadLine().Split().OrderBy(a => a))) Console.WriteLine("NOT CHEATER");
    else Console.WriteLine("CHEATER");
}