//
// Created by Olcay Taner YILDIZ on 8.02.2023.
//

#include <string.h>
#include "../src/Bootstrap.h"
#include <stdio.h>

void testSmallSample(){
    char* s[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10"};
    Array_list_ptr small_sample = create_array_list_of_string(s, 10);
    Bootstrap_ptr bootstrap = create_bootstrap(small_sample, 1);
    Array_list_ptr bootstrap_sample = get_sample(bootstrap);
    if (strcmp(array_list_get(bootstrap_sample, 0) , "4") != 0){
        printf("Test failed in testSmallSample\n");
    }
    if (strcmp(array_list_get(bootstrap_sample, 1) , "7") != 0){
        printf("Test failed in testSmallSample\n");
    }
    if (strcmp(array_list_get(bootstrap_sample, 2) , "8") != 0){
        printf("Test failed in testSmallSample\n");
    }
    if (strcmp(array_list_get(bootstrap_sample, 3) , "6") != 0){
        printf("Test failed in testSmallSample\n");
    }
    if (strcmp(array_list_get(bootstrap_sample, 4) , "4") != 0){
        printf("Test failed in testSmallSample\n");
    }
    if (strcmp(array_list_get(bootstrap_sample, 5) , "6") != 0){
        printf("Test failed in testSmallSample\n");
    }
    free_array_list(small_sample, NULL);
    free_bootstrap(bootstrap, NULL);
}

int main(){
    testSmallSample();
}