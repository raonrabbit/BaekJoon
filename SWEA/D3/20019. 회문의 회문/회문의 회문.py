T = int(input())

def calPalindrome(s):
    s1 = s[0:len(s) // 2]
    s2 = s[len(s) // 2 + len(s) % 2:]
    return s1 == s2[::-1]

for test_case in range(1, T + 1):
    s = input()

    if calPalindrome(s) and calPalindrome(s[0:len(s) // 2]):
        print(f'#{test_case} YES')
    else:
        print(f'#{test_case} NO')