#ifndef _WORKER_H_
#define _WORKER_H_
#include <iostream>
#include <string>

using namespace std;

class Worker
{
    private:
        string NameWorker;
        string JobTitle;
        int JobYear;

    public:
        Worker();
        Worker(const Worker&);
        Worker(string& inNameWorker, string& inJobTitle, int& inJobYear);
        ~Worker();

        void Print() const;
        void Save(ostream&) const;
        void Load(istream&);
        bool Menu();

        string GetNameWorker();
        string GetJobTitle();
        int GetJobYear();

        void SetNameWorker(string InNameWorker );
        void SetJobTitle(string inJobTitile);
        void SetJobYear(int inJobYear);

        friend ostream& operator << (ostream& os, const Worker&);

	    friend istream& operator >> (istream& in, Worker&);

        bool operator<(Worker&) const;
        bool operator>(Worker&) const;


};


#endif