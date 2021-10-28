#pragma once

#include <vector>
#include <stack>

template<typename T>
class Node {
public:
	int depth = -1;
	bool expanded = false;

	Node(T state): state(state) {
	}

	Node<T>* addChild(T state) {
		Node<T>* node = new Node<T>(state);
		node->parent = this;
		node->depth = depth + 1;
		children.push_back(node);
		return node;
	}

	std::vector<Node<T>*>& getChildren() {
		return children;
	}

	T getState() {
		return state;
	}

	Node<T>* getParent() {
		return parent;
	}

	~Node() {
		std::cout << "Deleting " << state << '\n';
	}

private:
	std::vector<Node<T>*> children;
	Node<T>* parent;
	T state;
};

template<typename T>
class Tree {
public:
	Tree(T root_state) {
		root = new Node<T>(root_state);
		root->depth = 0;
	}

	Node<T>* getRoot() {
		return root;
	}

	void breadth_first_search(T goal_state) {
		std::queue<Node<T>*> fringe;
		fringe.push(this->getRoot());
		Node<T>* final_node = nullptr;
		while(!fringe.empty()) {
			auto top = fringe.front();
			fringe.pop();
			if(top->getState() == goal_state) {
				final_node = top;
				break;
			}
			for(auto el : top->getChildren()) {
				fringe.push(el);
			}
		}
		while(final_node != nullptr) {
			std::cout << final_node->getState() << '\n';
			final_node = final_node->getParent();
		}
	}

	void depth_first_search(T goal_state) {
		std::stack<Node<T>*> fringe;
		fringe.push(this->getRoot());
		Node<T>* final_node = nullptr;
		while(!fringe.empty()) {
			auto top = fringe.top();
			if(top->expanded) {
				delete top;
				fringe.pop();
				continue;
			}
			std::cout << top->getState() << '\n';
			if(top->getState() == goal_state) {
				final_node = top;
				break;
			}
			for(auto el : top->getChildren()) {
				fringe.push(el);
			}
			top->expanded = true;
		}
		while(final_node != nullptr) {
			std::cout << final_node->getState() << '\n';
			final_node = final_node->getParent();
		}
	}

	void depth_limited_search(T goal_state, int limit) {
		std::stack<Node<T>*> fringe;
		fringe.push(this->getRoot());
		Node<T>* final_node = nullptr;
		while(!fringe.empty()) {
			auto top = fringe.top();
			if(top->expanded) {
				delete top;
				fringe.pop();
				continue;
			}
			std::cout << top->getState() << '\n';
			if(top->getState() == goal_state) {
				final_node = top;
				break;
			}
			if(top->depth != limit) {
				for(auto el : top->getChildren()) {
					fringe.push(el);
				}
			}
			top->expanded = true;
		}
		while(final_node != nullptr) {
			std::cout << final_node->getState() << '\n';
			final_node = final_node->getParent();
		}
	}

private:
	Node<T>* root;
	int depth = 1;
};