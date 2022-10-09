class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        import math
        l = nums1 + nums2
        l = sorted(l)
        if len(l)%2==1:
            return l[math.floor(len(l)/2)]
        else:
            n1 = l[math.floor(len(l)/2)]
            n2 = l[math.floor(len(l)/2)-1]
            return (n1+n2)/2