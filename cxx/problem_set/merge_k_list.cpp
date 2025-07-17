#include <iostream>
#include <vector>
static constexpr int max_loop { 10 };
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
	    using std::cout;
	    using std::endl;
        int exit_detector = std::size(lists);
	cout << "size:" << exit_detector << endl;
	int loop_counter { 0 };
        while (exit_detector > 0)
        {
            for(auto i : lists)
            {
                cout << "typeid:" << typeid(i).name() << endl;
                if(i->next == nullptr){
                    exit_detector--;
		}
		cout << "exit detecotr:" << exit_detector << endl;
            }
	    if(++loop_counter > max_loop) {
		    cout << "exit with max loop counter\n";
		    break;
	    }
        }
	cout << "retrun\n";
        return nullptr;
    }
};

int main ()
{
	using std::cout;
	cout << "hello merge k sort\n";
	ListNode l13(5);
	ListNode l12(4, &l13);
	ListNode l11(1, &l12);

	ListNode l23(4);
	ListNode l22(3, &l23);
	ListNode l21(1, &l22);

	ListNode l32(2);
	ListNode l31(6, &l31);

	std::vector<ListNode*> Lists{&l11, &l21, &l31};

	Solution s;
	s.mergeKLists(Lists);

	return 0;
}

