#include <iostream>
#include <queue>
#include "Tree.h"

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
	tree.depth_limited_search("", 1);
	return 0;
}