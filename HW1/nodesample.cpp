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
  string node;
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
  string name;
  int count;
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
  cout << "Data: " << data << " Node: " << node << endl;
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
    currentPacket.node = this->name;
  }
}

void reconstruct(packet* recievedPackets, node* topology){
  table nodeTable[MAX_NODES];
  string* output = new string[MAX_NODES];
  for(int i = 0; i < MAX_NODES; i++){
    nodeTable[i].name = topology[i].name;
    nodeTable[i].count = 0;
  }
  for(int i = 0; i < MAX_PACKETS; i++){
    for(int j = 0; j < MAX_NODES; j++){
      if(recievedPackets[i].node == nodeTable[j].name){
        nodeTable[j].count++;
        break;
      }
    }
  }
  sort(nodeTable, nodeTable + MAX_NODES, tableCompare);
  int count = 0;
  cout << "Route to attacker: " << endl;
  while(nodeTable[count].count != 0){
    cout << nodeTable[count].name << endl;
    count++;
  }
}

void populateNodes(node* topology){
  string data;
  int i = 0;
  ifstream inputFile;
  inputFile.open("nodes.txt");
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
  return a.count > b.count;
}
