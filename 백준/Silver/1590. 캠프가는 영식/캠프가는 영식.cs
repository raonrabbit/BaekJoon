var d=Console.ReadLine().Split().Select(int.Parse).ToList();
int m=2147483647;
for(int i=0;i<d[0];i++){
    var t=Console.ReadLine().Split().Select(int.Parse).ToList();
    m=Math.Min(m,(t[0]+t[1]*(t[2]-1)<d[1])?m:t[0]+((d[1]-t[0]<=0)?0:(t[1]*((d[1]-t[0])/t[1]+(((d[1]-t[0])%t[1]==0)?0:1)))));
}
Console.Write(m==2147483647?-1:m-d[1]);