import pytube

print("Enter your Youtube Link :")
link = input()

print("Enter your required quality : ")
print("1 - 144p\n2 - 360p\n3 - 720p")

try:
    a = int(input())
    if a==1:
        vid = pytube.YouTube(link)
        vd = vid.streams.get_lowest_resolution()
        vd.download()
    elif a==2:
        vid = pytube.YouTube(link)
        vd = vid.streams.get_by_resolution('360p')
        vd.download()
    elif a==3:
        vid = pytube.YouTube(link)
        vd = vid.streams.get_highest_resolution('360p')
        vd.download()
    else:
        print("Incorrect Response")
