var d=Console.ReadLine().Split().Select(int.Parse).ToList();
int min=int.MaxValue;
for(int i=0;i<d[0];i++)
{
    var t=Console.ReadLine().Split().Select(int.Parse).ToList();
    if (t[0]+t[1]*(t[2]-1)<d[1])continue;
    min=Math.Min(min,t[0]+((d[1] - t[0] <= 0)?0:(t[1]*((d[1]-t[0])/t[1]+(((d[1]-t[0])%t[1]==0)?0:1)))));
}
Console.Write(min==int.MaxValue?-1:min-d[1]);