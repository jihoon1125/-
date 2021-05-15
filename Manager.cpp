#include "Manager.h"

Manager::Manager()//manager constructor
{
    ds_queue = new queue<PatientNode*>;
    ds_bst = NULL;
    ds_heap = NULL;

}

Manager::~Manager()
{
    delete ds_queue, ds_bst, ds_heap;
}

void Manager::run(const char * command)
{
    fin.open(command);
    char* context=NULL;
    flog.open("log.txt", ios::app);
    if(!fin)
    {
        flog << "File Open Error" << endl;
        return;
    }

    char cmd[32];
    
    while (fin.getline(cmd, 32))//read from command.txt until eof
    {                
        char * tmp = strtok(cmd, " ");
        if(strcmp(tmp, "LOAD") == 0)//LOAD command
        {
            if(LOAD())
            {
                PrintSuccess("LOAD");
            }
            else
            {
                PrintErrorCode(100);
            }
        }

        else if (strcmp(tmp, "ADD") == 0)//ADD command
        {
            char* patient_info[4];

            for (int i = 0; i < 4; i++) //store patient's information
                patient_info[i] = strtok(NULL, " ");
            
            
            if (ADD(patient_info))//printing result in flog if true
            {
                flog << "========== " << "ADD" << " ==========" << endl;
                flog << patient_info[0] << '/' << patient_info[1] << '/' << patient_info[2] << '/' << patient_info[3] << endl;
                flog << "============================" << endl << endl;
            }
            else
            {
                PrintErrorCode(200);
            }
        }
        
        else if (strcmp(tmp, "QPOP") == 0)//QPOP command
        { 
            if (QPOP(atoi(strtok(NULL, " "))))
            {
                PrintSuccess("QPOP");
            }
            else
            {
                PrintErrorCode(300);
            }
        }

        else if (strcmp(tmp, "SEARCH") == 0)//SEARCH command
        {
            if (SEARCH(strtok(NULL, " ")) == false)
            {
                PrintErrorCode(400);
            }            
        }

        else if (strcmp(tmp, "PRINT") == 0)//PRINT command
        {
            char* arg[2];
            arg[0] = strtok(NULL, " ");//check B/H
            arg[1] = strtok(NULL, " ");//check print order
            if (PRINT(arg) == false)
            {
                PrintErrorCode(500);
            }
        }

        else if (strcmp(tmp, "BPOP") == 0)//BPOP command
        {
            char* name = strtok(NULL, " ");//patient's name
            if (BPOP(name) == true)
            {
                PrintSuccess("BPOP");
            }
            else
            {
                PrintErrorCode(600);
            }

        }

        else if(strcmp(tmp, "EXIT") == 0)//EXIT command
        {
            PrintSuccess("EXIT");
            break;
        }
        else
        {
            flog << "========== ERROR ==========" << endl;
            flog << "Command Error" << endl;
            flog << "===========================" << endl << endl;
        }
        
    }
    fin.close();
    flog.close();
}

bool Manager::LOAD()
{
    if (ds_bst != NULL) return false;//bst already exists
    
    else {
        ds_bst = new LocationBST();
        ds_heap = new LocationHeap();
    }

    ifstream datain;
    char data[32];
    char* context = NULL;
    datain.open("data.txt");
    if (!datain.is_open()) return false;   //file open failed
   
    while (datain.getline(data, 100))    
    {        
         
        /* gather information from data */
        char* name = strtok(data, " ");
        float temperature = (float)atof(strtok(NULL, " "));
        char cough = *(strtok(NULL, " "));
        char* location = strtok(NULL, " ");

        /* push data to ds_queue*/
        PatientNode* patient = new PatientNode();
        patient->SetName(name);
        patient->SetTemp(temperature);
        patient->SetCough(cough);
        patient->SetLoc(location);
        ds_queue->push(patient);
    }

    return true;


}

bool Manager::ADD(char** p_info)
{
    /* almost same as LOAD but not loading datafrom data.txt,
       client enter data directly. */
    PatientNode* patient = new PatientNode();

    for (int i = 0; i < 4; i++)
    {
        if (p_info[i] == NULL)
            return false;
    }
       
     patient->SetName(p_info[0]);
     patient->SetTemp((float)atof(p_info[1]));
     patient->SetCough(*(p_info[2]));
     patient->SetLoc(p_info[3]);
        
     ds_queue->push(patient);    

     return true;
    
}

bool Manager::QPOP(int pop_num)
{
    if (pop_num > ds_queue->size())//compare with queue size
        return false;

    else {
        for (int i = 0; i < pop_num; i++)
        {
            ds_bst->Insert_Patient(ds_queue->front());//Insert node into ds_bst
            ds_queue->pop();//pop from ds_queue
        }
    }

    return true;
}

bool Manager::SEARCH(char * name)
{
    return (ds_bst->Search(name));//just operate Search function
}

bool Manager::PRINT(char ** arg)
{
    if (*arg[0] == 'B' && arg[1] == NULL) //patient_bst print with no search option
        return false;

    if (*arg[0] == 'B')
    {
        if (!strcmp(arg[1], "PRE"))//preorder print
        {
            flog << "========== PRINT ==========" << endl;
            flog << "BST" << endl;
            flog.close();
            ds_bst->Print_PRE(ds_bst->GetRoot());
            flog.open("log.txt", ios::app);
            flog << "============================" << endl << endl;
            return true;
        }
        else if (!strcmp(arg[1], "IN"))//inorder print
        {
            flog << "========== PRINT ==========" << endl;
            flog << "BST" << endl;
            flog.close();
            ds_bst->Print_IN(ds_bst->GetRoot());
            flog.open("log.txt", ios::app);
            flog << "============================" << endl << endl;
            return true;
        }
        else if (!strcmp(arg[1], "POST"))//post order print
        {
            flog << "========== PRINT ==========" << endl;
            flog << "BST" << endl;
            flog.close();
            ds_bst->Print_POST(ds_bst->GetRoot());
            flog.open("log.txt", ios::app);
            flog << "============================" << endl << endl;
            return true;
        }
        else if (!strcmp(arg[1], "LEVEL"))//level order print
        {
            flog << "========== PRINT ==========" << endl;
            flog << "BST" << endl;
            flog.close();
            ds_bst->Print_LEVEL(ds_bst->GetRoot());
            flog.open("log.txt", ios::app);
            flog << "============================" << endl << endl;
            return true;
        }
        else return false; //unexpected option


    }

    else if (*arg[0] == 'H')
    {        
        flog.close();
        ds_heap->Print();
        flog.open("log.txt", ios::app);        
        return true;
    }

    else return false; // not 'B' or 'H'
}

bool Manager::BPOP(char* name)
{
    if (name == NULL) return false;

    char* delete_result;
    delete_result = ds_bst->Delete(name);//delete from ds_bst

    if (delete_result == 0) return false;
    else {
        ds_heap->Insert(delete_result);//update ds_heap
        return true;
    }

}


void Manager::PrintErrorCode(int num)
{
    flog << "========== ERROR ==========" << endl;
    flog << num << endl;
    flog << "===========================" << endl << endl;
}

void Manager::PrintSuccess(const char * act)
{
    flog << "========== " << act << " ==========" << endl;
    flog << "Success" << endl;
    flog << "============================" << endl << endl;
}
