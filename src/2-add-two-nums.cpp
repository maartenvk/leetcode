#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *result, *begin;
        result = begin = new ListNode();

        int carry {0};
        while (l1 || l2 || carry) {
            int a {0}, b {0};

            if (l1) {
                a = l1->val;
                l1 = l1->next;
            }

            if (l2) {
                b = l2->val;
                l2 = l2->next;
            }

            a += b + carry;
            carry = a > 9;

            result = result->next = new ListNode(a % 10);
        }

        auto head = begin->next;
        delete begin;
        return head;
    }
};

void print_list(ListNode* list) {
    if (list == nullptr) {
        std::cout << "< Empty list >\n";
        return;
    }

    do {
        std::cout << list->val;
        list = list->next;
    } while (list != nullptr);
    std::cout << std::endl;
}

ListNode* populate(std::initializer_list<int> data) {
    ListNode *list {nullptr}, *returnable;
    for (int n : data) {
        if (list == nullptr) {
            list = new ListNode(n);
            returnable = list;
        } else {
            list->next = new ListNode(n);
            list = list->next;
        }
    }

    return returnable;
}

int main() {
    auto l1 = populate({9, 9, 9, 9});
    auto l2 = populate({9});

    Solution s;
    auto result = s.addTwoNumbers(l1, l2);
    print_list(result);

    return 0;
}
