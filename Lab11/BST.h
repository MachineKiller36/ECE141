#ifndef BST_H
#define BST_H
#pragma once


struct Node {
	Node(int data) {
		this->data = data;
		this->LeftChild = nullptr;
		this->RightChild = nullptr;
	}
	int data;
	Node* LeftChild;
	Node* RightChild;
};

class BST {
	private /* Members */:
		Node* root  = nullptr;
	private /* Methods */:
		void clear(Node* root) {
			if(!root) return;
			if(root->LeftChild) clear(root->LeftChild);
			if(root->RightChild) clear(root->RightChild);
			delete root;
		}

	public /* Methods */:
		BST() {} 
		~BST() {
			clear(root);
		}
		
		Node* getRoot() { return this->root; };
		
		void printTree(Node* root) const { 
			if(!root) return;
			printTree(root->LeftChild);
			printTree(root->RightChild);
			std::cout << root->data << '\t';
		}
		
		Node* InsertNode(int data) {
			if(!root) {
				root = new Node(data);
				return root;
			}
			Node* temp = root;
			while(true) {
				if(data == temp->data) return temp;
				if(data < temp->data) {
					if(!temp->LeftChild) {
						temp->LeftChild = new Node(data);
						return temp->LeftChild;				// TODO May need to change
					}
					temp = temp->LeftChild;
				} else {
					if(!temp->RightChild) {
						temp->RightChild = new Node(data);
						return temp->RightChild;
					}
					temp = temp->RightChild;
				}
			}
		}

		bool FindNode(int data) {
			bool result = false;
			for(Node* ptr = root; ptr;) {
				if(!ptr) break;
				if(data == ptr->data) {
					result = true;
					break;
				}
				if(data < ptr->data) ptr = ptr->LeftChild;
				else ptr = ptr->RightChild;
			}
			return result;
		}

		int Largest() {
			if(!root) return 0;    // Ewwwww... Magic Number!
			Node* leaf = root;
			while(leaf->RightChild) leaf = leaf->RightChild;
			return leaf->data;
		}
};

#endif
