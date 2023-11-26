//
// Created by Olcay Taner YILDIZ on 7.02.2023.
//

#include <stdlib.h>
#include "StratifiedKFoldCrossValidation.h"
#include "Memory/Memory.h"

/**
 * A constructor of StratifiedKFoldCrossValidation class which takes as set of class samples as an array of array of instances, a K (K in K-fold cross-validation) and a seed number,
 * then shuffles each class sample using the seed number.
 *
 * @param instanceLists Original class samples. Each element of the this array is a sample only from one class.
 * @param K K in K-fold cross-validation
 * @param seed Random number to create K-fold sample(s)
 */
Stratified_k_fold_cross_validation_ptr
create_stratified_k_fold_cross_validation(Array_list_ptr *instance_lists, int number_of_classes, int K, int seed) {
    Stratified_k_fold_cross_validation_ptr result = malloc_(sizeof(Stratified_k_fold_cross_validation), "create_stratified_k_fold_cross_validation_1");
    result->instance_lists = instance_lists;
    result->number_of_classes = number_of_classes;
    result->K = K;
    result->N = malloc_(number_of_classes * sizeof(int), "create_stratified_k_fold_cross_validation_2");
    for (int i = 0; i < number_of_classes; i++) {
        srand(seed);
        array_list_shuffle(result->instance_lists[i], seed);
        result->N[i] = result->instance_lists[i]->size;
    }
    return result;
}

void
free_stratified_k_fold_cross_validation(Stratified_k_fold_cross_validation_ptr stratified_k_fold_cross_validation) {
    free_(stratified_k_fold_cross_validation->N);
    free_(stratified_k_fold_cross_validation);
}

/**
 * getTrainFold returns the k'th train fold in K-fold stratified cross-validation.
 *
 * @param k index for the k'th train fold of the K-fold stratified cross-validation
 * @return Produced training sample
 */
Array_list_ptr
get_train_fold_stratified(const Stratified_k_fold_cross_validation* stratified_k_fold_cross_validation, int k) {
    Array_list_ptr train_fold = create_array_list();
    for (int i = 0; i < stratified_k_fold_cross_validation->number_of_classes; i++) {
        for (int j = 0;
             j < (k * stratified_k_fold_cross_validation->N[i]) / stratified_k_fold_cross_validation->K; j++) {
            array_list_add(train_fold, array_list_get(stratified_k_fold_cross_validation->instance_lists[i], j));
        }
        for (unsigned long j =
                ((k + 1) * stratified_k_fold_cross_validation->N[i]) / stratified_k_fold_cross_validation->K;
             j < stratified_k_fold_cross_validation->N[i]; j++) {
            array_list_add(train_fold, array_list_get(stratified_k_fold_cross_validation->instance_lists[i], j));
        }
    }
    return train_fold;
}

/**
 * getTestFold returns the k'th test fold in K-fold stratified cross-validation.
 *
 * @param k index for the k'th test fold of the K-fold stratified cross-validation
 * @return Produced testing sample
 */
Array_list_ptr
get_test_fold_stratified(const Stratified_k_fold_cross_validation* stratified_k_fold_cross_validation, int k) {
    Array_list_ptr test_fold = create_array_list();
    for (int i = 0; i < stratified_k_fold_cross_validation->number_of_classes; i++) {
        for (int j = (k * stratified_k_fold_cross_validation->N[i]) / stratified_k_fold_cross_validation->K;
             j < ((k + 1) * stratified_k_fold_cross_validation->N[i]) / stratified_k_fold_cross_validation->K; j++) {
            array_list_add(test_fold, array_list_get(stratified_k_fold_cross_validation->instance_lists[i], j));
        }
    }
    return test_fold;
}
