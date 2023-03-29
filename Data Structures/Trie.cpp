const int ALPHABET_SIZE = 26;
const int OFFSET = 'a';
struct TrieNode{
    struct TrieNode* children[ALPHABET_SIZE];
    int endsHere;
};
TrieNode* initNode(){
    TrieNode* node = new TrieNode;
    node->endsHere = 0;
    for(int i = 0; i < ALPHABET_SIZE; i++)
        node->children[i] = NULL;
    return node;
}
void insert(TrieNode* root, string &val){
    for(auto ch: val){
        if(root->children[ch-OFFSET] == NULL)
            root->children[ch-OFFSET] = initNode();
        root = root->children[ch-OFFSET];
    }
    root->endsHere++;
}
