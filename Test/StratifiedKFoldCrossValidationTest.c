//
// Created by Olcay Taner YILDIZ on 8.02.2023.
//

#include <ArrayList.h>
#include <string.h>
#include <stdio.h>
#include "../src/StratifiedKFoldCrossValidation.h"

void testSmallSample10Fold(){
    char* i1[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10"};
    char* i2[] = {"11", "12", "13", "14", "15", "16", "17", "18", "19", "20",
                  "21", "22", "23", "24", "25", "26", "27", "28", "29", "30"};
    Array_list_ptr small_sample[2];
    small_sample[0] = create_array_list_of_string(i1, 10);
    small_sample[1] = create_array_list_of_string(i2, 20);
    Stratified_k_fold_cross_validation_ptr cross_validation = create_stratified_k_fold_cross_validation(small_sample, 2, 10, 1);
    Array_list_ptr test_sample = get_test_fold_stratified(cross_validation, 0);
    if (strcmp(array_list_get(test_sample, 0), "4") != 0){
        printf("Test failed in testSmallSample10Fold\n");
    }
    if (strcmp(array_list_get(test_sample, 1), "13") != 0){
        printf("Test failed in testSmallSample10Fold\n");
    }
    if (strcmp(array_list_get(test_sample, 2), "21") != 0){
        printf("Test failed in testSmallSample10Fold\n");
    }
    free_array_list(small_sample[0], NULL);
    free_array_list(small_sample[1], NULL);
    free_stratified_k_fold_cross_validation(cross_validation);
}

void testSmallSample5Fold(){
    char* i1[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10"};
    char* i2[] = {"11", "12", "13", "14", "15", "16", "17", "18", "19", "20",
                  "21", "22", "23", "24", "25", "26", "27", "28", "29", "30"};
    Array_list_ptr small_sample[2];
    small_sample[0] = create_array_list_of_string(i1, 10);
    small_sample[1] = create_array_list_of_string(i2, 20);
    Stratified_k_fold_cross_validation_ptr cross_validation = create_stratified_k_fold_cross_validation(small_sample, 2, 5, 1);
    Array_list_ptr test_sample = get_test_fold_stratified(cross_validation, 0);
    if (strcmp(array_list_get(test_sample, 0), "10") != 0){
        printf("Test failed in testSmallSample10Fold\n");
    }
    if (strcmp(array_list_get(test_sample, 1), "2") != 0){
        printf("Test failed in testSmallSample10Fold\n");
    }
    if (strcmp(array_list_get(test_sample, 2), "20") != 0){
        printf("Test failed in testSmallSample10Fold\n");
    }
    if (strcmp(array_list_get(test_sample, 3), "26") != 0){
        printf("Test failed in testSmallSample10Fold\n");
    }
    if (strcmp(array_list_get(test_sample, 4), "22") != 0){
        printf("Test failed in testSmallSample10Fold\n");
    }
    if (strcmp(array_list_get(test_sample, 5), "11") != 0){
        printf("Test failed in testSmallSample10Fold\n");
    }
    free_array_list(small_sample[0], NULL);
    free_array_list(small_sample[1], NULL);
    free_stratified_k_fold_cross_validation(cross_validation);
}

int main(){
    testSmallSample10Fold();
    testSmallSample5Fold();
}