var info = new int[8, 2] { 
    { 0, -1},
    { -1, 0 },
    { -1, -1 },
    { 1, 1 },
    { 1, -2 },
    { -2, 1 },
    { -2, -2 },
    { 2, 2 } 
};
var result = new List<bool>();
while (true)
{
    bool isValid = true;
    string input = Console.ReadLine();
    if (input == "0") break;
    if (input[0] != '1' || input[input.Length - 1] != '2')
    {
        result.Add(false);
        continue;
    }
    int right = -1;
    foreach (var n in input.Substring(1))
    {
        var t = n - 1 - '0';
        if (right == 0 || right + info[t, 0] != 0) isValid = false;
        right = info[t, 1];
    }
    result.Add(isValid);
}

for(int i = 1; i <= result.Count; i++)
{
    if (result[i - 1]) Console.WriteLine($"{i}. VALID");
    else Console.WriteLine($"{i}. NOT");
}