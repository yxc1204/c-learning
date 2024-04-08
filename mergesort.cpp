#include <iostream>
#include <vector>
#include <algorithm>


void merge(std::vector<int>& ms, int si, int ei){
    int mi = (si+ei)/2; 
    std::vector<int> leftarray;//不是指针
    std::vector<int> rightarray;//int a[], int a[8] 初始化问题;
    int leftarray_rightmostindex = mi - si; 
    int rightarray_rightmostindex = ei - mi - 1; 

    for (int i = si; i <= mi; ++i) {
        leftarray.push_back(ms[i]);
    }
    for (int i = mi+1; i <= ei; ++i) {
        rightarray.push_back(ms[i]);
    }
    //int test = ms[0];

    int i = 0, j = 0; //左右数组的指向index
    int k = 0;
    for( k; i<=leftarray_rightmostindex && j<=rightarray_rightmostindex; k++){
        if(leftarray[i]<=rightarray[j]){
            ms[si+k] = leftarray[i];
            i++;
        }else if(leftarray[i]>rightarray[j]){
            ms[si+k] = rightarray[j];
            j++;
        }
    }
    if(i > leftarray_rightmostindex && j <= rightarray_rightmostindex){
        for (int l = 0; l <= ei-si-k; l++){
            ms[si+k+l] = rightarray[j+l];
        }
    }else if(j > rightarray_rightmostindex && i <= leftarray_rightmostindex){
        for (int l= 0; l <= ei-si-k; l++){
            ms[si+k+l] = leftarray[i+l];
        }
    }
}




void mergesort(std::vector<int>& ms, int si, int ei){
    if(ei-si > 0){
        mergesort(ms, si, (si+ei)/2);
        mergesort(ms, (si+ei)/2+1, ei);
        merge(ms,si,ei);
    }

}
int main(){
    std::vector<int> vec = {4,1,5,2,3,8,7,6,7,3,4};
    mergesort(vec, 0, 10);
    for(int i = 0; i<=10; i++){
        std::cout << vec[i] <<" ";
    }
    std::cout << std::endl; 
    return 0;
}