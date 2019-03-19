#include <iostream>

using namespace std;

struct ListNode {
	int a;
	ListNode *next;
	ListNode(int a): a(a), next(NULL) {}
};

ListNode* reverseList(ListNode* src)
{
	if (src == NULL || src->next == NULL) return src;

	ListNode *head = src;
	ListNode *cur=src;
	while (cur->next) {
		ListNode* tmp = cur->next->next;
		cur->next->next = head;
		head = cur->next;
		cur->next = tmp;
	}

	return head;
}

ListNode *swapPairs(ListNode *head)
{
	if (head == NULL) return NULL;
	ListNode *odd = head, *even;
	ListNode *swapedlast = NULL;
	while (odd != NULL && odd->next != NULL) {
 		even = odd->next;
		if (swapedlast == NULL) {
			head = even;
		} else {
			swapedlast->next = even;
		}
		odd->next = even->next;
		even->next = odd;
		swapedlast = odd;
		odd = odd->next;
	}
	return head;
}


int main() 
{
	ListNode* head = NULL;
	int i = 0;
	ListNode* cur = NULL;
	while (i < 10) {
		ListNode* tmp = new ListNode(i);
		if (head == NULL) {
			head = tmp;
			cur = head;
		} else {
			cur->next = tmp;
			cur = cur->next;
		}
		i++;
	}

	cur = head;
	while (cur) {
		cout << cur->a << endl;
		cur = cur->next;
	}

	ListNode* rev_head = swapPairs(head);
	cur = rev_head;
	while (cur) {
		cout << cur->a << endl;
		cur = cur->next;
	}

	return 0;
}
