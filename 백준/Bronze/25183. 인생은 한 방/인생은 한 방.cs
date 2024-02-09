Console.ReadLine();
int count = 1;
char prevChar = '0';
foreach (char c in Console.ReadLine().ToCharArray())
{
    count = (c == prevChar - 1 || c == prevChar + 1) ? count + 1 : 1;
    if(5 <= count)
    {
        Console.WriteLine("YES");
        return;
    }
    prevChar = c;
}
Console.WriteLine("NO");