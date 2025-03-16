/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
      if (!head) return nullptr;
      unordered_map<int, Node*> idxToNodeMap;
      unordered_map<Node*, int> nodeToIdxMap;
      Node *copyTemp = nullptr, *copyPrev = nullptr, *originalTemp = head;
      Node* copyHead = nullptr;
      int index = 0;

      // First iterate and allocate all nodes based on next
      while (originalTemp) {
        Node* node = new Node(originalTemp->val);
        idxToNodeMap.try_emplace(index, node);
        nodeToIdxMap.try_emplace(originalTemp, index);
        if (index != 0) {
          copyPrev->next = node;
          copyPrev = copyPrev->next;
        } else {
          copyPrev = node;
          copyHead = node;
        }
        ++index;
        originalTemp = originalTemp->next;
      }

      // Now iterate and set random pointers
      originalTemp = head;
      copyTemp = copyHead;
      while (originalTemp) {
        if (originalTemp->random) {
          auto idx = nodeToIdxMap[originalTemp->random];
          copyTemp->random = idxToNodeMap[idx];
        }
        originalTemp = originalTemp->next;
        copyTemp = copyTemp->next;
      }

      return copyHead;
    }
};