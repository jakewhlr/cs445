#include<iostream>
#include<fstream>
#include<string>
#include<time.h>
#include<stdlib.h>
#include<stdio.h>
#include<sstream>
#include<algorithm>

#define p 0.5
#define MAX_NODES 11
#define MAX_PACKETS 100

using namespace std;

class packet{
public:
  int data;
  string start;
  string end;
  int distance;
  void printPacket();
};

class node{
public:
  string name;
  string nextHopName;
  node* nextHop;
  packet currentPacket;
  node();
  void printNode();
  void sendPacket();
  void markPacket();
};

class table{
public:
  string start;
  string end;
  int distance;
};

class treeNode{
public:
  string nodeData;
  table edge;
};

void reconstruct(packet*, node*);
void populateNodes(node*);
bool tableCompare(table const &a, table const &b);

int main(){
  srand (time(NULL));
  node topology[MAX_NODES];
  packet recievedPackets[MAX_PACKETS];
  populateNodes(topology);
  node* currentRouter = &topology[0];
  for(int i = 0; i < MAX_PACKETS; i++){
    currentRouter = &topology[1];
    while(currentRouter->nextHop != NULL){
      currentRouter->markPacket();
      currentRouter->sendPacket();
      currentRouter = currentRouter->nextHop;
    }
    recievedPackets[i] = currentRouter->currentPacket;
  }
  reconstruct(recievedPackets, topology);
}

void packet::printPacket(){
  cout << "Data: " << data << " Start: " << start << " End: " << end << " Distance: " << distance << endl;
}

node::node(){
  name = "";
  nextHopName = "none";
  nextHop = NULL;
}

void node::printNode(){
  cout << "Name: " << name << " Next hop: " << nextHopName << " Packet: ";
  currentPacket.printPacket();
}

void node::sendPacket(){
  if(nextHop != NULL){
    nextHop->currentPacket = currentPacket;
  }
}

void node::markPacket(){
  float x = rand()%10 / 10.0;
  if (x < p){
    currentPacket.start = this->name;
    currentPacket.distance = 0;
  }
  else{
    if(currentPacket.distance == 0){
      currentPacket.end = this->name;
    }
    currentPacket.distance++;
  }
}

void reconstruct(packet* recievedPackets, node* topology){
  treeNode outTree[MAX_NODES];
  table edges[MAX_PACKETS];
  for(int i = 0; i < MAX_NODES; i++){
    outTree[i].nodeData = topology[i].name;
  }
  int j = 0;
  for(int i = 0; i < MAX_PACKETS; i++){
    if(recievedPackets[i].distance == 0){
      edges[i].start = recievedPackets[i].start;
      edges[i].end = "v";
      edges[i].distance = 0;
    }
    else{
      edges[i].start = recievedPackets[i].start;
      edges[i].end = recievedPackets[i].end;
      edges[i].distance = recievedPackets[i].distance;
    }
  }
  sort(edges, edges + MAX_PACKETS, tableCompare);
  cout << "Route to attacker: " << endl;
  int count = 0;
  cout << edges[count].start << endl;
  string lastHop = edges[count].start;
  count++;
  while(edges[count].distance != 0){
    if(edges[count].start != lastHop){
      cout << edges[count].start << endl;
      lastHop = edges[count].start;
    }
    count++;
  }
  cout << edges[count].start << endl;
}

void populateNodes(node* topology){
  string data;
  int i = 0;
  ifstream inputFile;
  inputFile.open("topology.txt");
  while(!inputFile.eof()){
    getline(inputFile, data);
    istringstream line(data);
    line >> topology[i].name >> topology[i].nextHopName;
    i++;
  }
  inputFile.close();
  i = 0;
  int j = 0;
  while(i < MAX_NODES){
    topology[i].nextHop = NULL;
    for(j = 0; j < MAX_NODES; j++){
      if(topology[i].nextHopName == topology[j].name){
        topology[i].nextHop = &topology[j];
        break;
      }
    }
    i++;
  }
}

bool tableCompare(table const &a, table const &b){
  return a.distance > b.distance;
}
