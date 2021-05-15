#include "PatientBST.h"

PatientBST::PatientBST()
{
    Root = NULL;//initializa root as null
}

PatientBST::~PatientBST()
{
    DestroyBST(Root);//destruct in recursive way
}

void PatientBST::DestroyBST(PatientBSTNode* root) { //destruct in post-order way
    if (root == NULL) return;//
    DestroyBST(root->GetLeft());
    DestroyBST(root->GetRight());
    delete root;
}

PatientBSTNode * PatientBST::GetRoot()
{
    return Root;
}

bool PatientBST::Insert(PatientNode * node)
{
    //QPOP
    PatientBSTNode* p = Root, *pp = NULL;
    string insert_name(node->GetName());//char* -> string conversion
    string p_name;

    /* go left if insert_name is smaller than p_name */
    while (p!=NULL) {//checing point to be inserted
        pp = p;
        p_name = p->GetName();
        if (insert_name.compare(p_name) < 0) // check string's size
            p = p->GetLeft();
        else//restricting no overlapped name 
            p = p->GetRight();
    }

         /*      starting insertion        */
        p = new PatientBSTNode();//make new node
        p->SetName(node->GetName());
        if (node->GetTemp() >= 37.5 && node->GetCough() == 'Y')
            p->SetDisease('+');//corona
        else
            p->SetDisease('-');//not corona

        if (Root != NULL) {//if previous node existed, insert in pp's childnode
            if (insert_name.compare(p_name) < 0)
                pp->SetLeft(p);
            else
                pp->SetRight(p);
        }
        else//else new node will be root
            Root = p;

        return true;
}

bool PatientBST::Search(char * name)
{
    //SEARCH
    ofstream flog;//to write result in log

    PatientBSTNode* curnode = Root;
    string param_name = name;//name to search
    string tree_name;
    while (curnode != NULL) {
        tree_name = curnode->GetName();
        if (param_name.compare(tree_name) < 0) curnode = curnode->GetLeft();//if searching name is smaller, go left
        else if (param_name.compare(tree_name) > 0) curnode = curnode->GetRight();//"" bigger, go right

        else {//searched successfully, write result in log
            flog.open("log.txt", ios::app);
            flog << "======== SEARCH ========" << endl;
            flog << curnode->GetName() << '/' << curnode->GetDisease() << endl;
            flog << "========================" << endl<<endl;
            flog.close();
            return true;
        }     

    }
    

    return false;//not found, return false
    
}

bool PatientBST::Delete(char * name)
{
    //BPOP
    if (Root == NULL) return false; //empty BST, return false

    PatientBSTNode* p = Root, * q = NULL;
    string del_name = name;
    string p_name = Root->GetName();
    while (p != NULL && del_name.compare(p_name) != 0) { //while p is not null and deleting name not found      
        q = p;
        
        if (del_name.compare(p_name) < 0) p = p->GetLeft();//if smaller, go left
        else    p = p->GetRight();//bigger, go right

        if (p == NULL) return false; //name not found fianlly... return false
        p_name = p->GetName();
     }

    //p search completed, now there are four cases in delete

    if (p->GetLeft() != NULL && p->GetRight() != NULL) {//Leaf case(no child), just delete and set parent's child as NULL
        if (q == NULL) Root = NULL;
        else if (q->GetLeft() == p)  q->SetLeft(NULL);
        else q->SetRight(NULL);
        delete p;
    }

    else if (p->GetLeft() == NULL) //has only right child
    {
        /* set parent's child as node's right child*/
        if (q == NULL) Root = p->GetRight();
        else if (q->GetLeft() == p) q->SetLeft(p->GetRight());
        else q->SetRight(p->GetRight());

        delete p;
    }

    else if (p->GetRight() == NULL) // has only left child
    {
        /* set parent's child as node's left child*/
        if (q == NULL) Root = p->GetLeft();
        else if (q->GetLeft() == p) q->SetLeft(p->GetLeft());
        else q->SetRight(p->GetLeft());

        delete p;
    }

    //now node has both child
    else {
        PatientBSTNode* prevprev = p, * prev = p->GetLeft(),//finding biggeste node in left subtree
            * curr = p->GetLeft()->GetRight();

        while (curr) {
            prevprev = prev;//prevprev is prev's parent
            prev = curr;//prev will be node to be deleted
            curr = curr->GetRight();//curr will be NULL
        }
              
        /* now replace p's value by prev's value*/
        p->SetName(prev->GetName());
        p->SetDisease(prev->GetDisease());
        if (prevprev == p) prevprev->SetLeft(prev->GetLeft());//left subtree doesn't have right node
        else    prevprev->SetRight(prev->GetLeft());//if have right node, preprev's right child will be prev's left subtree
        delete prev;
    }
    return true;//delete successed
}

void PatientBST::Print_PRE(PatientBSTNode * node)
{
    //PRINT B PRE
    ofstream flog;   //print name, disease in here by PRE-ORDER

    if (node != NULL) {
        flog.open("log.txt", ios::app);
        flog << node->GetName() << '/' << node->GetDisease() << endl;
        flog.close();
        Print_PRE(node->GetLeft());
        Print_PRE(node->GetRight());
    }    

    
}

void PatientBST::Print_IN(PatientBSTNode * node)
{
    //PRINT B IN
    ofstream flog;  //print name, disease in here by IN-ORDER

    if (node != NULL) {
        Print_IN(node->GetLeft());
        flog.open("log.txt", ios::app);
        flog << node->GetName()  << '/' << node->GetDisease() << endl;
        flog.close();
        Print_IN(node->GetRight());
    }
}

void PatientBST::Print_POST(PatientBSTNode * node)
{
    //PRINT B POST
    ofstream flog;    //print name, disease in here by POST-ORDER

    if (node != NULL) {
        Print_POST(node->GetLeft());
        Print_POST(node->GetRight());
        flog.open("log.txt", ios::app);
        flog << node->GetName() + '/' + node->GetDisease() << endl;
        flog.close();
    }
}

void PatientBST::Print_LEVEL()
{
    //PRINT B LEVEL
    queue<PatientBSTNode*> q;
    ofstream flog;
    flog.open("log.txt", ios::app);

    PatientBSTNode* curnode = Root;
    while (curnode) {//pushing node sequentially and popping repeatedly
        flog << curnode->GetName() << '/' << curnode->GetDisease() << endl;
        if (curnode->GetLeft() != NULL)
            q.push(curnode->GetLeft());
        if (curnode->GetRight() != NULL)
            q.push(curnode->GetRight());
        if(q.empty()) return;
        curnode = q.front();
        q.pop();
    }

    flog.close();
}
