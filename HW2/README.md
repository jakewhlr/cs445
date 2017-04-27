# Homework 2

## tcpConnect.py
tcpConnect.py uses scapy to perform a TCP connect scan on 10 well known ports( `ports = [20, 21, 22, 23, 25, 80, 43, 53, 69, 443]`) to determine whether they are
open or closed at a random interval using a random source port.

#### Running
The script can be run in the following format: `python tcpConnect.py <src_ip> <dst_ip>`, for example, `python tcpConnect.py 192.168.100.220 192.168.100.196`.
#### Output
Below is a sample output from tcpConnect.py scanning 192.168.100.196 from 192.168.100.220.

```
Scanning 192.168.100.196:20 from 192.168.100.220:28326
 Port 20 closed.
Scanning 192.168.100.196:21 from 192.168.100.220:23740
 Port 21 closed.
Scanning 192.168.100.196:22 from 192.168.100.220:41453
 Port 22 closed.
Scanning 192.168.100.196:23 from 192.168.100.220:374
 Port 23 closed.
Scanning 192.168.100.196:25 from 192.168.100.220:23817
 Port 25 closed.
Scanning 192.168.100.196:80 from 192.168.100.220:32324
 Port 80 open.
Scanning 192.168.100.196:43 from 192.168.100.220:12624
 Port 43 closed.
Scanning 192.168.100.196:53 from 192.168.100.220:45976
 Port 53 closed.
Scanning 192.168.100.196:69 from 192.168.100.220:64348
 Port 69 closed.
Scanning 192.168.100.196:443 from 192.168.100.220:64173
 Port 443 closed.
```

## xmasScan.py
xmasScan.py uses scapy to perform a XMAS scan on 10 well known ports( `ports = [20, 21, 22, 23, 25, 80, 43, 53, 69, 443]`) to determine whether they are
open/filtered or closed at a random interval using a random source port. XMAS Scan can not differentiate between an open port or a filtered port.

#### Running
The script can be run in the following format: `python xmasScan.py <src_ip> <dst_ip>`, for example, `python xmasScan.py 192.168.100.220 192.168.100.196`.
#### Output
Below is a sample output from xmasScan.py scanning 192.168.100.196 from 192.168.100.220.

```
Scanning 192.168.100.196:20 from 192.168.100.220:51110
 Port 20 closed.
Scanning 192.168.100.196:21 from 192.168.100.220:59425
 Port 21 closed.
Scanning 192.168.100.196:22 from 192.168.100.220:35340
 Port 22 closed.
Scanning 192.168.100.196:23 from 192.168.100.220:6254
 Port 23 closed.
Scanning 192.168.100.196:25 from 192.168.100.220:53340
 Port 25 closed.
Scanning 192.168.100.196:80 from 192.168.100.220:37597
 Port 80 open/filtered.
Scanning 192.168.100.196:43 from 192.168.100.220:24571
 Port 43 closed.
Scanning 192.168.100.196:53 from 192.168.100.220:61359
 Port 53 closed.
Scanning 192.168.100.196:69 from 192.168.100.220:12156
 Port 69 closed.
Scanning 192.168.100.196:443 from 192.168.100.220:19085
 Port 443 closed.
```
