#include <stdio.h>
#include <linked_list.h>

/*
     - [ ] Implement (I did with tail pointer & without):
        - [ ] size() - returns the number of data elements in the list
        - [ ] empty() - bool returns true if empty
        - [ ] value_at(index) - returns the value of the nth item (starting at 0 for first)
        - [ ] push_front(value) - adds an item to the front of the list
        - [ ] pop_front() - remove the front item and return its value
        - [ ] push_back(value) - adds an item at the end
        - [ ] pop_back() - removes end item and returns its value
        - [ ] front() - get the value of the front item
        - [ ] back() - get the value of the end item
        - [ ] insert(index, value) - insert value at index, so the current item at that index is pointed to by the new item at the index
        - [ ] erase(index) - removes node at given index
        - [ ] value_n_from_end(n) - returns the value of the node at the nth position from the end of the list
        - [ ] reverse() - reverses the list
        - [ ] remove_value(value) - removes the first item in the list with this value
    - [ ] Doubly-linked List
        - [Description (video)](https://www.coursera.org/lecture/data-structures/doubly-linked-lists-jpGKD)
        - No need to implement
 */

int main(void)
{
    printf("Hello World!\n");
    LinkedList *list = create_linked_list();
    display_list(list);
    push_back(list, 10);
    push_front(list, 11);
    display_list(list);
    insert(list, 9, 9);
    display_list(list);
    return 0;
}
