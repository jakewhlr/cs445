#!/usr/bin/env python
import sys
import random
from scapy.all import *
conf.verb=0

source=sys.argv[1]
target=sys.argv[2]

ports =[20, 21, 22, 23, 25, 80, 43, 53, 69, 443]
for port in ports:
  sourceport = random.randrange(1,65535)
 outString = "Scanning " + target + ":" + str(port) + " from " + source + ":" + str(sourceport)
	 print outString
	 p1=IP(dst=target,src=source)/TCP(dport=port,sport=sourceport,flags='S')
	 r1=sr1(p1)
	 if r1[TCP].flags == 18:
	   print " Port " + str(port) +  " open."
	 if r1[TCP].flags == 20:
	   print " Port " + str(port) + " closed."
sys.exit(0)

