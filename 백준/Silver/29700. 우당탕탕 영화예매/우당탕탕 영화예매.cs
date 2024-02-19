var input = Array.ConvertAll(Console.ReadLine().Split(), Int32.Parse);
int result = 0;
int count = 0;
for (int i = 0; i < input[0]; i++)
{
    var seat = Console.ReadLine();
    count = 0;
    for(int idx = 0; idx < input[1]; idx++)
    {
        if (seat[idx] == '0') count++;
        else {
            if (count >= input[2]) 
                result += count - input[2] + 1;
            count = 0;
        }
    }
    if (count >= input[2]) result += count - input[2] + 1;
}
Console.WriteLine(result);