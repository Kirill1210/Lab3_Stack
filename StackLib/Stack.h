#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <fstream>

using namespace std;

template <typename T>
class TStack
{
private:
  T* stackPtr;                      // ��������� �� ����
  const int size;                   // ������������ ���������� ��������� � �����
  int num;                          // ����� �������� �������� �����
public:
  TStack(int = 10);                  // �� ��������� ������ ����� ����� 10 ���������
  TStack(const TStack<T>&);          // ����������� �����������
  ~TStack();                         // ����������

  inline void push(const T&);     // ��������� ������� � ������� �����
  inline T del();                   // ������� ������� �� ������� ����� � ������� ���
  inline const T& Peek(int) const; // n-� ������� �� ������� �����
  inline int getStackSize() const;  // �������� ������ �����
  inline T* getPtr() const;         // �������� ��������� �� ����
  inline int getNum() const;        // �������� ����� �������� �������� � �����

  //��� �������
  inline int min_elem(); //����� ������������ ��������
  inline int max_elem(); //����� ������������� ��������
  inline void file(); //������ � ����

  friend ostream& operator<<(ostream& out, const TStack& st)
  {
    for (int ix = st.num - 1; ix >= 0; ix--)
      cout << st.stackPtr[ix] << endl;
    return out;
  }
};

// ����������� �����
template <typename T>
TStack<T>::TStack(int maxSize) : size(maxSize) // ������������� ���������
{
  if (maxSize < 0)
  {
    throw "Error";
  }
  stackPtr = new T[size]; // �������� ������ ��� ����
  num = 0; // �������������� ������� ������� �����;
}

// ����������� �����������
template <typename T>
TStack<T>::TStack(const TStack<T>& otherStack) : size(otherStack.getStackSize()) // ������������� ���������
{
  stackPtr = new T[size]; // �������� ������ ��� ����� ����
  num = otherStack.getNum();

  for (int ix = 0; ix < num; ix++)
  {
    stackPtr[ix] = otherStack.getPtr()[ix];
  }
}

template <typename T>
TStack<T>::~TStack()
{
  if (this->stackPtr != NULL)
  {
    delete[] stackPtr; // ������� ����
  }
  num = 0;
}

// ������� ���������� �������� � ����
template <typename T>
inline void TStack<T>::push(const T& value)
{
  if (num > size-1 || num < 0)
  {
    throw "Error";
  }

  stackPtr[num++] = value; // �������� ������� � ����
}

// ������� �������� �������� �� �����
template <typename T>
inline T TStack<T>::del()
{
  if (num < 0)
  {
    throw "Error";
  }

  stackPtr[--num]; // ������� ������� �� �����

  return stackPtr[num];
}

// ������� ���������� n-� ������� �� ������� �����
template <class T>
inline const T& TStack<T>::Peek(int Elem) const
{
  if (Elem > num)
  {
    throw "Error";
  }
  return stackPtr[num - Elem]; // ������� n-� ������� �����
}

// ������� ������ �����
template <typename T>
inline int TStack<T>::getStackSize() const
{
  return size;
}

// ������� ��������� �� ���� (��� ������������ �����������)
template <typename T>
inline T* TStack<T>::getPtr() const
{
  return stackPtr;
}

// ������� ������ �����
template <typename T>
inline int TStack<T>::getNum() const
{
  return num;
}

template<typename T>
inline int TStack<T>::max_elem()
{
  int res = stackPtr[0];
  for (int i = 1; i < size; i++)
  {
    if (stackPtr[i] > res)
    {
      res = stackPtr[i];
    }
  }
  return res;
}

template<typename T>
inline int TStack<T>::min_elem()
{
  int res = stackPtr[0];
  for (int i = 1; i < size; i++)
  {
    if (stackPtr[i] < res)
    {
      res = stackPtr[i];
    }
  }
  return res;
}

template<typename T>
inline void TStack<T>::file()
{
  ofstream outf("Data.txt");
  if (!outf)
  {
    throw "Error file";
  }
  for (int i = 0; i < size; i++)
  {
    outf << stackPtr[i] << endl;
  }
}
#endif