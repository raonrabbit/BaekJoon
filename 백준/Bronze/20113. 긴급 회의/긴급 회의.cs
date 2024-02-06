class Program
{
    public static void Main(string[] args)
    {
        int result;
        int playerCount = Int32.Parse(Console.ReadLine());
        int[] votelist = Array.ConvertAll(Console.ReadLine().Split(' '), Int32.Parse);
        List<int> voteCount = new List<int>(new int[playerCount]);
        foreach(int vote in votelist)
            if(vote != 0)
                voteCount[vote - 1] += 1;
        result = voteCount.IndexOf(voteCount.Max()) + 1;
        var sortedList = voteCount.OrderByDescending(x => x).ToList();
        if (sortedList[0] == sortedList[1]) Console.WriteLine("skipped");
        else Console.WriteLine(result);
    }
}