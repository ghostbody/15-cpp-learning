# (15 c++ Lab) D&A Simple List

## Introduction

Knowledge points: (copy) constructor, deep copy, pointers, dynamic allocation, linked list algorithms, debug methods(GDB or IDE or output debug), memory leak.

In this Lab, you are going to implement a class named list which is a simple version for the list in stl. You are going to use dynamic memory allocation and pointer operations to finish this project.

I recommend you to:

1. Learn the knowledge points mentioned above.
2. Use local compilers to test you program rather than submit your answer to the system time after time.
3. Use local debug tools(GDB is recommended) to debug your code, especially for the memory leak problem. I can tell you that you will meet runtime error problem if you don't use local debug tools.
4. Make use of your paper and pen to have some sketches because it's a good way when you meet list.

## Requirements:

Finish all the functions which have been declared inside the hpp file.

Details:

`string toString(void) const`

Return a visible list using '->' to show the linked relation which is a string like:

1->2->3->4->5->NULL

`void insert(int position, const int& data)`

Add an element at the given position:

example0:

1->3->4->5->NULL

instert(1, 2);

1->2->3->4->5->NULL

example1:

NULL

insert(0, 1);

1->NULL;

`void list::erase(int position)`

Erase the element at the given position

1->2->3->4->5->NULL;

erase(0)

2->3->4->5->NULL;

## More

Happy coding...

[c language learning : list](https://github.com/wujr5/c-and-cpp-language-learning/issues/46)
