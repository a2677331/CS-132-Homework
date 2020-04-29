/* BST.h contains the declaration of class template BST.
   Basic operations:
     Constructor:           Constructs an empty BST
     empty:                 Checks if a BST is empty
     search:                Search a BST for an item
     insert:                Inserts a value into a BST
     remove:                Removes a value from a BST
     inorder:               Inorder traversal of a BST -- output the data values
     graph:                 Output a grapical representation of a BST
     increaseConcordance:   Function to increase the concordance of a word by 1
     updateLineNum:         Function to receive a value and update line number within the word with that value
     displayAnItem:         Function to display concordance of one specific word
 
   Private utility helper operations:
     search2:                Used by delete
     inorderAux:             Used by inorder
     graphAux:               Used by graph
     increaseConcordanceAux: Used by increaseConcordance
     updateLineNumAux:       Used by updateLineNum
     displayAnItemAux:       Used by displayAnItem
     copyHelper              Used by constructor and assignment operator
 
   Other operations:
     destructor
     copy constructor
     assignment operator
---------------------------------------------------------------------------*/

#include <iostream>

#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

using namespace std;

template <typename DataType>
class BST
{
public:
    /***** Function Members *****/
    BST();
    /*------------------------------------------------------------------------
      Construct a BST object.

      Precondition:  None.
      Postcondition: An empty BST has been constructed.
     -----------------------------------------------------------------------*/
    
    //--- Destructor
    ~BST();
    
    //--- Copy Constructor
    BST(const BST&);
    
    //--- Assignment Operator overloading
    const BST& operator=(const BST& rightObj);
    
    bool empty() const;
    /*------------------------------------------------------------------------
      Check if BST is empty.

      Precondition:  None.
      Postcondition: Returns true if BST is empty and false otherwise.
     -----------------------------------------------------------------------*/

    bool search(const DataType & item) const;
    /*------------------------------------------------------------------------
      Search the BST for item.

      Precondition:  None.
      Postcondition: Returns true if item found, and false otherwise.
     -----------------------------------------------------------------------*/

    void insert(const DataType & item);
    /*------------------------------------------------------------------------
      Insert item into BST.

      Precondition:  None.
      Postcondition: BST has been modified with item inserted at proper
          position to maintain BST property.
    ------------------------------------------------------------------------*/

    void remove(const DataType & item);
    /*------------------------------------------------------------------------
      Remove item from BST.

      Precondition:  None.
      Postcondition: BST has been modified with item removed (if present);
          BST property is maintained.
      Note: remove uses auxiliary function search2() to locate the node
            containing item and its parent.
   ------------------------------------------------------------------------*/

    void inorder(ostream & out) const;
    /*------------------------------------------------------------------------
      Inorder traversal of BST.

      Precondition:  ostream out is open.
      Postcondition: BST has been inorder traversed and values in nodes
          have been output to out.
      Note: inorder uses private auxiliary function inorderAux().
   ------------------------------------------------------------------------*/

    void graph(ostream & out) const;
    /*------------------------------------------------------------------------
      Graphic output of BST.

      Precondition:  ostream out is open.
      Postcondition: Graphical representation of BST has been output to out.
      Note: graph() uses private auxiliary function graphAux().
   ------------------------------------------------------------------------*/

    // Function to increase the concordance of a word by 1
    void increaseConcordance(ostream&, const DataType&);

    // Function to receive a value and update line number within the word with that value
    void updateLineNum (ostream&, const DataType&, const int&);

    // Function to display concordance of one specific word
    void displayAnItem(ostream& out, const DataType& item) const;

private:
    /***** Node class *****/
    class BinNode
    {
    public:
        DataType data;       // word of type string
        BinNode * left;
        BinNode * right;

        // BinNode constructors
        // Default -- data part is default DataType value; both links are null.
        BinNode()
                : left(0), right(0)
        {}

        // Explicit Value -- data part contains item; both links are null.
        BinNode(DataType item)
                : data(item), left(0), right(0)
        {}

    };// end of class BinNode declaration

    typedef BinNode * BinNodePointer;

    /***** Private Function Members *****/
    void search2(const DataType & item, bool & found,
                 BinNodePointer & locptr, BinNodePointer & parent) const;
    /*------------------------------------------------------------------------
      Locate a node containing item and its parent.

      Precondition:  None.
      Postcondition: locptr points to node containing item or is null if
          not found, and parent points to its parent.#include <iostream>
    ------------------------------------------------------------------------*/

    void inorderAux(ostream & out,
                    BinNodePointer subtreePtr) const;
    /*------------------------------------------------------------------------
      Inorder traversal auxiliary function.

      Precondition:  ostream out is open; subtreePtr points to a subtree
          of this BST.
      Postcondition: Subtree with root pointed to by subtreePtr has been
          output to out.
   ------------------------------------------------------------------------*/

    void graphAux(ostream & out, int indent,
                  BinNodePointer subtreeRoot) const;
    /*------------------------------------------------------------------------
      Graph auxiliary function.

      Precondition:  ostream out is open; subtreePtr points to a subtree
          of this BST.
      Postcondition: Graphical representation of subtree with root pointed
          to by subtreePtr has been output to out, indented indent spaces.
   ------------------------------------------------------------------------*/

    // Used by increaseConcordance
    void increaseConcordanceAux(ostream&, BinNodePointer&, const DataType&);
    
    // Used by updateLineNum
    void updateLineNumAux(ostream&, BinNodePointer&, const DataType&, const int&);
    
    // Used by displayAnItem
    void displayAnItemAux(ostream&, const BinNodePointer&, const DataType&) const;
    // Used by constructor and assignment operator
    void copyHelper(BinNodePointer);

    /***** Data Members *****/
    BinNodePointer myRoot;

}; // end of class template declaration

//--- Definition of constructor
template <typename DataType>
inline BST<DataType>::BST()
        : myRoot(0)
{}

//--- Definition of Destructor
template <typename DataType>
BST<DataType>::~BST()
{
    while ( !empty() )
        remove(myRoot->data);
}

//--- Definition of Copy Constructor
template <typename DataType>
BST<DataType>::BST(const BST& oriObj)
{
    myRoot = 0;                 // clean the pointer's garbage value
    copyHelper(oriObj.myRoot);  // copy from oriObj to destination
}

//--- Definition of Assignment Operator
template <typename DataType>
const BST<DataType>& BST<DataType>::operator=(const BST& rightObj)
{
    if (this != &rightObj)                  // if not the same object
    {
        this->~BST<DataType>();             // clean the left one
        copyHelper(rightObj.myRoot);        // copy from right to the left
    }
    return *this;
}

//--- Definition of copyHelper
template <typename DataType>
void BST<DataType>::copyHelper(BinNodePointer oriRoot)
{
    if (oriRoot)                     // if oriRoot is not empty
    {
        insert(oriRoot->data);       // Insert treeNode
        copyHelper(oriRoot->left);   // L
        copyHelper(oriRoot->right);  // R
    }
}

//--- Definition of empty()
template <typename DataType>
inline bool BST<DataType>::empty() const
{ return myRoot == 0; }

//--- Definition of search()
template <typename DataType>
bool BST<DataType>::search(const DataType& item) const
{
    BST<DataType>::BinNodePointer locptr = myRoot;
    bool found = false;
    while (!found && locptr != 0)
    {
        if (item.word < locptr->data.word)       // descend left
            locptr = locptr->left;
        else if (locptr->data.word < item.word)  // descend right
            locptr = locptr->right;
        else                           // item found
            found = true;
    }
    return found;
}

//--- Definition of insert()
template <typename DataType>
inline void BST<DataType>::insert(const DataType & item)
{
    BST<DataType>::BinNodePointer
            locptr = myRoot,   // search pointer
            parent = 0;        // pointer to parent of current node
    bool found = false;     // indicates if item already in BST
    while (!found && locptr != 0)
    {
        parent = locptr;
        if (item.word < locptr->data.word)       // descend left
            locptr = locptr->left;
        else if (locptr->data.word < item.word)  // descend right
            locptr = locptr->right;
        else                           // item found
            found = true;
    }
    if (!found)
    {                                 // construct node containing item
        locptr = new BST<DataType>::BinNode(item);
        if (parent == 0)               // empty tree
            myRoot = locptr;
        else if (item.word < parent->data.word)  // insert to left of parent
            parent->left = locptr;
        else                           // insert to right of parent
            parent->right = locptr;
    }
    else
        cout << "Item already in the tree\n";
}

//--- Definition of remove()
template <typename DataType>
void BST<DataType>::remove(const DataType & item)
{
    bool found;                      // signals if item is found
    BST<DataType>::BinNodePointer
            x,                            // points to node to be deleted
            parent;                       //    "    " parent of x and xSucc
    search2(item, found, x, parent);

    if (!found)
    {
        cout << "Item not in the BST\n";
        return;
    }
    //else
    if (x->left != 0 && x->right != 0)
    {                                // node has 2 children
        // Find x's inorder successor and its parent
        BST<DataType>::BinNodePointer xSucc = x->right;
        parent = x;
        while (xSucc->left != 0)       // descend left
        {
            parent = xSucc;
            xSucc = xSucc->left;
        }

        // Move contents of xSucc to x and change x
        // to point to successor, which will be removed.
        x->data = xSucc->data;
        x = xSucc;
    } // end if node has 2 children

    // Now proceed with case where node has 0 or 1 child
    BST<DataType>::BinNodePointer
            subtree = x->left;             // pointer to a subtree of x
    if (subtree == 0)
        subtree = x->right;
    if (parent == 0)                  // root being removed
        myRoot = subtree;
    else if (parent->left == x)       // left child of parent
        parent->left = subtree;
    else                              // right child of parent
        parent->right = subtree;
    delete x;
}

//--- Definition of inorder()
template <typename DataType>
inline void BST<DataType>::inorder(ostream & out) const
{
    inorderAux(out, myRoot);
}

//--- Definition of graph()
template <typename DataType>
inline void BST<DataType>::graph(ostream & out) const
{ graphAux(out, 0, myRoot); }

//--- Definition of search2()
template <typename DataType>
void BST<DataType>::search2(const DataType & item, bool & found,
                            BinNodePointer & locptr,
                            BinNodePointer & parent) const
{
    locptr = myRoot;
    parent = 0;
    found = false;
    while (!found && locptr != 0)
    {
        if (item.word < locptr->data.word)       // descend left
        {
            parent = locptr;
            locptr = locptr->left;
        }
        else if (locptr->data.word < item.word)  // descend right
        {
            parent = locptr;
            locptr = locptr->right;
        }
        else                           // item found
            found = true;
    }
}

#include <iomanip>
//--- Definition of inorderAux()
template <typename DataType>
void BST<DataType>::inorderAux(ostream & out,
                               BinNodePointer subtreeRoot) const
{
    if (subtreeRoot != 0)
    {
        inorderAux(out, subtreeRoot->left);        // L operation
        out << left << setw(22) << subtreeRoot->data.word
            << setw(21) << subtreeRoot->data.lineNum
            << right << setw(5) << subtreeRoot->data.concord << endl;
        inorderAux(out, subtreeRoot->right);       // R operation
    }
}

//--- Definition of graphAux()
template <typename DataType>
void BST<DataType>::graphAux(ostream & out, int indent,
                             BinNodePointer subtreeRoot) const
{
    if (subtreeRoot != 0)
    {
        graphAux(out, indent + 8, subtreeRoot->right);
        out << setw(indent) << " " << subtreeRoot->data.word << endl;
        graphAux(out, indent + 8, subtreeRoot->left);
    }
}


//--- Definition of increaseConcordance()
template <typename DataType>
void BST<DataType>::increaseConcordance(ostream & out, const DataType& item)
{ increaseConcordanceAux(out, myRoot, item); }

//--- Definition of increaseConcordanceAux()
template <typename DataType>
void BST<DataType>::increaseConcordanceAux(ostream& out, BinNodePointer& subtreeRoot, const DataType& item)
{
    if (item.word < subtreeRoot->data.word)
        increaseConcordanceAux(out, subtreeRoot->left, item);    // L operation
    else if (item.word > subtreeRoot->data.word)
        increaseConcordanceAux(out, subtreeRoot->right, item);    // R operation
    else // found item
        subtreeRoot->data.concord++; // if found item, then increase the word's concordance by 1
}


//--- Definition of updateLineNum()
template <typename DataType>
void BST<DataType>::updateLineNum (ostream & out, const DataType& item, const int& lineNumVal)
  { updateLineNumAux(out, myRoot, item, lineNumVal); }

//--- Definition of updateLineNumAux()
template <typename DataType>
void BST<DataType>::updateLineNumAux(ostream& out, BinNodePointer& subtreeRoot, const DataType& item, const int& NewLineNumVal)
{
    if (item.word < subtreeRoot->data.word)
        updateLineNumAux(out, subtreeRoot->left, item, NewLineNumVal);  // L operation
    else if (item.word > subtreeRoot->data.word)
        updateLineNumAux(out, subtreeRoot->right, item, NewLineNumVal); // R operation
    else
        subtreeRoot->data.lineNum = NewLineNumVal; // if found item, assign a new line number into the word
}


//--- Definition of displayAnItem()
template <typename DataType>
void BST<DataType>::displayAnItem(ostream& out, const DataType& item) const
{ displayAnItemAux(out, myRoot, item); }

//--- Definition of displayAnItemAux()
template <typename DataType>
void BST<DataType>::displayAnItemAux(ostream& out, const BinNodePointer& subtreeRoot, const DataType& item) const
{
    if (item.word < subtreeRoot->data.word)
        displayAnItemAux(out, subtreeRoot->left, item);    // L operation
    else if (item.word > subtreeRoot->data.word)
        displayAnItemAux(out, subtreeRoot->right, item);   // R operation
    else                                                   // if found the item, display it
        out << left << setw(22) << subtreeRoot->data.word
            << setw(21) << subtreeRoot->data.lineNum
            << right << setw(5) << subtreeRoot->data.concord << endl;
}

#endif
