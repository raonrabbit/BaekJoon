int count=Int32.Parse(Console.ReadLine()),result=0;
var m=new Dictionary<string, Stack<string>>();
string t;
while(count--!=0){
    var l=Console.ReadLine().Split();
    if (!m.ContainsKey(l[0])){
        m.Add(l[0], new Stack<string>(new string[]{l[1]}));
        continue;
    }
    if (m[l[0]].TryPeek(out t)&&t=="+"&&l[1]=="-") m[l[0]].Pop();
    else m[l[0]].Push(l[1]);
}
foreach(var a in m){result+=a.Value.Count;}
Console.WriteLine(result);