#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// TEMPLATES FOR BINARY SEARCH !!!!

// finding last element of a number !!!
int last_index(vector<int> a,int target) {

    int l = 0;
    int r = a.size() - 1;
    int mid;

    while(l<r) {
        mid = (l + r + 1) / 2;
        if(a[mid]<=target) {
            l = mid;
        }
        else {
            r = mid - 1;
        }
    }

    return a[l] == target ? l : -1;
}

// first index of a number
int first_index(vector<int> a,int target) {
    int l = 0;
    int r = a.size() - 1;
    int mid;
    while(l<r) {
        mid = (l + r - 1) / 2;
        if(a[mid]>=target) {
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }
    return a[r] == target ? r : -1;
}

/*
EQUAL TO SHOULD BE ON THE SIDE WE ARE TRYING TO 
GET RID OF !
*/

int main() {
    return 0;
}