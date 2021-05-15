#include "LocationBST.h"

LocationBST::LocationBST()
{
    Root = new LocationNode();//construct just once
    Root->SetLoc("Gwangju");
    Insert_Location(Root);//construct every location's LocationNode
}

LocationBST::~LocationBST()
{
    DestroyBST(Root);    //destruct BST
}

void LocationBST::DestroyBST(LocationNode* root) {//freeing LocationNodes
    if (root == NULL) return;
    DestroyBST(root->GetLeft());
    DestroyBST(root->GetRight());
    delete root;
}


LocationNode * LocationBST::GetRoot()
{
    return Root;
}

void LocationBST::Insert_Location(LocationNode* node)//construct every locations
{
    LocationNode Daegu, Seoul, Busan, Daejeon, Incheon, Ulsan;
    Daegu.SetLoc("Daegu"); Seoul.SetLoc("Seoul"); Busan.SetLoc("Busan");
    Daejeon.SetLoc("Daejeon"); Incheon.SetLoc("Incheon"); Ulsan.SetLoc("Ulsan");

    node->SetLeft(&Daegu); node->SetRight(&Seoul);
    node->GetLeft()->SetLeft(&Busan); node->GetLeft()->SetRight(&Daejeon);
    node->GetRight()->SetLeft(&Incheon); node->GetRight()->SetRight(&Ulsan);
}
   

bool LocationBST::Insert_Patient(PatientNode * node)
{
    //QPOP
    LocationNode* curr = Root;
    
    string insert_loc = node->GetLoc();
    string curr_loc = Root->GetLoc();

    while (curr != NULL)//search proper location
    {
        if (insert_loc.compare(curr_loc) < 0)
            curr = curr->GetLeft();
        else if (insert_loc.compare(curr_loc) > 0)
            curr = curr->GetRight();
        else//if found location, insert node to the locationnode's BST
        {
            curr->GetBST()->Insert(node);
            return true;//successfully insert
        }

        curr_loc = curr->GetLoc();
    }

    return false;//insert failed

}

bool LocationBST::Search(char * name)
{
    //SEARCH
    if (name == NULL) return false;

    LocationNode* curr = Root, * left = NULL, * right = NULL;    

        left = curr->GetLeft();
        right = curr->GetLeft();
        if (curr->GetBST()->Search(name) != true)//if search failed in Root
        {
            if (curr->GetLeft()->GetBST()->Search(name) == true || curr->GetRight()->GetBST()->Search(name) == true)//search in child node
                 return true;

            curr = curr->GetLeft();//go to left child

            if (curr->GetLeft()->GetBST()->Search(name) == true || curr->GetRight()->GetBST()->Search(name) == true)//search in child node
                return true;

            curr = Root->GetRight();//go to root's right child

            if (curr->GetLeft()->GetBST()->Search(name) == true || curr->GetRight()->GetBST()->Search(name) == true)//search in child node
                return true;

        }

        else return true;//found in root          

  

    return false;// name not found


}

char * LocationBST::Delete(char * name)
{
    //BPOP
    LocationNode* curr = Root, * left = NULL, * right = NULL;

  
        left = curr->GetLeft();
        right = curr->GetRight();
        if (curr->GetBST()->Delete(name) != true)//if delete failed in root, find in child's node
        {
            if (curr->GetLeft()->GetBST()->Delete(name) == true)
                return curr->GetLeft()->GetLoc();

            if (curr->GetRight()->GetBST()->Delete(name) == true)
                return curr->GetRight()->GetLoc();

            curr = curr->GetLeft();

            if (curr->GetLeft()->GetBST()->Delete(name) == true)
                return curr->GetLeft()->GetLoc();

            if (curr->GetRight()->GetBST()->Delete(name) == true)
                return curr->GetRight()->GetLoc();

            curr = Root->GetRight();

            if (curr->GetLeft()->GetBST()->Delete(name) == true)
                return curr->GetLeft()->GetLoc();

            if (curr->GetRight()->GetBST()->Delete(name) == true)
                return curr->GetRight()->GetLoc();

        }

        else return curr->GetLoc();//found in root              

 

    return NULL;//not found

}

void LocationBST::Print_PRE(LocationNode* node)
{
    //PRINT B PRE, Print_PRE in PRE_ORDER    
    if (node != NULL) {
        node->GetBST()->Print_PRE(node->GetBST()->GetRoot());
        Print_PRE(node->GetLeft());
        Print_PRE(node->GetRight());
    }

}

void LocationBST::Print_IN(LocationNode* node)
{
    //PRINT B IN , Print_IN in IN_ORDER 
    if (node != NULL) {
        Print_IN(node->GetLeft());
        node->GetBST()->Print_IN(node->GetBST()->GetRoot());
        Print_IN(node->GetRight());
    }
}

void LocationBST::Print_POST(LocationNode* node)
{
    //PRINT B POST, Print_POST in POST_ORDER
    if (node != NULL) {
        Print_POST(node->GetLeft());
        Print_POST(node->GetRight());
        node->GetBST()->Print_POST(node->GetBST()->GetRoot());
    }
}

void LocationBST::Print_LEVEL(LocationNode* node)
{
    //PRINT B LEVEL, Print_Level in LEVEL_ORDER
    queue<LocationNode*> q;

    LocationNode* curnode = Root;

    while (curnode) {
        curnode->GetBST()->Print_LEVEL();
        if (curnode->GetLeft() != NULL)
            q.push(curnode->GetLeft());
        if (curnode->GetRight() != NULL)
            q.push(curnode->GetRight());
        if (q.empty()) return;
        curnode = q.front();
        q.pop();
    }
}
