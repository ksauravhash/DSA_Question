#include <iostream>
#include <vector>

void sort(std::vector<int>& v) {

    for(int i =0;i<v.size();i++) {
        int j;
        int temp = v[i];
        for(j=i-1;j>=0;j--) {
            if(v[j] > temp) {
                v[j+1]= v[j];
            }else 
                break;
        }
        v[j+1] = temp;
    }

}

void display(std::vector<int>& v) {
    for(auto i = v.begin(); i < v.end(); i++) {
        std::cout << *i << " ";
    }
}

int main()
{
    std::vector<int> v = {1, 7, 2, 7, 9};

    sort(v);
    display(v);
    
    
}