class Program
{
    public static void Main()
    {
        bool isLiar = false;
        int min = 0, max = 11;
        List<string> result = new List<string>();
        while (true)
        {
            int prediction = Int32.Parse(Console.ReadLine());
            if (prediction == 0) break;

            string answer = Console.ReadLine();
            if (answer == "too high")
            {
                if (min >= prediction) isLiar = true;
                else if (prediction < max) max = prediction;
            }
            if (answer == "too low")
            {
                if (max <= prediction) isLiar = true;
                else if (min < prediction) min = prediction;
            }
            if (answer == "right on")
            {
                if (!isLiar && min < prediction && prediction < max) result.Add("Stan may be honest");
                else result.Add("Stan is dishonest");
                isLiar = false;
                min = 0;
                max = 11;
            }
        }
        foreach (string s in result) Console.WriteLine(s);
    }
}