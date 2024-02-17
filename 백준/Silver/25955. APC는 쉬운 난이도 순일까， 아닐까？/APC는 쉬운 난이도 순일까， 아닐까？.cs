var TT = new Dictionary<char, int>(){ 
    { 'B', 0 },
    { 'S', 1 },
    { 'G', 2 },
    { 'P', 3 },
    { 'D', 4 } };
int count = Int32.Parse(Console.ReadLine());
var tier = Console.ReadLine().Split();
var sTier = tier.ToList();
string temp;
for(int i = 0; i < count; i++)
{
    for(int j = 0; j < count - i - 1; j++)
    {
        if (TT[sTier[j][0]] > TT[sTier[j + 1][0]] ||
            ((sTier[j][0] == sTier[j + 1][0]) && Int32.Parse(sTier[j][1..]) < Int32.Parse(sTier[j + 1][1..])))
        {
            temp = sTier[j];
            sTier[j] = sTier[j + 1];
            sTier[j + 1] = temp;
            continue;
        }
    }
}

var result = new List<string>();
for(int i = 0; i < count; i++)
{
    if (sTier[i] != tier[i]) result.Add(tier[i]);
}
if (result.Count == 0) Console.WriteLine("OK");
else Console.WriteLine($"KO\n{result[1]} {result[0]}");