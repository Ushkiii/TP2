#include "Keeper.h"
#include <iostream>
#include <fstream>
using namespace std;


Keeper::Keeper() {
  m_pFirst    = nullptr;
  m_pLast     = nullptr;
    m_nCounter  = 0;
}
Keeper::~Keeper() {
}

bool Keeper::IsEmpty() const{
  return m_pFirst == nullptr;
}

void Keeper::Push(const Worker& obj) {
  container* buffer = new container;
  buffer->obj = obj;
  if (IsEmpty()) {
        m_pLast = buffer;
    m_pFirst = buffer;
    buffer->next = nullptr;
    m_nCounter++;
    return;
  }
  if (buffer->obj < m_pFirst->obj) {
    buffer->next = m_pFirst;
    m_pFirst = buffer;
    m_nCounter++;
    return;
  }
  if (m_pFirst == m_pLast) {
    if(buffer->obj > m_pFirst->obj){
      buffer->next = nullptr;
      m_pLast = buffer;
      m_pFirst->next = m_pLast;
    }
    else {
      buffer->next = m_pFirst;
      m_pFirst = buffer;
    }
    m_nCounter++;
    return;
  }
  container* buffer_sort = m_pFirst;
  while (buffer_sort->next != nullptr) {
    if (buffer->obj > buffer_sort->next->obj) {
      buffer_sort = buffer_sort->next;
    }
    else if (buffer->obj < buffer_sort->next->obj) {
      buffer->next = buffer_sort->next;
      buffer_sort->next = buffer;
      m_nCounter++;
      return;
    }
    else {
      buffer->next = buffer_sort->next;
      buffer_sort->next = buffer;
      m_nCounter++;
      return;
    }
  }
  buffer->next = nullptr;
  m_pLast->next = buffer;
  m_pLast = buffer;
  m_nCounter++;
}

void Keeper::Save(const string& filename) {
  if (IsEmpty()) {
    cout << "container is empty" << endl;
    return;
  }
  ofstream file(filename);
  if (!file.is_open())
    throw runtime_error("cannot open file");
    
    container* buffer = m_pFirst;
    while (buffer->next != nullptr) {
        buffer->obj.Save(file);
        buffer = buffer->next;
    }
    buffer->obj.Save(file);
  file << "end\n";
    m_pLast = nullptr;
    m_pFirst = nullptr;
    m_nCounter = 0;
    file.close();
}

Keeper Keeper::Load(const string& filename) {
  Keeper keeper;
  ifstream file(filename);
  if (!file.is_open()) 
    throw runtime_error("Cant open file");

    string line;
    while (!file.eof()) {
        Worker obj;
        if(obj.Load(file))
          keeper.Push(obj);
    else
      break;
       // m_nCounter++;
    }
    file.close();
    return keeper;
}

void Keeper::Print() const{
  if (IsEmpty()) {
    cout << "container is empty" << endl;
    return;
  }
  if (m_pFirst == m_pLast) {
    cout << m_pFirst->obj;
    return;
  }
  container* buffer = m_pFirst;
  while (buffer != m_pLast) {
    cout << buffer->obj;
    buffer = buffer->next;
  }
  cout << buffer->obj;
}

void Keeper::Search() const{
  int m_nCounter = 0;
  int key_word;
  cout << "Enter minimum work experience: ";
  cin >> key_word;
  cout << endl;
  container* buffer = m_pFirst;
  while (buffer->next != nullptr) {
    if (2024 - buffer->obj.GetJobYear() >= key_word) {
      cout << buffer->obj << endl;
      m_nCounter++;
    }
    buffer = buffer->next;
  }
  if (2024 - buffer->obj.GetJobYear() >= key_word) {
    cout << buffer->obj << endl;
    m_nCounter++;
  }
  if (m_nCounter == 0) {
    cout << "Container is empty" << endl;
  }
}
void Keeper::Remove() {
  int index = -1;
  if (IsEmpty()) {
    cout << "Container is empty" << endl;
    return;
  };
  container* buffer = m_pFirst;
  for (int i = 0; i < m_nCounter; i++) {
    cout << i + 1 << ". " << buffer->obj.GetNameWorker() << endl;
    buffer = buffer->next;
  }
    do{
        if(index != -1){
            cout << "Incorrect index\n";
        }
      cout << "Enter entity index: ";
      cin >> index;
    }while(index > m_nCounter || index <= 0);

  if (index == 1) {
    buffer = m_pFirst;
    m_pFirst = m_pFirst->next;
    m_nCounter--;
    return;
  }
  if (index == m_nCounter) {
    buffer = m_pFirst;
    while (buffer->next != m_pLast) buffer = buffer->next;
    buffer->next = nullptr;
    delete m_pLast;
    m_pLast = buffer;
    m_nCounter--;
    return;
  }
  buffer = m_pFirst;
  container* buffer_prev = m_pFirst;
  for (int i = 1; i < index; i++) {
    buffer_prev = buffer;
    buffer = buffer->next;
  }
  buffer_prev->next = buffer->next;
  m_nCounter--;
}

void Keeper::Redact(){
    int index = -1;
  if (IsEmpty()) {
    cout << "Container is empty" << endl;
    return;
  };
  container* buffer = m_pFirst;
  for (int i = 0; i < m_nCounter; i++) {
    cout << i + 1 << ". " << buffer->obj.GetNameWorker() << endl;
    buffer = buffer->next;
  }
    do{
        if(index != -1){
            cout << "Incorrect index\n";
        }
      cout << "Enter entity index: ";
      cin >> index;
    }while(index > m_nCounter || index <= 0);

  if (index == 1) {
    cout << "Enter new value: " << endl;
    cin >> m_pFirst->obj;
    return;
  }
  if (index == m_nCounter) {
    cout << "Enter new value: ";
    cin >> m_pLast->obj;
    return;
  }
  buffer = m_pFirst;
  for (int i = 1; i < index; i++) {
    buffer = buffer->next;
  }
  cout << "Enter new value: ";
  cin >> buffer->obj;
  m_nCounter--;
}