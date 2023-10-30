#ifndef BST_H
#define BST_H
#pragma once

template<class Type>
class bst {
	public /* Methods */:
		bst() {} 
		~bst() {
			clear();
		}
		void insert(Type new_data) {
			if(!m_root) {
				m_root = new Node(new_data);
				m_size++;
				return;
			}
			Node* temp = m_root;
			while(true) {
				if(new_data == temp->data) return;
				if(new_data < temp->data) {
					if(!temp->left) {
						temp->left = new Node(new_data);
						m_size++;
					}
					temp = temp->left;
				} else {
					if(!temp->right) {
						temp->right = new Node(new_data);
						m_size++;
						return;
					}
					temp = temp->right;
				}
			}
		}
		[[nodiscard]] size_t size() const { return m_size; }
		void clear() { 
			clear_recursive(m_root); 
			m_size = 0;
		}
		[[nodiscard]] Type min() {
			if(!m_root) return 0;    // Ewwwww... Magic Number!
			Node* leaf = m_root;
			while(leaf->left) leaf = leaf->left;
			return leaf->data;
		}
		[[nodiscard]] Type max() {
			if(!m_root) return 0;    // Ewwwww... Magic Number!
			Node* leaf = m_root;
			while(leaf->right) leaf = leaf->right;
			return leaf->data;
		}
		[[nodiscard]] bool find_r(Type search_data) { return find_recursive(m_root, search_data); }
		[[nodiscard]] bool find(Type search_data) {
			bool result = false;
			for(Node* ptr = m_root; ptr;) {
				if(!ptr) break;
				if(search_data == ptr->data) {
					result = true;
					break;
				}
				if(search_data < ptr->data) ptr = ptr->left;
				else ptr = ptr->right;
			}
			return result;
		}
		void print() const { print_recursive(m_root); }
	
	private /* Methods */:
		struct Node {
			Node(Type new_data) : data(new_data) {}
			Type data = {};
			Node* left = nullptr;
			Node* right = nullptr;
		};
		void clear_recursive(Node* temp) {
			if(!temp) return;
			if(temp->left) clear_recursive(temp->left);
			if(temp->right) clear_recursive(temp->right);
			delete temp;
		}
		bool find_recursive(Node* temp, Type search_data) {
			#pragma GCC diagnostic push
			#pragma GCC diagnostic ignored "-Wreturn-type"
			if(!temp) return false;
			if(search_data == temp->data) return true;
			if(search_data < temp->data) find_recursive(temp->left, search_data);
			else find_recursive(temp->right, search_data);
		}
		void print_recursive(Node* temp) const noexcept{
			if(!temp) return;
			print_recursive(temp->left);
			std::cout << temp->data << '\t';
			print_recursive(temp->right);
		}
	private /* Members */:
		Node* m_root  = nullptr;
		size_t m_size = 0;
};

#endif
