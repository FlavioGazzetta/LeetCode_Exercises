class Solution {
public:
    std::vector<int> list_to_vec(ListNode* l1) {
        std::vector<int> out;
        while (l1 != nullptr) {
            out.push_back(l1->val);
            l1 = l1->next;
        }
        return out;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        std::vector<int> val1 = list_to_vec(l1);
        std::vector<int> val2 = list_to_vec(l2);
        std::vector<int> sum;
        int carry = 0, sumval;

        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;

        int maxLen = max(val1.size(), val2.size());
        for (int j = 0; j < maxLen; j++) {
            int val1Digit = j < val1.size() ? val1[j] : 0;
            int val2Digit = j < val2.size() ? val2[j] : 0;

            sumval = val1Digit + val2Digit + carry;
            sum.push_back(sumval % 10);
            carry = sumval / 10;
        }

        if (carry > 0) {
            sum.push_back(carry);
        }

        for (int i = 0; i < sum.size(); i++) {
            current->next = new ListNode(sum[i]);
            current = current->next;
        }

        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};
