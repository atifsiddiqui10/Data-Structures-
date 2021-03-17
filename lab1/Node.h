/**
  @Douly Linked List
  @File - Node.h
  @Author M. Atif Siddiqui

*/
#ifndef NODE_H
#define NODE_H

/**
	Node class for Doubly Linked List
*/

class Node
{
private:
	int item;
	Node* next;
	Node* prev;
public:
		/**
		 	Node constructor
			@param int Value
		*/
		Node(int anItem);

		/**
		 	Function to get the value of the node
			@param none
			@return interger value
		*/
		int getItem() const;

		/**
		 	Function to set the value of the node
			@param interger value
			@return none
		*/
		void setItem(int newItem);

		/**
		 	Function to get the value of the next node
			@param none
			@return Node pointer
		*/
		Node* getNext() const;

		/**
		 	Function to set the value of the next node
			@param Node pointer
			@return none
		*/
		void setNext(Node* nodePtr);

		/**
		 	Function to get the value of the prev node
			@param none
			@return Node pointer
		*/
		Node* getPrev() const;

		/**
		 	Function to set the value of the prev node
			@param Node pointer
			@return none
		*/
		void setPrev(Node* nodePtr);
};

#endif
