/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        std::vector<std::vector<int>> vlists;
        std::vector<int> temp, out;
        int min, l, totmin, maxvsize = 0, nmin, size = 0;
        bool skipped = true;

        ListNode* dummy = new ListNode(0);

        ListNode* current = dummy;


        for(int i = 0; i < lists.size(); i++){

            temp = list_to_vec(lists[i]); //I could sort them here in order to implement merge sort
            /*
            for(int m = 0; m < temp.size(); m++){

                min = temp[m];

                for(l = m; l < temp.size() - 1; l++){
                    
                    if(temp[l] <= min){

                        min = temp[l];

                    }

                }

                temp[m] = min;    

            }
            */

           //the above for loop would be implemented in the case of merging k unsorted lists

            vlists.push_back(temp);

            size += temp.size();

            if(temp.size() >= maxvsize){

                maxvsize = temp.size();

            }

        }

        for(int p = 0; p < size; p++){

            skipped = true;

            for(int n = 0; n < vlists.size(); n++){

                if(0 < vlists[n].size()){

                    if(vlists[n][0] <= min || n == 0 || skipped == true){

                        skipped = false;

                        min = vlists[n][0];
                        nmin = n;

                    }

                }

            }
            
            vlists[nmin].erase(vlists[nmin].begin());
            out.push_back(min);

        }
        

        for(int j = 0; j < out.size(); j++){

        current->next = new ListNode(out[j]);

        current = current->next;

        }

        ListNode* result = dummy->next;

        delete dummy;

        return result;

    }

};