import itertools
import os

full_path = os.path.realpath(__file__)
path, filename = os.path.split(full_path)
dataset = path + "\\dataset_ar.txt"

"""prompt user to enter support and confidence values in percent"""

support = int(input("Please enter support value in %: "))
confidence = int(input("Please enter convidence value in %: "))

"""Compute candidate 1-itemset"""
C1 = {}
"""total number of transactions contained in the file"""
transactions = 0
D = []
T = []
with open(dataset, "r") as f:
    for line in f:
        T = []
        transactions += 1
        for word in line.split():
            T.append(word)
            if word not in C1.keys():
                C1[word] = 1
            else:
                count = C1[word]
                C1[word] = count + 1
        D.append(T)

print("---------------------------Test Dataset---------------------------")
print(D)
print("------------------------------------------------------------------")
# print("---------------------------Candidate 1-ITEMSET------------------")
# print(C1)
# print("----------------------------------------------------------------")

"""Compute frequent 1-itemset"""
L1 = []
for key in C1:
    if(100 * C1[key]/transactions) >= support:
        list = []
        list.append(key)
        L1.append(list)
print("---------------------------Frequent 1-ITEMSET---------------------")
print(L1)
print("------------------------------------------------------------------")

"""apriori_gen function to compute candidate k-itemset, (ck), using frequent (k-1)-itemset"""

def apriori_gen(LK_1, k):
    length = k
    CK = []
    for list1 in LK_1:
        for list2 in LK_1:
            count = 0
            c = []
            if list1 != list2:
                while count < length-1:
                    if list1[count] != list2[count]:
                        break
                    else:
                        count += 1
                else:
                    if list1[length-1] < list2[length-1]:
                        for item in list1:
                            c.append(item)
                        c.append(list2[length-1])
                        if not has_infrequent_subset(c, LK_1, k):
                            CK.append(c)
                            c = []
    return CK

"""function to compute 'm' element subset of a set S"""

def findsubsets(S,m):
    return set(itertools.combinations(S,m))

"""has_infrequent_subsets function to determine if pruning is required to remove unfruitful candidates (c) using the Apriori"""

def has_infrequent_subset(c, LK_1, k):
    list = []
    list = findsubsets(c,k)
    for item in list:
        s = []
        for l in item:
            s.append(l)
        s.sort()
        if s not in LK_1:
            return True
    return False

"""frequent_itemsets function to compute all frequent itemsets"""

def frequent_itemsets():
    k = 2
    LK_1 = []
    LK = []
    L = []
    count = 0
    transactions = 0
    for item in L1:
        LK_1.append(item)
    while LK_1 != []:
        CK = []
        LK = []
        CK = apriori_gen(LK_1, k-1)
        # print("---------------------------Candidate %d-ITEMSET------------------")
        # print("CK: %s" % CK)
        # print("-----------------------------------------------------------------")
        for c in CK:
            count = 0
            transactions = 0
            s = set(c)
            for T in D:
                transactions += 1
                t = set(T)
                if s.issubset(t) == True:
                    count += 1
            if(100 * count/transactions) >= support:
                c.sort()
                LK.append(c)
        LK_1 = []
        print("---------------------------Frequent %d-ITEMSET---------------------" % k)
        print(LK)
        print("------------------------------------------------------------------")
        for l in LK:
            LK_1.append(l)
        k += 1
        if LK != []:
            L.append(LK)

    return L

"""generate_association_rules function to mine and print all the association rules with given support and confidence"""

def generate_association_rules():
    s = []
    r = []
    length = 0
    count = 1
    inc1 = 0
    inc2 = 0
    num = 1
    m = []
    L = frequent_itemsets()
    print("---------------------------ASSOCIATION RULES---------------------------")
    print("RULES \t SUPPORT \t CONFIDENCE")
    print("-----------------------------------------------------------------------")
    for list in L:
        for l in list:
            length = len(l)
            count = 1
            while count < length:
                s = []
                r = findsubsets(l,count)
                count += 1
                for item in r:
                    inc1 = 0
                    inc2 = 0
                    s = []
                    m = []
                    for i in item:
                        s.append(i)
                    for T in D:
                        if set(s).issubset(set(T)) == True:
                            inc1 += 1
                        if set(l).issubset(set(T)) == True:
                            inc2 += 1
                    if 100*inc2/inc1 >= confidence:
                        for index in l:
                            if index not in s:
                                m.append(index)
                        print("Rule# %d : %s ==> %s %d %d" %(num, s, m, 100*inc2/len(D), 100*inc2/inc1))
                        num += 1

generate_association_rules()
print("-----------------------------------------------------------------------")