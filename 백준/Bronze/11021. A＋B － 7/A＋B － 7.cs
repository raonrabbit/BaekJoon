var n = int.Parse(Console.ReadLine());

for(int i = 0; i < n; i++){
    var l = Console.ReadLine().Split().Select(int.Parse).ToList();
    Console.WriteLine($"Case #{i+1}: {l[0] + l[1]}");
}