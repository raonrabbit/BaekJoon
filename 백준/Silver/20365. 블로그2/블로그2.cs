int n=int.Parse(Console.ReadLine()),b=0,r=0;
var s=Console.ReadLine();
char c='0';
for (int i=0;i<n;i++)
{
    if (c==s[i])continue;
    if (s[i]=='B')b++;
    else r++;
    c=s[i];
}
Console.Write(1 + Math.Min(b, r));