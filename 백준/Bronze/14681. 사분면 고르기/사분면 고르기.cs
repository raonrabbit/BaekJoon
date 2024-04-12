int x = int.Parse(Console.ReadLine());
int y = int.Parse(Console.ReadLine());
if(x > 0)
{
    if (y > 0) Console.Write(1);
    else Console.Write(4);
}
else
{
    if (y > 0) Console.Write(2);
    else Console.Write(3);
}