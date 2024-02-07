class Program
{
    static bool cal(Stack<string> s, string key, int value)
    {
        int num = 0, n;
        if (s.Count == 0) return false;
        while (s.Count != 0 && s.Peek() != key)
        {
            if (Int32.TryParse(s.Peek(), out n))
            {
                num += n;
                s.Pop();
            }
            else if (s.Peek() != key) return false;
        }
        if (s.Count == 0) return false;
        s.Pop();
        if (num != 0) s.Push((num * value).ToString());
        else s.Push((value).ToString());
        return true;
    }
    static int Main(string[] args)
    {
        List<char> s = new List<char>(Console.ReadLine());
        Stack<string> stack = new Stack<string>();
        for (int i = 0; i < s.Count; i++)
        {
            if (s[i] == '(' || s[i] == '[')
            {
                stack.Push(s[i].ToString());
                continue;
            }

            if (s[i] == ')' && !cal(stack, "(", 2))
            {
                Console.WriteLine(0);
                return 0;
            }

            if (s[i] == ']' && !cal(stack, "[", 3))
            {
                Console.WriteLine(0);
                return 0;
            }
        }
            int num = 0, n;
        while (stack.Count > 0 && Int32.TryParse(stack.Peek(), out n))
        {
            num += n;
            stack.Pop();
        }
        if (stack.Count > 0) Console.WriteLine("0");
        else Console.WriteLine(num);

        return 0;
    }
}