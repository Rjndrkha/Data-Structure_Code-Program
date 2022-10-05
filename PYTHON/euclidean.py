import math

def calc_euclid(array, array1):
    # print('Euclidean distance : \n' ,math.sqrt(((a-c)*(a-c))+(b-d)*(b-d)))
    euc = 0

    def sq(num):
        return math.pow(num, 2)
    for i in range(len(array)):
        euc += sq(array[i]-array1[i])

    return math.sqrt(euc)

point1 = [4, 4, 2]
point2 = [1, 2, 1]

print(calc_euclid(point1, point2))
