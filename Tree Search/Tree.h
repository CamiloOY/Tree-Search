#pragma once

#include <vector>

template<typename T>
class Node {
public:
	int depth = -1;
	T state;

	Node<T>* addChild(T state) {
		Node<T>* node = new Node<T>();
		node->parent = this;
		node->state = state;
		node->depth = depth + 1;
		children.push_back(node);
		return node;
	}

	std::vector<Node<T>*>& getChildren() {
		return children;
	}

	int getDepth() {
		return depth;
	}

	T getState() {
		return state;
	}

	Node<T>* getParent() {
		return parent;
	}

private:
	std::vector<Node<T>*> children;
	Node<T>* parent;
};

template<typename T>
class Tree {
public:
	Tree(T root_state) {
		root = new Node<T>();
		root->depth = 0;
		root->state = root_state;
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

private:
	Node<T>* root;
	int depth = 1;
};