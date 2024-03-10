var s = Console.ReadLine().ToArray().Select(x => x.ToString()).ToList();
int zC = 0, oC = 0;
foreach(var c in s)
{
    if (c == "0") zC++;
    else oC++;
}
zC /= 2;
oC /= 2;
for (int i = 0; i < s.Count; i++){
    if (oC == 0) break;
    if (s[i] == "1")
    {
        s.RemoveAt(i--);
        oC--;
    }
}
for(int i = s.Count - 1; i >= 0; i--) {
    if (zC == 0) break;
    if (s[i] == "0")
    {
        s.RemoveAt(i);
        zC--;
    }
}
foreach (var c in s) Console.Write(c);