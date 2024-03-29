
class Solution {
public:
    unordered_map<Node*, Node*> cloneMap;

Node* cloneGraph(Node* node) {
    if (node == nullptr) {
        return nullptr;
    }
    if (cloneMap.find(node) != cloneMap.end()) {
        return cloneMap[node];
    }

    Node* newNode = new Node(node->val);
    cloneMap[node] = newNode;

    for (Node* neighbor : node->neighbors) {
        newNode->neighbors.push_back(cloneGraph(neighbor));
    }

    return newNode;
}
};