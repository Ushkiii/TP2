#include "Worker.h"
#include <iostream>
#include <string>
using namespace std;

Worker::Worker(){cout<<"The constructor"<<endl;}

Worker::Worker(const Worker& worker)
{
    NameWorker=worker.NameWorker;
    JobTitle=worker.JobTitle;
    JobYear=worker.JobYear;
    cout<<"The copy construct"<<endl;
}

Worker::Worker(string&inNameWorker, string& inJobTitle, int& inJobYear)
{
    NameWorker=inNameWorker;
    JobTitle=inJobTitle;
    JobYear=inJobYear;
    cout<<"The constructor with parametrs"<<endl;
}

Worker::~Worker(){cout<<"The destructor"<<endl;}

void Worker::SetNameWorker(string InNameWorker)
{
    NameWorker=InNameWorker;
}

string Worker::GetNameWorker(){return NameWorker;}

void Worker::SetJobTitle(string inJobTitle)
{
    JobTitle=inJobTitle;
}

string Worker::GetJobTitle(){return JobTitle;}

void Worker::SetJobYear(int inJobYear)
{
    JobYear=inJobYear;
}


void Worker:: Print()const {
    cout<<"Name:"<<NameWorker<<endl;
    cout<<"JobTitle:"<<JobTitle<<endl;
    cout<<"Year:"<<JobYear<<endl;
}

void Worker:: Save(ostream& os) const{
    os<<"Name:"<<NameWorker<<endl;
    os<<"Jobtitle:"<<JobTitle<<endl;
    os<<"Year:"<<JobYear<<endl;
    os<<"end"<<endl;
    cout<<"The Worker is saved succeesfully"<<endl;
}

void Worker:: Load(istream& is)
{
    while (!is.eof())
    {
        string key, value;
        is>>key;
        if (key=="end")
            break;
        is>>value;
        if (key=="Name:")
            NameWorker=value;
        else if (key=="Jobtitle:")
            {JobTitle=value;}
        else if (key=="Year:")
            {JobYear=stoi(value);}
        cout<<"The Worker is succesfully loaded";
    }
    
}



