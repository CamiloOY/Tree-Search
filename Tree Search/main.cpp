#include <iostream>
#include <queue>
#include "Tree.h"

/*template<typename T>
void breadth_first_search(Tree<T>& tree, T goal_state) {
	std::queue<Node<T>*> fringe;
	fringe.push(tree.getRoot());
	Node<T>* final_node;
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
}*/

int main() {
	Tree<std::string> tree("Arad");
	auto root = tree.getRoot();
	auto sib = root->addChild("Sibiu");
	auto timi = root->addChild("Timisoara");
	auto zer = root->addChild("Zerind");
	sib->addChild("Arad");
	sib->addChild("Fagaras");
	sib->addChild("Oradea");
	sib->addChild("Rimnicu Vilcea");
	timi->addChild("Arad");
	timi->addChild("Lugoj");
	zer->addChild("Arad");
	zer->addChild("Oradea");
	tree.depth_first_search("");
	return 0;
}