var a = Array.ConvertAll(Console.ReadLine().Split(), Int32.Parse);
for(int k=a[0]; k<8; k++){
    var t = Array.ConvertAll(Console.ReadLine().Split(), Int32.Parse);
    a[1]+=(t[0]<=6)?t[0]*3:18;
    a[2]+=(t[0]+t[1] <= 6)?(t[0]+t[1])*3:18;
}
if(a[1]<66||a[2]<130) Console.WriteLine("Nae ga wae");
else Console.WriteLine("Nice");