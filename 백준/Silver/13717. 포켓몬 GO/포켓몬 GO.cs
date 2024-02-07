string resultPokemon = "";
int evolutionCount = 0;
int max = 0;
int pokeCount = Int32.Parse(Console.ReadLine());
for(int i = 0; i < pokeCount; i++)
{
    string pokemon = Console.ReadLine();
    List<int> candyInfo = Array.ConvertAll(Console.ReadLine().Split(), Int32.Parse).ToList<int>();
    int currentEvolutionCount = 0;
    while (candyInfo[0] <= candyInfo[1])
    {
        currentEvolutionCount++;
        candyInfo[1] = candyInfo[1] - candyInfo[0] + 2;
    }
    evolutionCount += currentEvolutionCount;
    if(max < currentEvolutionCount)
    {
        resultPokemon = pokemon;
        max = currentEvolutionCount;
    }
}
Console.WriteLine(evolutionCount);
Console.WriteLine(resultPokemon);