var s =  Console.ReadLine();
int prev = (int)s[0];
int t = 0, pt = (int)s[1] - (int)s[0];
bool result = true;
if (pt < 0) Console.WriteLine("NON ALPSOO");
else
{
    foreach (var c in s[1..])
    {
        int n = (int)c;
        t = n - prev;
        if(t == 0 || (pt * t > 0 && t != pt))
        {
            result = false;
            break;
        }
        pt = t;
        prev = n;
    }
    if (t > 0) result = false;
    Console.WriteLine(result ? "ALPSOO" : "NON ALPSOO");
}