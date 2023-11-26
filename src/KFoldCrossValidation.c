//
// Created by Olcay Taner YILDIZ on 7.02.2023.
//

#include <stdlib.h>
#include <Memory/Memory.h>
#include "KFoldCrossValidation.h"

/**
 * A constructor of KFoldCrossValidation class which takes a sample as an array of instances, a K (K in K-fold cross-validation) and a seed number,
 * then shuffles the original sample using this seed as random number.
 *
 * @param instanceList Original sample
 * @param K K in K-fold cross-validation
 * @param seed Random number to create K-fold sample(s)
 */
K_fold_cross_validation_ptr create_k_fold_cross_validation(Array_list_ptr instance_list, int K, int seed) {
    K_fold_cross_validation_ptr result = malloc_(sizeof(K_fold_cross_validation), "create_k_fold_cross_validation");
    result->K = K;
    result->N = instance_list->size;
    result->instance_list = instance_list;
    array_list_shuffle(result->instance_list, seed);
    return result;
}

void free_k_fold_cross_validation(K_fold_cross_validation_ptr k_fold_cross_validation) {
    free_(k_fold_cross_validation);
}

/**
 * getTrainFold returns the k'th train fold in K-fold cross-validation.
 *
 * @param k index for the k'th train fold of the K-fold cross-validation
 * @return Produced training sample
 */
Array_list_ptr get_train_fold_k_fold(const K_fold_cross_validation* k_fold_cross_validation, int k) {
    Array_list_ptr train_fold = create_array_list();
    for (int i = 0; i < (k * k_fold_cross_validation->N) / k_fold_cross_validation->K; i++) {
        array_list_add(train_fold, array_list_get(k_fold_cross_validation->instance_list, i));
    }
    for (int i = ((k + 1) * k_fold_cross_validation->N) / k_fold_cross_validation->K;
         i < k_fold_cross_validation->N; i++) {
        array_list_add(train_fold, array_list_get(k_fold_cross_validation->instance_list, i));
    }
    return train_fold;
}

/**
 * getTestFold returns the k'th test fold in K-fold cross-validation.
 *
 * @param k index for the k'th test fold of the K-fold cross-validation
 * @return Produced testing sample
 */
Array_list_ptr get_test_fold_k_fold(const K_fold_cross_validation* k_fold_cross_validation, int k) {
    Array_list_ptr test_fold = create_array_list();
    for (int i = (k * k_fold_cross_validation->N) / k_fold_cross_validation->K;
         i < ((k + 1) * k_fold_cross_validation->N) / k_fold_cross_validation->K; i++) {
        array_list_add(test_fold, array_list_get(k_fold_cross_validation->instance_list, i));
    }
    return test_fold;
}
