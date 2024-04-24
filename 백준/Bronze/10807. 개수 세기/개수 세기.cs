Console.ReadLine();
var l = Console.ReadLine().Split().Select(int.Parse).ToList();
var n = int.Parse(Console.ReadLine());
int result = 0;
foreach(var t in l){
    if(t == n) result++;
}
Console.Write(result);