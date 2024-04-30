while(true){
    var l = Console.ReadLine().Split().Select(int.Parse).ToList();
    if(l[0] == 0 && l[1] == 0) break;
    
    Console.WriteLine(l[0] > l[1] ? "Yes" : "No");
}