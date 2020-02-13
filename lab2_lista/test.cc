/C++ code to define list element

template <class Type>
class ListElem {
  public:
      ListElem (const Type elem){prev=next=NULL; data=elem;}
  public:
      Type data; // the element data
       ListElem *prev; // next link
       ListElem *next; // next link
};

//pfirst and plast pointers

ListElem *pfirst; //points to the first item in the list
ListElem *plast; //points to the last item in the list

The operations of the doubly linked list are outlines as the functions prototypes shown below:

template <class Type>
class LinkedList {
  public:
    LinkedList(){pfirst=plast=NULL;}
   ~LinkedList();
    void insertNode (const Type&,int);//insert a new item to the list
    void deleteNode(int);//delete item from the list
    void printall();//print out all items on the screen
    int countitem();//return the number of items in the list
    ListElem<Type> *findmin();//show the min item
    ListElem<Type> *findmax();//show the max item
    ListElem<Type> *find(int);//find an item
  protected:
     ListElem<Type> *pfirst; // pfirst element in the list
     ListElem<Type> *plast; // last element in the list
  public:
     ListElem<Type> *temp; //for temporary use only
};
