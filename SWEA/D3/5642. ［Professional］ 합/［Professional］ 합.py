T = int(input())

for test_case in range(1, T + 1):
    input()
    num_list = list(map(int, input().split()))
    current_max = 0;
    max_list = []
    for i in range(len(num_list)):
        if current_max >= 0:
            current_max += num_list[i]
            max_list.append(current_max)
        else:
            current_max = num_list[i]
            max_list.append(current_max)

    print(f'#{test_case} {max(max_list)}')