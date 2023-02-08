//
// Created by Olcay Taner YILDIZ on 7.02.2023.
//

#ifndef SAMPLING_STRATIFIEDKFOLDCROSSVALIDATION_H
#define SAMPLING_STRATIFIEDKFOLDCROSSVALIDATION_H

#include <ArrayList.h>

struct stratified_k_fold_cross_validation{
    int* N;
    int K;
    int number_of_classes;
    Array_list_ptr* instance_lists;
};

typedef struct stratified_k_fold_cross_validation Stratified_k_fold_cross_validation;
typedef Stratified_k_fold_cross_validation* Stratified_k_fold_cross_validation_ptr;

Stratified_k_fold_cross_validation_ptr create_stratified_k_fold_cross_validation(Array_list_ptr* instance_lists,
                                                                                 int number_of_classes,
                                                                                 int K,
                                                                                 int seed);
void free_stratified_k_fold_cross_validation(Stratified_k_fold_cross_validation_ptr stratified_k_fold_cross_validation);
Array_list_ptr get_train_fold_stratified(Stratified_k_fold_cross_validation_ptr stratified_k_fold_cross_validation, int k);
Array_list_ptr get_test_fold_stratified(Stratified_k_fold_cross_validation_ptr stratified_k_fold_cross_validation, int k);

#endif //SAMPLING_STRATIFIEDKFOLDCROSSVALIDATION_H
