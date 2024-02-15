using System.Collections;
int count = 0, max = 0, n = Int32.Parse(Console.ReadLine());
string s = Console.ReadLine();
Stack stack = new Stack();
char pc = ' ';
bool isPoped = false;
foreach(char c in s)
{
    if(stack.Count > 0 && !stack.Peek().Equals(c))
    {
        isPoped = true;
        pc = c;
        stack.Pop();
        count++;
        continue;
    }
    if (max < count) max = count;
    if (isPoped){
        stack.Clear();
        for (int i = 0; i < count; i++) stack.Push(pc);
        isPoped = false;
        if (stack.Count > 0 && !stack.Peek().Equals(c))
        {
            isPoped = true;
            pc = c;
            stack.Pop();
            count = 1;
            continue;
        }
    }
    stack.Push(c);
    count = 0;
}
if (max < count) max = count;
Console.WriteLine(max * 2);