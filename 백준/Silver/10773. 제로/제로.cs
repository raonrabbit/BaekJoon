long d=long.Parse(Console.ReadLine()),r=0;
var s=new Stack<long>();
while (d--!=0){
    var n=long.Parse(Console.ReadLine());
    if (n==0)r-=s.Pop();
    else s.Push(n);
    r+=n;
}
Console.Write(r);