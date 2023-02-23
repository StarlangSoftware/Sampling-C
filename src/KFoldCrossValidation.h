//
// Created by Olcay Taner YILDIZ on 7.02.2023.
//

#ifndef SAMPLING_KFOLDCROSSVALIDATION_H
#define SAMPLING_KFOLDCROSSVALIDATION_H

#include <ArrayList.h>

struct k_fold_cross_validation {
    int K;
    int N;
    Array_list_ptr instance_list;
};

typedef struct k_fold_cross_validation K_fold_cross_validation;
typedef K_fold_cross_validation *K_fold_cross_validation_ptr;

K_fold_cross_validation_ptr create_k_fold_cross_validation(Array_list_ptr instance_list, int K, int seed);

void free_k_fold_cross_validation(K_fold_cross_validation_ptr k_fold_cross_validation);

Array_list_ptr get_train_fold_k_fold(K_fold_cross_validation_ptr k_fold_cross_validation, int k);

Array_list_ptr get_test_fold_k_fold(K_fold_cross_validation_ptr k_fold_cross_validation, int k);

#endif //SAMPLING_KFOLDCROSSVALIDATION_H
