#include <iostream>

int main(){

    // point to the another address
    int number = 10;
    int *ptr = new int (5);
    ptr = &number;       //lose track of the address of {new int(5)}

    //double allocation
    int *ptr2 = new int(7);
    ptr2 = new int(10);
}

//using valgrind ./a.out result:

/*

==19935== Memcheck, a memory error detector
==19935== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==19935== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
==19935== Command: ./a.out
==19935==
==19935==
==19935== HEAP SUMMARY:
==19935==     in use at exit: 4 bytes in 1 blocks
==19935==   total heap usage: 2 allocs, 1 frees, 72,708 bytes allocated
==19935==
==19935== LEAK SUMMARY:
==19935==    definitely lost: 4 bytes in 1 blocks
==19935==    indirectly lost: 0 bytes in 0 blocks
==19935==      possibly lost: 0 bytes in 0 blocks
==19935==    still reachable: 0 bytes in 0 blocks
==19935==         suppressed: 0 bytes in 0 blocks
==19935== Rerun with --leak-check=full to see details of leaked memory
==19935==
==19935== For lists of detected and suppressed errors, rerun with: -s
==19935== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

*/