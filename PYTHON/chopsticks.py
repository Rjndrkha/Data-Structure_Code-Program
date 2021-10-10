import time
from os import system, name

class player:
    def __init__(self) -> None:
        self.left=1
        self.right=1

def clear():
  
    # for windows
    if name == 'nt':
        _ = system('cls')
  
    # for mac and linux(here, os.name is 'posix')
    else:
        _ = system('clear')

def game():
    current=0
    run=True
    p1=player()
    p2=player()

    print("Current Status: ")
    print(f'player 1- {p1.left} {p1.right}')
    print(f'player 2- {p2.left} {p2.right}')


    while(run):

        if(current==0):
            move=input('Enter move for player 1: ')

            if((p1.right==0 and p1.left==1 or p1.left==0 and p1.right==1) and move=='S'):
                print("You can only attack in this turn")
                move='A'

            if(move=='A'):
                invalid=True
                while(invalid):
                    inp=input('Enter Move combination for player 1: ').split()
                    if(inp[0]=='R' and inp[1]=='R'):
                        if(p1.right!=0 and p2.right!=0):
                            p2.right+=(p1.right)
                            p2.right=p2.right%5
                            invalid=False
                        else:
                            print("Invalid move!")
                            continue


                    elif(inp[0]=='R' and inp[1]=='L'):
                        if(p1.right!=0 and p2.left!=0):
                            p2.left+=(p1.right)
                            p2.left=p2.left%5
                            invalid=False
                        else:
                            print("Invalid move!")
                            continue

                    elif(inp[0]=='L' and inp[1]=='L'):
                        if(p1.left!=0 and p2.left!=0):
                            p2.left+=(p1.left)
                            p2.left=p2.left%5
                            invalid=False
                        else:
                            print("Invalid move!")
                            continue

                    elif(inp[0]=='L' and inp[1]=='R'):
                        if(p1.left!=0 and p2.right!=0):
                            p2.right+=(p1.left)
                            p2.right=p2.right%5
                            invalid=False
                        else:
                            print("Invalid move!")
                            continue

            elif(move=='S'):
                invalid=True
                while(invalid):
                    inp=input('Enter move combination for player 1: ').split()
                    lef=int(inp[1])
                    rig=int(inp[2])
                    if(lef+rig==p1.right+p1.left):
                        if(lef!=p1.left and rig!=p1.right) and (lef!=p1.right and rig!=p1.left):
                            invalid=False
                            p1.right=rig%5
                            p1.left=lef%5
                        
                        else:
                            print("Invalid move!")
                            continue
                    
                    else:
                        print("Invalid move")
                        continue
            
            current=1-current

        elif(current==1):
            move=input('Enter move for player 2: ')

            if((p2.right==0 and p2.left==1 or p2.left==0 and p2.right==1) and move=='S'):
                print("You can only attack in this turn")
                move='A'

            if(move=='A'):
                invalid=True
                while(invalid):
                    inp=input('Enter Move combination for player 2: ').split()
                    if(inp[0]=='R' and inp[1]=='R'):
                        if(p2.right!=0 and p1.right!=0):
                            p1.right+=(p2.right)
                            p1.right=p1.right%5
                            invalid=False
                        else:
                            print("Invalid move!")
                            continue


                    elif(inp[0]=='R' and inp[1]=='L'):
                        if(p2.right!=0 and p1.left!=0):
                            p1.left+=(p2.right)
                            p1.left=p1.left%5
                            invalid=False
                        else:
                            print("Invalid move!")
                            continue

                    elif(inp[0]=='L' and inp[1]=='L'):
                        if(p2.left!=0 and p1.left!=0):
                            p1.left+=(p2.left)
                            p1.left=p1.left%5
                            invalid=False
                        else:
                            print("Invalid move!")
                            continue

                    elif(inp[0]=='L' and inp[1]=='R'):
                        if(p2.left!=0 and p1.right!=0):
                            p1.right+=(p2.left)
                            p1.right=p1.right%5
                            invalid=False
                        else:
                            print("Invalid move!")
                            continue

            elif(move=='S'):
                invalid=True
                while(invalid):
                    inp=input('Enter move combination for player 2: ').split()
                    lef=int(inp[1])
                    rig=int(inp[2])
                    if(lef+rig==p2.right+p2.left):
                        if(lef!=p2.left and rig!=p2.right) and (lef!=p2.right and rig!=p2.left):
                            invalid=False
                            p2.right=rig%5
                            p2.left=lef%5
                        
                        else:
                            print("Invalid move!")
                            continue
                    
                    else:
                        print("Invalid move")
                        continue
            
            current=1-current

        print("Current Status: ")
        print(f'player 1- {p1.left} {p1.right}')
        print(f'player 2- {p2.left} {p2.right}')

        if(p1.right==0 and p1.left==0):
            print("Player 2 has won!")
            run=False

        if(p2.right==0 and p2.left==0):
            print("Player 1 has won!")
            run=False

           
play=True
while(play):
    game()
    print('New game in',end=' ')
    time.sleep(1)
    print(5,end=' ')
    time.sleep(1)
    print(4,end=' ')
    time.sleep(1)
    print(3,end=' ')
    time.sleep(1)
    print(2,end=' ')
    time.sleep(1)
    print(1,end=' ')
    time.sleep(1)

    clear()