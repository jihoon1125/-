#include "LocationHeap.h"

LocationHeap::LocationHeap()
{
    /* memory allocate for 7 cities */
    Heap = new LocationHeapNode*[8];
    size = 0;

    for (int i = 0; i < 8; i++)
    {
        Heap[i] = new LocationHeapNode();
    }
}

LocationHeap::~LocationHeap()
{
    /* memory deleting for 7 cities */
    for (int i = 0; i < 8; i++) {
        delete Heap[i];
    }
    delete Heap;
}

bool LocationHeap::Insert(char * location)
{
    //BPOP
    bool preexist = false;
    for (int i = 1; i < size + 1; i++)//if pre-exists, just increase number, not inserting additional node
    {
        if (!strcmp(location, Heap[i]->GetLoc())) {
            Heap[i]->SetCount(Heap[i]->GetCount() + 1);
            preexist = true;
            break;
        }
    }

    if (preexist == false)//if not pre-exists, add new node and increase heap size
    {        
        size++;
        Heap[size]->SetCount(1);
        Heap[size]->SetLoc(location);       
    }

    else {//if pre-existed, needs to be rearranged
        /* make new_heap, pop from heap and insert to new_heap  */
        vector<LocationHeapNode*> v;

        LocationHeapNode** new_heap = new LocationHeapNode * [8];
        for (int i = 0; i < 8; i++)
        {
            new_heap[i] = new LocationHeapNode();
        }
        int new_heapsize = 0, currnode = 0;
                      
        for (int i = 1; i < size + 1; i++)
            v.push_back(Heap[i]);        
       
        while (new_heapsize < size) {
            /* heap insertion */
            currnode = ++new_heapsize;
            
            LocationHeapNode* temp = v.back();
            v.pop_back();

            while (currnode != 1 && new_heap[currnode / 2]->GetCount() < temp->GetCount())
            {
                new_heap[currnode]->SetCount(new_heap[currnode/2]->GetCount());
                new_heap[currnode]->SetLoc(new_heap[currnode / 2]->GetLoc());
                currnode /= 2;
            }

            new_heap[currnode]->SetCount(temp->GetCount());
            new_heap[currnode]->SetLoc(temp->GetLoc());           
        }

        /* deleting previous heap */
        for (int i = 0; i < 8; i++) {
            delete Heap[i];
        }
        delete Heap;

        Heap = new_heap;
    }
    return true;//heap arranged completed
}

void LocationHeap::Print()
{
    //PRINT H
    ofstream flog;
   
    if (size == 0) { //error, size 0
        flog.open("log.txt", ios::app);
        flog << "========== Error ==========" << endl;
        flog << "500" << endl;
        flog << "===========================" << endl << endl;
        flog.close();
        return;
    }
    else {//just print heap sequentially
        flog.open("log.txt", ios::app);
        flog << "========== PRINT ==========" << endl;
        flog << "Heap" << endl;
        for (int i = 1; i < size + 1; i++)        
            flog << Heap[i]->GetCount() << '/' << Heap[i]->GetLoc() << endl;  
        flog << "===========================" << endl << endl;
        flog.close();
        return;
    }   
}
