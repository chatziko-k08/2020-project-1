///////////////////////////////////////////////////////////////////
//
// ADT Priority Queue
//
// Abstract ουρά προτεραιότητας. Σε κάθε remove επιστρέφεται το
// μεγαλύτερο στοιχείο (με βάση τη συνάρτηση compare).
//
///////////////////////////////////////////////////////////////////

#pragma once // #include το πολύ μία φορά

#include "common_types.h"


// Μία ουρά προτεραιότητας αναπαριστάται από τον τύπο PriorityQueue

typedef struct priority_queue* PriorityQueue;


// Δημιουργεί και επιστρέφει μια νέα ουρά προτεραιότητας, της οποίας τα
// στοιχεία συγκρίνονται με βάση τη συνάρτηση compare.
// Αν destroy_value != NULL, τότε καλείται destroy_value(value) κάθε φορά που αφαιρείται ένα στοιχείο.

PriorityQueue priority_queue_create(CompareFunc compare, DestroyFunc destroy_value);

// Επιστρέψει τον αριθμό στοιχείων που περιέχει η ουρά pqueue

int priority_queue_size(PriorityQueue pqueue);

// Επιστρέφει το μεγαλύτερο στοιχείο της ουράς (μη ορισμένο αποτέλεσμα αν η ουρά είναι κενή)

Pointer priority_queue_top(PriorityQueue pqueue);

// Προσθέτει την τιμή value στην ουρά pqueue.

void priority_queue_insert(PriorityQueue pqueue, Pointer value);

// Αφαιρεί και επιστρέφει  την μεγαλύτερη τιμή της ουράς (μη ορισμένο αποτέλεσμα αν η ουρά είναι κενή)

Pointer priority_queue_remove(PriorityQueue pqueue);

// Ελευθερώνει όλη τη μνήμη που δεσμεύει η ουρά pqueue.
// Οποιαδήποτε λειτουργία πάνω στη ουρά μετά το destroy είναι μη ορισμένη.

void priority_queue_destroy(PriorityQueue pqueue);
