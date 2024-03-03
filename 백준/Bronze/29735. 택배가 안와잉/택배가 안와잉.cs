var t = Console.ReadLine().Split();
var st = Array.ConvertAll(t[0].Split(':'), Int32.Parse);
int stn = st[0] * 60 + st[1];
var et = Array.ConvertAll(t[1].Split(':'), Int32.Parse);
int etn = et[0] * 60 + et[1];

var d = Array.ConvertAll(Console.ReadLine().Split(), Int32.Parse);
int resultDay = 0, resultTime = stn;
for(int i = 0; i <= d[0]; i++)
{
    if (resultTime + d[1] >= etn)
    {
        resultDay++;
        resultTime = stn + d[1];
    }
    else
    {
        resultTime += d[1];
    }
}
Console.WriteLine(resultDay);
Console.WriteLine($"{string.Format("{0:D2}", resultTime / 60)}:{string.Format("{0:D2}", resultTime % 60)}");