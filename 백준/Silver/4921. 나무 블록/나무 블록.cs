var blockInfo = new List<int[]>() { 
    new int[] { 0, -1},
    new int[] { -1, 0 },
    new int[] { -1, -1 },
    new int[] { 1, 1 },
    new int[] { 1, -2 },
    new int[] { -2, 1 },
    new int[] { -2, -2 },
    new int[] { 2, 2 } 
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
        if (right == 0 || right + blockInfo[n - '0' - 1][0] != 0) isValid = false;
        right = blockInfo[n - '0' - 1][1];
    }
    result.Add(isValid);
}

for(int i = 1; i <= result.Count; i++)
{
    if (result[i - 1]) Console.WriteLine(i + ". VALID");
    else Console.WriteLine(i + ". NOT");
}