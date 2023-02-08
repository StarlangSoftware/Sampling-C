//
// Created by Olcay Taner YILDIZ on 8.02.2023.
//

#include <ArrayList.h>
#include <string.h>
#include <stdio.h>
#include "../src/KFoldCrossValidation.h"

void testSmallSample10Fold(){
    char* s[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10"};
    Array_list_ptr small_sample = create_array_list();
    for (int i = 0; i < 10; i++){
        array_list_add(small_sample, s[i]);
    }
    K_fold_cross_validation_ptr cross_validation = create_k_fold_cross_validation(small_sample, 10, 1);
    Array_list_ptr test_sample = get_test_fold_k_fold(cross_validation, 0);
    if (strcmp(array_list_get(test_sample, 0), "4") != 0){
        printf("Test failed in testSmallSample10Fold\n");
    }
}

void testSmallSample5Fold(){
    char* s[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10"};
    Array_list_ptr small_sample = create_array_list();
    for (int i = 0; i < 10; i++){
        array_list_add(small_sample, s[i]);
    }
    K_fold_cross_validation_ptr cross_validation = create_k_fold_cross_validation(small_sample, 5, 1);
    Array_list_ptr test_sample = get_test_fold_k_fold(cross_validation, 0);
    if (strcmp(array_list_get(test_sample, 0), "3") != 0){
        printf("Test failed in testSmallSample5Fold\n");
    }
    if (strcmp(array_list_get(test_sample, 1), "6") != 0){
        printf("Test failed in testSmallSample5Fold\n");
    }
}

int main(){
    testSmallSample10Fold();
    testSmallSample5Fold();
}