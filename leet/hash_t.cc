#include <iostream>
#include <map>
using namespace std;

class Node {
public:
	int val;
	Node *next;
	Node *random;

	Node() {}

	Node(int _val, 
			Node *_next, 
			Node *_random):
		val(_val),
		next(_next),
		random(_random) {}
};

Node *copyRandomList(Node *head)
{
	Node *new_head = NULL, *new_cur = NULL;
	Node *cur = head;
	map<Node*, Node*> old_new_map;
	while (cur) {
		Node* new_node = new Node(cur->val, NULL, NULL);
		old_new_map[cur] = new_node;
		if (new_head == NULL) {
			new_head = new_cur = new_node;
			new_head->next = new_cur->next = NULL;
		} else {
			new_cur->next = new_node;
			new_cur = new_cur->next;
		}
		cur = cur->next;
	}
	
	cur = head;
	new_cur = new_head;
	while (cur) {
		if (cur->random == NULL) {
			new_cur->random = NULL;
		} else {
			new_cur->random = old_new_map[cur->random];
		}
		cur = cur->next;
		new_cur = new_cur->next;
	}
	
	return new_head;
}

int main(int argc, char** argv)
{

}
