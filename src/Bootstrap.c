//
// Created by Olcay Taner YILDIZ on 7.02.2023.
//

#include <stdlib.h>
#include <Memory/Memory.h>
#include "Bootstrap.h"

/**
 * A constructor of Bootstrap class which takes a sample an array of instances and a seed number, then creates a bootstrap
 * sample using this seed as random number.
 *
 * @param instanceList  Original sample
 * @param seed Random number to create boostrap sample
 */
Bootstrap_ptr create_bootstrap(Array_list_ptr instance_list, int seed) {
    Bootstrap_ptr result = malloc_(sizeof(Bootstrap), "create_bootstrap");
    result->instance_list = create_array_list();
    srand(seed);
    int N = instance_list->size;
    for (int i = 0; i < N; i++) {
        array_list_add(result->instance_list, array_list_get(instance_list, random() % N));
    }
    return result;
}

/**
 * Destructor for the Bootstrap class. Frees memory allocated for the instance_list array list with possible option of
 * freeing memory allocated for the insider objects.
 * @param bootstrap Current bootstrap
 * @param free_method Destructor method for the contents of the elements of the instance list
 */
void free_bootstrap(Bootstrap_ptr bootstrap, void free_method(void *)) {
    free_array_list(bootstrap->instance_list, free_method);
    free_(bootstrap);
}

/**
 * getSample returns the produced bootstrap sample.
 *
 * @return Produced bootstrap sample
 */
Array_list_ptr get_sample(Bootstrap_ptr bootstrap) {
    return bootstrap->instance_list;
}
