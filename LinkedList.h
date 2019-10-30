#pragma once
#include "LinkedListInterface.h"
#include <sstream>

using namespace std;

template<typename T>
class LinkedList : public LinkedListInterface<T> 
{
private :
    struct Node {
        Node(T val){
            value = val;
            next = NULL;
        }
        
        T value;
        Node *next;
    };
    
    Node *head;
    int size;

public : 
    LinkedListInterface() {
        head = NULL;
    };
	~LinkedListInterface() {};

	/*
	insertHead

	A node with the given value should be inserted at the beginning of the list.

	Do not allow duplicate values in the list.
	*/
	void insertHead(T value){
	    Node *newNode = new Node(value);
	    newNode->next = head;
	    head = newNode;
	    size += 1; 
	}

	/*
	insertTail

	A node with the given value should be inserted at the end of the list.

	Do not allow duplicate values in the list.
	*/
	void insertTail(T value){
	    //create the Node we want to insert
	    Node *newNode = new Node(value);
	    
	    //check if it's the first item to be added
	    if(head == NULL)
	        head = newNode;
	    
	    //iterate through to the end of the list
	    Node *pseudoIterator = head;
	    while(pseudoIterator->next != NULL){
	        pseudoIterator = pseudoIterator->next;
	    }
	    
	    //change the last item to point to our new item
	    pseudoIterator->next = newNode;
	}

	/*
	insertAfter

	A node with the given value should be inserted immediately after the
	node whose value is equal to insertionNode.

	A node should only be added if the node whose value is equal to
	insertionNode is in the list. Do not allow duplicate values in the list.
	*/
	void insertAfter(T value, T insertionNode){
	    Node *pseudoIterator = head;
	    while(pseudoIterator->next != NULL){
	        if(pseudoIterator->value == insertionNode){
	            Node *newNode = new Node(value);
	            newNode->next = pseudoIterator->next;
	            pseudoIterator->next = newNode;
	            break;
	        }
		    pseudoIterator = pseudoIterator->next;
	    }
	}

	/*
	remove

	The node with the given value should be removed from the list.

	The list may or may not include a node with the given value.
	*/
	void remove(T value){
	    Node *pseudoIterator = head;
	    Node *aboutToBeDeletedNode;
	    while(pseudoIterator->next != NULL){
	        if(pseudoIterator->value == value){ // found it!
	            aboutToBeDeletedNode = pseudoIterator; // let's mark it
	            pseudoIterator = head; //start the iteration over again
	            while(pseudoIterator->next != NULL){
	                if(pseudoIterator->next == aboutToBeDeletedNode){//found it, but we stopped one ahead of it
	                    //now we change what it points to to skip  
	                    //over the one we want to delete
	                    pseudoIterator->next = aboutToBeDeletedNode->next;
	                    delete aboutToBeDeletedNode; //it just got deleted
	                    break; //let's blow this popsicle stand
	                }
	                pseudoIterator = pseudoIterator->next;
	            }
	        }
	        pseudoIterator = pseudoIterator->next;
	    }
	}

	/*
	clear

	Remove all nodes from the list.
	*/
	void clear(){
		Node *pseudoIterator = head;
		while(pseudoIterator != NULL){
			Node *nextNode = pseudoIterator->next;
			delete pseudoIterator;
			pseudoIterator = nextNode;
		}
		head = NULL;
	}

	/*
	at

	Returns the value of the node at the given index. The list begins at
	index 0.

	If the given index is out of range of the list, throw an out of range exception.
	*/
	T at(int index){
	    Node *pseudoIterator = head;
	    int count = 0; //let's keep track of where we're at
	    while(pseudoIterator != NULL){
	    	if(count == index){ //we're arrived at our desired location
	    		return pseudoIterator->value;//thank you for flying with linkedAir
	    		break;
	    	} else {
	    		count += 1;
	    		pseudoIterator = pseudoIterator->next;
	    	}
	    	
	    }
	}

	/*
	size

	Returns the number of nodes in the list.
	*/
	int size(){
	    int count = 0;
	    for(Node *pseudoIterator = head; pseudoIterator != NULL; pseudoIterator = pseudoIterator->next){
	    	count += 1;
	    }
	    return count;
	}

	/*
	toString
	
	Returns a string representation of the list, with the value of each node listed in order (Starting from the head) and separated by a single space
	There should be no trailing space at the end of the string

	For example, a LinkedList containing the value 1, 2, 3, 4, and 5 should return
	"1 2 3 4 5"
	*/
	string toString(){
	    stringstream to_string;
	    Node *pseudoIterator = head;
	    while(pseudoIterator->next != NULL){
	        to_string << pseudoIterator->value;
	        if(pseudoIterator->next != NULL)
	            to_string << " ";
	    }
	    return to_string.str();
	}
    
};