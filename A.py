first = input()
second = input()
subs = first.split()
subs2 = second.split()
i = 0
n = int(subs[0])
k = int(subs[1])
while i < k:
    if subs2[i] == 'undo':
        amount = subs2[i+1]
        