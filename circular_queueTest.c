#include "testUtils.h"
#include "circular_queue.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int areEqual(Queue* src,Queue* expected){
	int res = (src->capacity == expected->capacity)
	        && (src->size == expected->size)
	        && (src->front == expected->front)
	        && (src->rear == expected->rear);
	        if(!res)
	                return res;
	        return 0 == memcmp(src->elements, expected->elements, src->size*src->capacity);                        
}
// ----------------------  CREATE --------------------------------
void test_create_queue_for_integers() {
    int expectedArr[2]={0,0};
    Queue expected = {2,sizeof(int),0,-1,expectedArr};
    Queue* src = create(2,sizeof(int));
    ASSERT(areEqual(src, &expected));
}
void test_create_queue_for_floats() {
    float expectedArr[2]={0.0,0.0};
    Queue expected = {2,sizeof(float),0,-1,expectedArr};
    Queue* src = create(2,sizeof(float));
    ASSERT(areEqual(src, &expected));
}
void test_create_queue_for_chars() {
    char expectedArr[2]={0,0};
    Queue expected = {2,sizeof(char),0,-1,expectedArr};
    Queue* src = create(2,sizeof(char));
    ASSERT(areEqual(src, &expected));
}
void test_create_queue_for_String() {
    String expectedArr[2]={0,0};
    Queue expected = {2,sizeof(String),0,-1,expectedArr};
    Queue* src = create(2,sizeof(String));
    ASSERT(areEqual(src, &expected));
}
void test_create_queue_for_double() {
    double expectedArr[2]={0.0,0.0};
    Queue expected = {2,sizeof(double),0,-1,expectedArr};
    Queue* src = create(2,sizeof(double));
    ASSERT(areEqual(src, &expected));
}

// ----------------------- EQUEUE ----------------------------
void test_for_enqueing_int_element_in_queue(){
    Queue* actual = create(2,sizeof(int));
    int value = 1;
    bool res =enqueue(actual,&value);
    int* data = (int*)actual->elements;
    ASSERT(data[0] == 1);
    free(actual);
}
void test_for_enqueing_float_element_in_queue(){
    Queue* actual = create(2,sizeof(float));
    float value = 89.0;
    float* data;
    int res = enqueue(actual,&value);
    data = (float*)actual->elements;
    ASSERT(data[0] == 89.0);
    free(actual);
}
void test_for_enqueing_double_element_in_queue(){
    Queue* actual = create(2,sizeof(double));
    double value = 89.0;
    double* data;
    int res = enqueue(actual,&value);
    data = (double*)actual->elements;
    ASSERT(data[0] == 89.0);
    free(actual);
}
void test_for_enqueing_string_element_in_queue(){
    Queue* actual = create(2,sizeof(String));
    String value = "shital";
    String* data;
    int res = enqueue(actual,&value);
    data = (String*)actual->elements;
    ASSERT(0 == strcmp(data[0], "shital"));
    free(actual);
}
void test_for_enqueing_char_element_in_queue(){
    Queue* actual = create(2,sizeof(char));
    char value = 'A';
    char* data;
    int res = enqueue(actual,&value);
    data = (char*)actual->elements;
    ASSERT(data[0] == 'A');
    free(actual);
}
void test_for_non_enqueueing_float_element_into_queue(){
    Queue* actual = create(sizeof(float),4);
    bool result;
    float value = 5;
    actual->rear = 3;
    result = enqueue(actual,&value);
    ASSERT(result == 1);
    free(actual);
}
// ---------------------- DEQUEUE ---------------------------------
void test_for_dequeueing_int_element_from_queue(){
    Queue* actual = create(sizeof(int),4);
    void* result;
    int value = 3;
    int value1 = 4;
    int value2 = 5;
    int value3 = 6;
    int* data;
    enqueue(actual, &value);
    enqueue(actual, &value1);
    enqueue(actual, &value2);
    enqueue(actual, &value3);
    result = (int*)dequeue(actual);
    data = (int*)actual->elements;
    ASSERT(*(int*)result == 3);
    ASSERT((actual->front) == 1);
    ASSERT(actual->rear == 3);
    free(actual);
}
void test_for_dequeueing_float_element_from_queue(){
    Queue* actual = create(sizeof(float),3);
    float value = 3;
    float value1 = 4;
    float value2 = 5;
    void* result;
    float* data;
    enqueue(actual, &value);
    enqueue(actual, &value1);
    enqueue(actual, &value2);
    result = (float*)dequeue(actual);
    result = (float*)dequeue(actual);
    data = (float*)actual->elements;
    ASSERT(actual->front == 2);
    ASSERT(*(float*)result == 3);
    ASSERT(actual->rear == 2);
    free(actual);
}
void test_for_non_dequeueing_float_element_from_queue(){
    Queue* actual = create(sizeof(float),5);
    void* result;
    result = dequeue(actual);
    ASSERT(result == NULL);
    free(actual);
}
void test_for_enqueueing_new_element_at_the_0_location_for_integer(){
    Queue* actual = create(sizeof(float),4);
    void* result;
    int* data;
    int value = 5;
    int value1 = 6;
    int value2 = 7;
    int value3 = 8;
    int value4 = 9;
    enqueue(actual,&value);
    enqueue(actual,&value1);
    enqueue(actual,&value2);
    enqueue(actual,&value3);
    result = dequeue(actual);
    enqueue(actual, &value4);
    data = (int*)actual->elements;
    ASSERT(data[0] == 9);        
    ASSERT(*(int*)result = 5);
    
}
void test_fail(){
	ASSERT(0);
}
