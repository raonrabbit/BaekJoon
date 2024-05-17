T = int(input())

for test_case in range(1, T + 1):
    result = 0
    l = list(map(int, input().split()))
    l.reverse()
    prev = l[0]

    for num in l[1:]:
        if prev <= num:
            result += num - prev + 1
            prev -= 1
        else:
            prev = num

    if prev <= 0:
        print(f'#{test_case} {-1}')
    else:
        print(f'#{test_case} {result}')
