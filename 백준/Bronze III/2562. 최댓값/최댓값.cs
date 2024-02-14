int max = 0 , index = 0;
for(int i = 0; i < 9; i++)
{
    int n = Int32.Parse(Console.ReadLine());
    if (n >= max)
    {
        max = n;
        index = i + 1;
    }
}
Console.WriteLine($"{max}\n{index}");