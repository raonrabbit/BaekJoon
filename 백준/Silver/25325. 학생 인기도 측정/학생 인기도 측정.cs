int studentCount = Int32.Parse(Console.ReadLine());
var dict = Console.ReadLine().Split(' ').ToDictionary(str => str, str => 0);
for (int i = 0; i < studentCount; i++) foreach(var name in Console.ReadLine().Split().ToList()) dict[name] += 1;
dict = dict.OrderByDescending(x => x.Value).ToDictionary(x => x.Key, x => x.Value);
foreach(KeyValuePair<string, int> e in dict) System.Console.WriteLine($"{e.Key} {e.Value}");