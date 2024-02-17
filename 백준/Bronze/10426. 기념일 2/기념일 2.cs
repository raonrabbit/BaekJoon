using System.ComponentModel.Design.Serialization;

var month = new List<int>() { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
var l = Console.ReadLine().Split();
var d = Array.ConvertAll(l[0].Split('-'), Int32.Parse);
for (int i = 1; i < Int32.Parse(l[1]); i++)
{
    if (d[0] % 400 == 0 || (d[0] % 100 != 0 && d[0] % 4 == 0)) month[1] = 29;
    else month[1] = 28;
    if (d[2] < month[d[1] - 1]) d[2]++;
    else
    {
        if (d[1] < 12)
        {
            d[1]++;
            d[2] = 1;
        }
        else
        {
            d[0]++;
            d[1] = 1;
            d[2] = 1;
        }
    }
}

Console.WriteLine($"{d[0]:D4}-{d[1]:D2}-{d[2]:D2}");