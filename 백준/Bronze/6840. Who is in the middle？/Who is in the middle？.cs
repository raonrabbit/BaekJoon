var l = new List<int>();
for(int i = 0; i < 3; i++){
    l.Add(int.Parse(Console.ReadLine()));
}
l.Sort();
Console.Write(l[1]);