/*

    Author: Vinay Kumar Agrawal
    Date Created: 12/04/2019
    Description: Visualization of Bubble sort Algorithm using graphics.h library.

*/
#include <iostream>
#include <graphics.h>
#include <conio.h>

class Sorting {
    int *values;
    int size, range;
    void draw(int i, int color = WHITE) {
        int y = getmaxy();
        setcolor(color);
        line(i, y, i, y - values[i]);
    }
    void _swap(int i, int j) {
        draw(i, BLACK);
        draw(j, BLACK);

        int temp = values[i];
        values[i] = values[j];
        values[j] = temp;

        draw(i, GREEN);
        draw(j, GREEN);
    }
public:
    Sorting(int size = 500, int range = 500){
        this -> size = size;
        this -> range = range;
        int gd = DETECT, gm;
        initwindow(this->size + 10, this->range + 10);
        values = new int[this -> size];
        for(int i = 0; i < this -> size; i++)
            values[i] = rand()%this->range;
        for(int i = 0; i < size; i++) {
            draw(i);
        }
    }

    void visualize() {
        for(int i = 0; i < size - 1; i++) {
            for(int j = 0; j < size - i - 1; j++) {
                draw(j,RED);
                draw(j+1,RED);
                if(values[j] > values[j+1])
                    _swap(j,j+1);
                draw(j,WHITE);
                draw(j+1,WHITE);
            }
            draw(size-i-1,GREEN);
        }
    }

    ~Sorting(){
        getch();
        closegraph();
    }
};

//Driver Function
int main()
{
    int size;
    std::cout<<"Enter Size of the Sorting Array: ";
    std::cin>>size;
    Sorting s(size);        //First Parameter: Size of the Array, Second Parameter: Max value for each element.
    s.visualize();          //Call this function to display the visualization.
}



