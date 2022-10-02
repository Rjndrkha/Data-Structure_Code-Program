def isNumber(self, s):
    # create an enumerator to track when the str  is split the string
    for c,ss in enumerate(s):
        if ss in "eE":
            break 
        else:
            return self.isDecimal(s) or self.isInteger(s)
    return  self.isDecimal(s[:c]) & self.isInteger(s[c+1:])

# check if its ecimal
def isDecimal(self,st):
     # test edge case
    if st=="":
        return False
    for c,ss in enumerate(st):
        if ss==".": 
            break 
    else: 
        return self.isInteger(st) 

    left = st[:c]
    right = st[c+1:]
    # first operand : rule 1 and 2.3 
    # second operand: rule 2.1 and 2.2
    return (((left in "+-") and self.isUinteger(right)) or
            ((self.isInteger(left) and (self.isUinteger(right) or right==""))))

# check if its an integer without sign
def isUinteger(self, st):
     # test edge case
    if st=="": 
        return False
    return set(st).issubset("0123456789")

def isInteger(self,st):
    # test edge case
    if st=="": 
        return False
    if st[0] in "+-":
        return self.isUinteger(st[1:])
    return self.isUinteger(st)
