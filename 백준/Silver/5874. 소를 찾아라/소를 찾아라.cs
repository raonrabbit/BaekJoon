var s=Console.ReadLine();
char p=' ';
int c=0,r=0;
foreach(var t in s){
    if(p=='('&&t=='(')c++;
    if(p==')'&&t==')')r+=c;
    p=t;
}
Console.WriteLine(r);