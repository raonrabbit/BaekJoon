Func<int> f=()=>int.Parse(Console.ReadLine());
int n=f(),min=int.MaxValue,result=0;
var l = new List<int>();
for(int i = 0; i < n; i++)l.Add(f());
l.Sort();
l.Reverse();
for(int i = 0; i < n; i++) result = Math.Max(result, l[i] * (i + 1));
Console.Write(result);