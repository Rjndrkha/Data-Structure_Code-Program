import random

lower = "abcdefghijklmnopqrstuvwxyz"
upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
numbers = "0123456789"
sp_symbols = "!#@{}*[]"

mix = lower + upper + numbers + sp_symbols
length = random.randrange(8,16)

password = "".join(random.sample(mix,length))
print("strong password - ", password)