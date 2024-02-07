Console.ReadLine();
int max = 0, start = 0, prev = -1;
foreach(int a in Array.ConvertAll(Console.ReadLine().Split(), Int32.Parse)){
    if (prev == -1) prev = a;
    if (a > prev) max = (max < a - start) ? (a - start) : max;
    else start = a;
    prev = a;
}
Console.WriteLine(max);