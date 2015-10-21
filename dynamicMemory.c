/* Author : Srinivas Avireddy */

#include <stdio.h>
#include <stdlib.h>

#define CALLOC_ARRAY_SIZE 2
#define REALLOC_ARRAY_SIZE 4

//#pragma pack(1)
struct course {
	int id;
	char name;
};

void setCourseDetails(struct course *a, int id, char name) {
    a -> id = id;
    a -> name = name;
}

void swapId(struct course *a, struct course *b) {
    int temp;
    temp = a->id;
    a->id = b->id;
    b->id = temp;
}

void printDetails(struct course *a, int size) {
    int i;
    
    for (i = 0; i < size; i++) {
        printf("\nCourse %d \n", i);
        printf("Course id %d \n", a[i].id);
        printf("Course Name %c \n", a[i].name);
        printf("*----------*-----------*");
    }
}
int main(void) {
    
	// malloc example 
	struct course *courseOne = (struct course *) malloc(sizeof(struct course));
	printf("Size of struct course = %d \n", sizeof(struct course));
	
	//calloc example - For Array of courses
	struct course *courseArray = (struct course *) calloc(CALLOC_ARRAY_SIZE, sizeof(struct course));
	setCourseDetails(&courseArray[0], 2, 'A');
	setCourseDetails(&courseArray[1], 3, 'B');
	printDetails(courseArray, CALLOC_ARRAY_SIZE);
	
  //realloc example - Doubling array size
	courseArray = (struct course *) realloc(courseArray, REALLOC_ARRAY_SIZE * sizeof(struct course));
	
	printf("\nResults After Swapping\n");
	swapId(&courseArray[0], &courseArray[1]);
	printDetails(courseArray, CALLOC_ARRAY_SIZE);
	
	free(courseOne);
	free(courseArray);
	
	return 0;
}

