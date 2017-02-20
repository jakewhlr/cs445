## HW1
This program simulates the behavior of probabilistic packet marking using C++, and compares the performance of node sampling and edge sampling algorithms.

#### Input file
The program reads network topology from "topology.txt", with the form `node nextHop`, with node being a router or host, and nextHop being that node's next hop to get to its destination. To simulate a network topology such as this:  

![alt text](http://i.imgur.com/Uddot0K.png?3)    

The input file would be:  
```
a1 r5
a2 r6
a3 r7
r5 r3
r6 r3
r7 r4
r3 r2
r4 r2
r2 r1
r1 v
v none
```

### Compiling
`make` can be run in this directory to compile two executables `nodesample`, and `edgesample`. Each of these executables output the route from the victim to the attacker using node sampling and edge sampling, respectively.
