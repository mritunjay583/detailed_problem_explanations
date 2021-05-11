#include<bits/stdc++.h>


using namespace std;

class Interval
{
    public:
    int left,right;
    Interval(){}
    Interval(int _left,int _right){
        left = _left;
        right = _right;
    }
};

class IntervalTreeNode{
    public:
    Interval *interval;
    int max;
    IntervalTreeNode *left,*right;
    IntervalTreeNode(Interval *_interval,int _max){
        interval = _interval;
        max = _max;
        left=right=NULL;
    }
};

class IntervalTree
{
public:
    IntervalTreeNode *root;
    IntervalTree(){
        root = NULL;
    }
    IntervalTreeNode* insert(IntervalTreeNode *root,Interval *interval){
        if(root==NULL){
            return new IntervalTreeNode(interval,interval->right);
        }
        if(root->interval->left>interval->left){
            
            root->left = insert(root->left,interval);
        }else{
            root->right = insert(root->right,interval);
        }

        if(root->max<interval->right){
            root->max=interval->right;
        }
        return root;
    }
    void inorder(IntervalTreeNode *root){
        if(root==NULL){
            return;
        }
        inorder(root->left);
        cout<<"["<<root->interval->left<<","<<root->interval->right<<"]"<<"max : "<<root->max<<endl;
        inorder(root->right);
    }
    
    void intervalOverlaps(IntervalTreeNode *root,Interval *interval){
        if(root==NULL){
            return;
        }
        if(overlaps(root->interval,interval))
            cout<<"["<<root->interval->left<<","<<root->interval->right<<"]"<<endl;
        intervalOverlaps(root->left,interval);
        intervalOverlaps(root->right,interval);
    }
    private:
    bool overlaps(Interval *i1,Interval *i2){
        if(i1->left<=i2->right && i1->right>=i2->left){
            return true;
        }else{
            return false;
        }
    }
};

int main(){
    IntervalTree t;
    Interval ints[] = {{15, 20}, {10, 30}, {17, 19},
        {5, 20}, {12, 15}, {30, 40}
    };
    int n = sizeof(ints)/sizeof(ints[0]);
    for(int i=0;i<n;i++){
        if(left<right){
            t.root=t.insert(t.root,new Interval(ints[i].left,ints[i].right));
        }
    }
    t.inorder(t.root);
    t.intervalOverlaps(t.root,new Interval(6,18));
}

