var d=Int32.Parse(Console.ReadLine());
int t=d/3,p=d%3,r=2000;
for(int i=0;i<=t;i++)if((d-(3*i))%5==0)r=Math.Min(r,i+(d-(3*i))/5);
Console.WriteLine(r==2000?-1:r);