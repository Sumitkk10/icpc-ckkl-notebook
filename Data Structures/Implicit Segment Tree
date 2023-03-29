struct Node{
    //range sum, range add
    int left_bound, right_bound;
    int sum = 0, lazy = 0;
    struct Node* left_child = nullptr;
    struct Node* right_child = nullptr;
    Node(int l, int r){
        left_bound = l;
        right_bound = r;
    }
    bool has_children(){
        return left_child != nullptr && right_child != nullptr;
    }
    bool is_leaf(){
        return right_bound - left_bound == 0;
    }
    void create_children(){
        if(has_children() || is_leaf())
            return;
        int mid = left_bound + (right_bound - left_bound) / 2;
        left_child = new Node(left_bound, mid);
        right_child = new Node(mid + 1, right_bound);
    }
    void propagate(){
        left_child->lazy += lazy;
        left_child->sum += lazy;
        right_child->lazy += lazy;
        right_child->sum += lazy;
        lazy = 0;
    }
    int query(int qleft_bound, int qright_bound){
        if(qright_bound < left_bound || right_bound < qleft_bound)
            return 0;
        if(qleft_bound <= left_bound && right_bound <= qright_bound)
            return sum;
        create_children();
        propagate();
        int left_ans = left_child->query(qleft_bound, qright_bound);
        int right_ans = right_child->query(qleft_bound, qright_bound);
        return left_ans + right_ans;
    }
    void update(int qleft_bound, int qright_bound, int val){
        if(qright_bound < left_bound || right_bound < qleft_bound)
            return;
        if(qleft_bound <= left_bound && right_bound <= qright_bound){
            lazy += val;
            sum += val;
            return;
        }
        create_children();
        propagate();
        left_child->update(qleft_bound, qright_bound, val);
        right_child->update(qleft_bound, qright_bound, val);
        sum = left_child->sum + right_child->sum;
    }
};
/*
Node* root = new Node(0, n-1);
root->update(l,r,x)
root->query(l,r)
*/
