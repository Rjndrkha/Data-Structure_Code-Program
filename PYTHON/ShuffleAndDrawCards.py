# Python program to shuffle and draw a deck of card
import itertools, random

deck = list(itertools.product(['2','3','4','5','6','7','8','9','10','Jack','Queen','King','Ace'],['Spade','Heart','Diamond','Club']))
random.shuffle(deck)

# draw five cards
print("You got:")
for i in range(5):
   print(deck[i][0], "of", deck[i][1])
