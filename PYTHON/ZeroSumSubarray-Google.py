"""Here return the subarray having the Sum = 0
NOTE:- The complexity must be O(n)"""

# from time import time

data = list(map(int, input().split()))  # 4 1 -1 2 -1 3
# start = time()                                      #4 5  4 6 5 7
new = []
seen = set()
i = 0
for a in data:
    if len(new) == 0:
        new.append(a)
        seen.add(a)
    else:
        new.append(new[i] + a)
        if (new[i] + a) not in seen:
            seen.add(new[i] + a)
        else:
            print(f"{new.index(new[i] +a) +1} -->  {i +1}")
            break
        print(seen)
        i += 1
# print(time() - start)
print(new)
