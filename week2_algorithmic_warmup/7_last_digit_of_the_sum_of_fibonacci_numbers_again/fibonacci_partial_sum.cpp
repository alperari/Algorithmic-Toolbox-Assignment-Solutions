#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}
 int get_fibonacci_huge_fast(unsigned long long int n, int m)
{
    using namespace std;

    struct node
    {
        unsigned long long int value;
        node* next;
        node* prev;
        node(int x = 0)
        {
            value = x;
            next = nullptr;
            prev = nullptr;
        }
    };
    node* head = nullptr;
    node* n1 = new node(0);
    head = n1;
    node* n2 = new node(1);
    n1->next = n2;
    n2->prev = n1;
    node* n3 = new node(1);
    n2->next = n3;
    n3->prev = n2;

    node* ptr = n3;

    int size = 3;
    while (true)
    {
        node* mynode = new node;

        ptr->next = mynode;
        mynode->prev = ptr;
        ptr = mynode;

        mynode->value = (mynode->prev->value + mynode->prev->prev->value) % m;;
        size++;
        if (ptr->value == 1 && ptr->prev->value == 0)
        {
            node* ptrdel = ptr->prev;
            ptrdel->prev->next = nullptr;
            delete ptrdel;
            delete ptr;
            size -= 2;
            break;
        }

    }
    unsigned long long int arr[size];
    //cout << endl << "sequence is ";
    node* ptr2 = head;
    int i = 0;
    while (ptr2)
    {
        arr[i++] = ptr2->value;
        //cout << ptr2->value << "-";
        ptr2 = ptr2->next;
    }
    //cout << endl << "size is " << size << endl << endl;


    return arr[n % size];
}

int get_fibonacci_partial_sum_fast(unsigned long long int n, unsigned long long int m)
{
    // fact is that this partial sum is equal to Fm+2 - fn+1,
    int sum = get_fibonacci_huge_fast(m + 2, 10) - get_fibonacci_huge_fast(n + 1, 10);
    if (sum < 0)
    {
        return sum + 10;
    }
    return sum;
}

int main() {
    unsigned long long int from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
}
