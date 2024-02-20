int testcase=Int32.Parse(Console.ReadLine());
while(testcase--!=0)
{
    Console.ReadLine();
    Console.WriteLine(Enumerable.SequenceEqual(Console.ReadLine().Split().OrderBy(a=>a),Console.ReadLine().Split().OrderBy(a=>a))?"NOT CHEATER":"CHEATER");
}