if __name__=='__main__':

    for _ in range(int(input())):

        n , m = map(int,input().split())

        A = list(map(int,input().rstrip().split()))

        B = list(map(int,input().rstrip().split()))

        s = 0

        A = list(set(A))
        B = list(set(B))

        for i in A:
            for j in B:
                if i==j:
                    s+=1
        
        if(s==len(B)):
            print("Yes")
        else:
            print("No")