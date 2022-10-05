# (b) To write a python program for tower of Hanoi Scenario


def towerofhanoi(n, fromrod, torod, auxrod):
    if n == 1:
        print("Move disk 1 from rod", fromrod, "to rod", torod)
        return
    towerofhanoi(n-1, fromrod, auxrod, torod)
    print("Move disk", n, "from rod", fromrod, "to rod", torod)
    towerofhanoi(n-1, auxrod, torod, fromrod)

n=int(input("Enter number of disks: "))
towerofhanoi(n, 'A', 'C', 'B')