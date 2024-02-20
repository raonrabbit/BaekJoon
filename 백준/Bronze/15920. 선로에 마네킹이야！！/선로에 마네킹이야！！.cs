Console.ReadLine();
var l=Console.ReadLine().Split('W');
Console.WriteLine(l.Length<3?0:l[1].Length!=0?6:l[0].Length%2==0?5:1);