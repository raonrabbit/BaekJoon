bool[ , ] l = new bool[100, 100];
int result = 0;
for(int i = 0; i < 4; i++)
{
    var r = Array.ConvertAll(Console.ReadLine().Split(), Int32.Parse);
    for(int h = r[1]; h < r[3]; h++)
        for(int w = r[0]; w < r[2]; w++) l[h, w] = true;
}

for (int h = 0; h < 100; h++)
    for (int w = 0; w < 100; w++)
        if (l[h, w]) result++;
Console.WriteLine(result);