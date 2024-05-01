/******************************************************************************
Group A1 (Hashing)
Title : Consider telephone book database of N clients. Make use of a hash table
implementation to quickly look up client‘s telephone number. Make use of two collision 
handling techniques and compare them using number of comparisons required to find a set 
of telephone numbers
**********************************************************************************/
#include<iostream>
#include<string>
using namespace std;

class HashTable{
public:
    int size;
    long long number, HashArr[];

    HashTable(int s)
    {
        this->size = s;
        HashArr[size];

        for(int i=0; i<s; i++)
        {
            HashArr[i] = -1;
        }
    }

    void display()
    {
        for(int i=0; i<size; i++)
        {
            cout<<HashArr[i]<<endl;
        }
    }

    void insert(long long n)
    {
        int position = n % 10;
        if(HashArr[position] != -1)
        {
            //linear probing
            // while(HashArr[position] != -1)
            // {
            //     position += 1;
            //     if(position >= size)
            //     {
            //         position = 0;
            //     }
            // }

            //Quadratic Probing
            for(int i=1; i<=10; i++)
            {
                position = (n + (i*i)) % size;
                if(HashArr[position] == -1)
                    break;
            }
        }
        HashArr[position] = n;   

    }//insert

    void search(long long n) 
    {
        int position = n % size;
        int originalPosition = position;

        // Linear probing
        while (HashArr[position] != n) {
            position += 1;
            if (position >= size) {
                position = 0;
            }
            // If we've looped back to the original position, the element is not in the hash table
            if (position == originalPosition) {
                cout << "Element not found" << endl;
                return;
            }
        }

        // If we found the element
        cout << "Element found at position " << position << endl;
    }//search   
};

int main(){
    HashTable MyTable(10);
    int ch;
    do{
        cout<<"1)Insert\n2)Display\n3)search"<<endl;
        cout<<"Enter your choice:";
        cin>>ch;
        cout<<endl;

        switch(ch)
        {
            case 1:{
                long long n;
                cout<<"Enter Phone Number: ";
                cin>>n;
                MyTable.insert(n);
                cout<<endl;
                break;
            }
            case 2:{
                MyTable.display();
                cout<<endl;
                break;
            }
            case 3:{
                long long y;
                cout<<"Enter Phone Number to Search: ";
                cin>>y;
                MyTable.search(y);
                cout<<endl;
                break;
            }
            case 4:{
                break;
            }
            default:{
                cout<<"Enter valid choice"<<endl;  
                break;
            } 
        }
    }while(ch != 4);

    return 0;
}

