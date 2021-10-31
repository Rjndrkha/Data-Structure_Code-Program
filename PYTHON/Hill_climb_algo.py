import math

increment = 0.1
startingPoint = [1, 1]
point1 = [1,5]
point2 = [6,4]
point3 = [5,2]
point4 = [2,1]
def distance(x1, y1, x2, y2):
    dist = math.pow(x2-x1, 2) + math.pow(y2-y1, 2)
    return dist
def sumOfDistances(x1, y1, px1, py1, px2, py2, px3, py3, px4, py4):
    d1 = distance(x1, y1, px1, py1)
    d2 = distance(x1, y1, px2, py2)
    d3 = distance(x1, y1, px3, py3)
    d4 = distance(x1, y1, px4, py4)
    return d1 + d2 + d3 + d4
def newDistance(x1, y1, point1, point2, point3, point4):
    d1 = [x1, y1]
    d1temp = sumOfDistances(x1, y1, point1[0],point1[1], point2[0],point2[1],
    point3[0],point3[1], point4[0],point4[1] )
    d1.append(d1temp)
    return d1
minDistance = sumOfDistances(startingPoint[0], startingPoint[1],point1[0],point1[1], point2[0],point2[1],point3[0],point3[1], point4[0],point4[1] )
flag = True
def newPoints(minimum, d1, d2, d3, d4):
    if d1[2] == minimum:
        return [d1[0], d1[1]]
    elif d2[2] == minimum:
        return [d2[0], d2[1]]
    elif d3[2] == minimum:
        return [d3[0], d3[1]]
    elif d4[2] == minimum:
        return [d4[0], d4[1]]

i = 1
while flag:
    d1 = newDistance(startingPoint[0]+increment, startingPoint[1], point1, point2,point3,point4)
    d2 = newDistance(startingPoint[0]-increment, startingPoint[1], point1, point2,point3, point4)
    d3 = newDistance(startingPoint[0], startingPoint[1]+increment, point1, point2,point3, point4)
    d4 = newDistance(startingPoint[0], startingPoint[1]-increment, point1, point2,point3, point4)
    print (i,' ', round(startingPoint[0], 2), round(startingPoint[1], 2))
    minimum = min(d1[2], d2[2], d3[2], d4[2])
    if minimum < minDistance:
        startingPoint = newPoints(minimum, d1, d2, d3, d4)
        minDistance = minimum
        #print i,' ', round(startingPoint[0], 2), round(startingPoint[1], 2)
        i+=1
    else:
        flag = False



#  output here        
#  1   1 1
# 2   1.1 1
# 3   1.2 1
# 4   1.3 1
# 5   1.4 1
# 6   1.5 1
# 7   1.6 1
# 8   1.6 1.1
# 9   1.7 1.1
# 10   1.7 1.2
# 11   1.7 1.3
# 12   1.8 1.3
# 13   1.8 1.4
# 14   1.9 1.4
# 15   2.0 1.4
# 16   2.0 1.5
# 17   2.1 1.5
# 18   2.1 1.6
# 19   2.2 1.6
# 20   2.2 1.7
# 21   2.3 1.7
# 22   2.3 1.8
# 23   2.3 1.9
# 24   2.4 1.9
# 25   2.5 1.9
# 26   2.5 2.0
# 27   2.6 2.0
# 28   2.6 2.1
# 29   2.7 2.1
# 30   2.7 2.2
# 31   2.8 2.2
# 32   2.8 2.3
# 33   2.9 2.3
# 34   2.9 2.4
# 35   3.0 2.4
# 36   3.0 2.5
# 37   3.1 2.5
# 38   3.1 2.6
# 39   3.2 2.6
# 40   3.2 2.7
# 41   3.2 2.8
# 42   3.3 2.8
# 43   3.4 2.8
# 44   3.4 2.9
# 45   3.5 2.9
# 46   3.5 3.0
