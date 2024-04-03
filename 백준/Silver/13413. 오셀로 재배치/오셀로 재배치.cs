Func<string> i = () => Console.ReadLine();
int T = int.Parse(i());
while (T-- != 0)
{
    int t = int.Parse(i()), w = 0, b = 0;
    string N = i(), M = i();
    for(int j = 0; j < t; j++)
    {
        if (N[j] == M[j]) continue;
        if (M[j] == 'W') w++;
        else b++;
    }

    Console.WriteLine(Math.Max(w, b));
}