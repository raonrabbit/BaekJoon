Dictionary<int, int> numberCount = new Dictionary<int, int>();
int result = 1;
string roomNumber = Console.ReadLine();

for(int i = 0; i < 10; i++)
{
    numberCount.Add(i, 1);
}

for(int i = 0; i < roomNumber.Length; i++)
{
    int currentNumber = roomNumber[i] - '0';
    if (numberCount[currentNumber] == 0)
    {
        if (currentNumber == 6 && numberCount[9] != 0)
        {
            numberCount[9]--;
            continue;
        }
        if (currentNumber == 9 && numberCount[6] != 0)
        {
            numberCount[6]--;
            continue;
        }

        result++;
        foreach (KeyValuePair<int, int> data in numberCount)
        {
            numberCount[data.Key]++;
        }
    }

    numberCount[currentNumber]--;
}

Console.WriteLine(result);