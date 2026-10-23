#include <iostream>
#include <cstdlib> //for generating random integers
#include <time.h> //will be used for our seeding function
#include "node.h"
#include "searchingAlgo.h"

const int max_size = 50;

//generates random values
int main() {

    //generates random values
    int dataset[max_size];
    srand(time(0));

    for(int i=0; i<max_size; i++){
        dataset[i] = rand();
    }

    for(int i=0; i < max_size; i++){
       std::cout << dataset[i] << " ";
    }

    std::cout<<std::endl;

    //create a user input to ask what value to find
    int toFind;
    std::cout<<"what value you want to search?";
    std::cin >> toFind;

    linearSearchArr(dataset, max_size, toFind);


    //linear search:

    //linked list: R Y A N 6 2 7
    Node<char>* name1  = new_node('R');
    Node<char>* name2  = new_node('Y');
    Node<char>* name3  = new_node('A');
    Node<char>* name4  = new_node('N');
    Node<char>* name5  = new_node('6');
    Node<char>* name6  = new_node('2');
    Node<char>* name7  = new_node('7');

    name1->next = name2;
    name2->next = name3;
    name3->next = name4;
    name4->next = name5;
    name5->next = name6;
    name6->next = name7;


    std::cout <<"linear search for linked list result: ";
    linearSearchLL(name1, '7');

    std::cout <<"linear search for linked list result: ";
    linearSearchLL(name1, 'X');


    //implement it here
    //sort the array first for binary search
    for(int i = 0; i < max_size - 1; i++){
        for(int j = 0; j < max_size - i - 1; j++){

            if(dataset[j] > dataset[j + 1]){
                int temp = dataset[j];
                dataset[j] = dataset[j + 1];
                dataset[j + 1] = temp;
            }
        }
    }

    //display the sorted array
    std::cout << "\nSorted array: ";

    for(int i = 0; i < max_size; i++){
        std::cout << dataset[i] << " ";
    }

    std::cout << std::endl;

    //binary search using array
    std::cout << "binary search for array result: ";
    binarySearchArr(dataset, max_size, toFind);


    //binary search using linked list
    //The linked list must be sorted for binary search
    Node<int>* num1 = new_node(10);
    Node<int>* num2 = new_node(20);
    Node<int>* num3 = new_node(30);
    Node<int>* num4 = new_node(40);
    Node<int>* num5 = new_node(50);
    Node<int>* num6 = new_node(60);
    Node<int>* num7 = new_node(70);

    num1->next = num2;
    num2->next = num3;
    num3->next = num4;
    num4->next = num5;
    num5->next = num6;
    num6->next = num7;

    std::cout << "binary search for linked list result: ";
    binarySearchLL(num1, 40);

    std::cout << "binary search for linked list result: ";
    binarySearchLL(num1, 100);

}