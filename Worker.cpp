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