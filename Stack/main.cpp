
#include "Stack.h"

 

 
int main()
{
    TStack<char> stackSymbol(5);
    char ch;
 
    for (int i = 0; i < 5; i++) // помещаем элементы в стек
    {
      cout << "Elem: ";
      cin >> ch;
      stackSymbol.push(ch);
    }
    cout << endl;
    cout << stackSymbol; // печать стека
 
    cout << "\n\nRemove an item from the stack\n";
    stackSymbol.del(); //Удаление элемента
 
    cout << stackSymbol; // печать стека
 
    TStack<char> newStack(stackSymbol); //Конструктор копирования
 
    cout << "\n\nCopy constructor worked\n";
    cout << newStack;
 
    cout << "The second element in the queue: "<< newStack.Peek(2) << endl; //Вывод элемента 2
 
    TStack<int> test(5);
    int t;
    for (int i = 0; i < 5; i++) // помещаем элементы в стек
    {
      cout << "Elem: ";
      cin >> t;
      test.push(t);
    }

    cout << "TEST PEEK   " << test.Peek(2) << endl;
    cout << test.min_elem(); //Поиск мин элемента
    cout << endl << test.max_elem(); //Макс элемента
    test.file(); //Запись в файл. 
    return 0;
}