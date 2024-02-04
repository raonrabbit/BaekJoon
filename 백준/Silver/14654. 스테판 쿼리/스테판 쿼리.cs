class Program
{
    static void Main(string[] args)
    {
        List<int[]> teams = new List<int[]>();
        int round = Int32.Parse(Console.ReadLine());
        int result = 0;

        for (int i = 0; i < 2; i++)
        {
            teams.Add(Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse));
        }

        int count = 0;
        int lastWon = -1;
        for (int i = 0; i < round; i++)
        {
            int winner = calRSP(teams[0][i], teams[1][i]);
            if (winner == lastWon) count++;
            else
            {
                if (count > result) result = count;
                if (winner == -1) winner = Math.Abs(lastWon - 1);
                lastWon = winner;
                count = 1;
            }
        }
        if (count > result) result = count;
        Console.WriteLine(result);
    }


    static int calRSP(int team0, int team1)
    {
        switch (team0 - team1)
        {
            case -1:
                return 1;
            case 1:
                return 0;
            case -2:
                return 0;
            case 2:
                return 1;
            case 0:
                return -1;
        }
        return -2;
    }
}