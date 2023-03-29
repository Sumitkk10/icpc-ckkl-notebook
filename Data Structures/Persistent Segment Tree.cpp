/*Set A[i] = x in copy k 
sum of values in range [a,b] in array k
Create a copy of array k and add it to the end of the list.*/
struct Node{
    Node *l, *r;
    int sum;
    Node(int val) : l(nullptr), r(nullptr), sum(val){}
    Node(Node *l, Node *r): l(l), r(r), sum(0){
        if(l) sum += l->sum;
        if(r) sum += r->sum;
    }
    Node(Node* copy): l(copy->l), r(copy->r), sum(copy->sum){}
};
Node* build(int A[], int l, int r){
    if(l == r)
        return new Node(A[l]);
    int mid = (l + r) / 2;
    Node* lchild = build(A, l, mid);
    Node* rchild = build(A, mid + 1, r);
    return new Node(lchild, rchild);
}
int query(Node* node, int l, int r, int ql, int qr){
    if(ql <= l && r <= qr)
        return node->sum;
    if(r < ql || qr < l)
        return 0;
    int mid = (l + r) / 2;
    int lans = query(node->l, l, mid, ql, qr);
    int rans = query(node->r, mid+1, r, ql, qr);
    return lans + rans;
}

Node* update(Node* node, int l, int r, int qpos, int x){
    if(l == r)
        return new Node(x);
    int mid = (l + r) / 2;
    if(qpos <= mid){
        Node* c = update(node->l, l, mid, qpos, x);
        return new Node(c,node->r);
    }
    else{
        Node* c = update(node->r, mid+1, r, qpos, x);
        return new Node(node->l,c);
    }
}
