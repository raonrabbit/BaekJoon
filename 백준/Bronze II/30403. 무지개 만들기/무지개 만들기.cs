Console.ReadLine();
string S = "ROYGBIV", s = "roygbiv", a = Console.ReadLine(); ;
bool S1 = true, S2 = true;
for (int i = 0; i < 7; i++)
{
    if (!a.Contains(S[i])) S1 = false;
    if (!a.Contains(s[i])) S2 = false;
}
Console.WriteLine((S1) ? ((S2) ? "YeS" : "YES") : ((S2) ? "yes" : "NO!"));
