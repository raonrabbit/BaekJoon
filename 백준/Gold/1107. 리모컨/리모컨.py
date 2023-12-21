currentChanel = 100
chanel = int(input())
brokenButtonsCount = int(input())
brokenButtons = []

if(brokenButtonsCount > 0):
    brokenButtons = input().split()
        
min = float('inf')
for i in range(999999):
    if not any(buttons in str(i) for buttons in brokenButtons):
        if min > abs(chanel - i) + len(str(i)):
            min = abs(chanel - i) + len(str(i))

FindWithChanelNumber = min
FindWithUpDownNumber = abs(currentChanel - chanel)

print(FindWithChanelNumber if FindWithChanelNumber < FindWithUpDownNumber else FindWithUpDownNumber)