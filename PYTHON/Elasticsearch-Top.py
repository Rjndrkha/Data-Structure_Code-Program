#!/usr/bin/python
# Calculating differences between indices size of ELasticsearch every few seconds

import requests
import time
import sys

try:
    r = requests.get('http://localhost:9200/_cat/indices?v')
except :
    print ("Error conecting to elasticsearch. Exiting...")
    sys.exit(1)

data = r.text.split('\n')

#remove header
data.pop(0)

stored_values = []
for i in range(0,len(data)-1):
    index_name = data[i].split()[2]
    docs_number = data[i].split()[5]
    size = data[i].split()[7]
    delta = 0
    last_number = data[i].split()[5]

    values = {'index':index_name,'docs':docs_number,'size':size,'delta':delta,'last':last_number}

    stored_values.append(values)

try:
    while True:
	    try:
		r = requests.get('http://localhost:9200/_cat/indices?v')
	    except :
		print ("Error conecting to elasticsearch. Exiting...")
		sys.exit(1)
	
	    data = r.text.split('\n')
	    data.pop(0)
	
	    #clean the screen
	    print(chr(27) + "[2J")
	    print '{0:40} {1:6} {2:11} {3:10}'.format('Index name', 'Delta', 'Docs number', 'Size')
	    for i in range(0,len(data)-1):
		index_name = data[i].split()[2]
		docs_number = int(float(data[i].split()[5]))
	
		size = data[i].split()[7]
		for item in stored_values:
		    if item["index"] == index_name:
			delta = docs_number - int(float(item["last"]))
			item["delta"] = delta
			item["last"] = docs_number
			if delta != 0:
			    print '{0:40} {1:6} {2:11} {3:10}'.format(index_name, delta, docs_number, size)
			break
	    time.sleep(2)

except KeyboardInterrupt:
    print "Bye-bye"

# vim: tabstop=8 expandtab shiftwidth=4 softtabstop=4