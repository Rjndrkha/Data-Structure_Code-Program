from bs4 import BeautifulSoup as soup
import webbrowser
import requests


def play(query):
	url="https://www.youtube.com/results?search_query=%s"%(query)
	#webbrowser.open(url)
	req = requests.get(url)
	new_soup = soup(req.text,'html.parser')
	divs=new_soup.findAll("div", { "class" : "yt-lockup-content"})
	first_vid=[]
	for i in divs:
	        href= i.find('a', href=True)
	        link="https://www.youtube.com"+href['href']
	        webbrowser.open(link)
	        break
	        #first_vid.append(link)
	        #print(href.text, link , '\n')
	#url=r''
	#url = first_vid[0]
	#webbrowser.open(url)

// pass any music name
play("Unstoppable")
