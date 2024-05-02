var Key1 = Console.ReadLine();
var Key2 = Console.ReadLine();

string shortKey = Key1.Length > Key2.Length ? Key2 : Key1;
string longKey = Key1.Length > Key2.Length ? Key1 : Key2;

int left = 0, right = 0, minLength = shortKey.Length + longKey.Length, currentLength;
for(int i = 0; i < shortKey.Length + longKey.Length - 1; i++) 
{
    int t = 0;
    bool isRight = true;
    currentLength = shortKey.Length + longKey.Length - (right - left + 1);

    if (left == 0) t += shortKey.Length - (right - left + 1);
    for (int j = left; j <= right; j++)
    {
        if (shortKey[t] == '2' && longKey[j] == '2')
        {
            isRight = false;
            break;
        }
        t++;
    }

    if (right < longKey.Length - 1) right++;
    if (right >= shortKey.Length) left++;

    if (!isRight) continue;

    minLength = Math.Min(minLength, currentLength);
    if (minLength == longKey.Length) break;
}

Console.Write(minLength);