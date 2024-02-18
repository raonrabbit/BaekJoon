var input = Array.ConvertAll(Console.ReadLine().Split(), Int32.Parse);
int result = 0;
for (int i = 0; i < input[0]; i++)
{
    var seat = Console.ReadLine();
    for(int idx = 0; idx <= input[1] - input[2]; idx++)
    {
        bool b = true;
        for(int j = 0; j < input[2]; j++)
        {
            if (seat[idx + j] != '0')
            {
                b = false;
                break;
            }
        }
        if (b) result++;
    }
}
Console.WriteLine(result);