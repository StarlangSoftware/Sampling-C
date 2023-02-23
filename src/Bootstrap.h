//
// Created by Olcay Taner YILDIZ on 7.02.2023.
//

#ifndef SAMPLING_BOOTSTRAP_H
#define SAMPLING_BOOTSTRAP_H

#include <ArrayList.h>

struct bootstrap {
    Array_list_ptr instance_list;
};

typedef struct bootstrap Bootstrap;
typedef Bootstrap *Bootstrap_ptr;

Bootstrap_ptr create_bootstrap(Array_list_ptr instance_list, int seed);

void free_bootstrap(Bootstrap_ptr bootstrap, void free_method(void *));

Array_list_ptr get_sample(Bootstrap_ptr bootstrap);

#endif //SAMPLING_BOOTSTRAP_H
