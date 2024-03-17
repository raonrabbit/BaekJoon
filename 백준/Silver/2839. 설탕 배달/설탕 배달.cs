var d = Int32.Parse(Console.ReadLine());
int t = d / 3, p = d % 3, result = Int32.MaxValue;
bool yeah = false;
for(int i = 0; i <= t; i++){
    var n = (d - (3 * i)) / 5;
    if((d - (3 * i)) % 5 == 0)
    {
        result = Math.Min(result, i + n);
        yeah = true;
    }
}
Console.WriteLine(yeah?result:-1);