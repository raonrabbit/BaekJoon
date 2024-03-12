var d = Array.ConvertAll(Console.ReadLine().Split(), Int32.Parse);
var l = Array.ConvertAll(Console.ReadLine().Split(), Int32.Parse).ToList();
l.Sort();
int i = 0, result = d[1];
while (i < l.Count) {
    if (result >= l[i++]) result++;
    else break;
}
Console.WriteLine(result);