var month = new List<int>() { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
var d1 = Array.ConvertAll(Console.ReadLine().Split(), Int32.Parse);
var d2 = Array.ConvertAll(Console.ReadLine().Split(), Int32.Parse);
int result = 0;
if (d1[0] + 1000 < d2[0] || (d1[0] + 1000 == d2[0] && (d1[1] < d2[1] || (d1[1] == d2[1] && d1[2] <= d2[2])))){
    Console.WriteLine("gg");
}
else {
    while (true) {
        if (d1[0] % 400 == 0 || (d1[0] % 100 != 0 && d1[0] % 4 == 0)) month[1] = 29;
        else month[1] = 28;
        if (d1[2] < month[d1[1] - 1]) d1[2]++;
        else
        {
            if (d1[1] < 12)
            {
                d1[1]++;
                d1[2] = 1;
            }
            else
            {
                d1[0]++;
                d1[1] = 1;
                d1[2] = 1;
            }
        }
        result++;
        if (d1[0] == d2[0] && d1[1] == d2[1] && d1[2] == d2[2])
        {
            Console.WriteLine($"D-{result}");
            break;
        }
    }
}