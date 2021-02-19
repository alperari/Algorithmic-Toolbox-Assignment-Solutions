#include <iostream>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

int fibonacci_sum_fast(unsigned long long int n)
{
    int fiboList[n + 1];
    fiboList[0] = 0;
    fiboList[1] = 1;
    int sum = 1;
    for (int i = 2; i < n + 1; i++)
    {
        fiboList[i] = (fiboList[i - 1] + fiboList[i - 2]) % 10;
        sum = (sum + fiboList[i]) % 10;
    }
    return sum;
}


unsigned long long int get_fibonacci_huge_fast(unsigned long long int n, int m)
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
int fastest_algo(unsigned long long int n)
{
    //okay the rule is :   f1 + f2 + f3 + .... + fn = f(n+2) -1
    int num = get_fibonacci_huge_fast(n + 2, 10);
    if (num == 0)
    {
        return 9;
    }
    else
        return num-1;
}

int main() {
    unsigned long long int n = 0;
    std::cin >> n;
    if (n == 0)
    {
        std::cout << 0 << std::endl;
        return 0;
    }
    std::cout << fastest_algo(n);
}
