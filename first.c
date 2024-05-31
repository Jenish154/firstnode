#include <stdio.h>
#include <stdlib.h>

void print_array(int *arr, int size) {
    printf("The elements of the arrays are: ");
    for (int i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void reverse_print_array(int *arr, int size) {
    printf("The elements of the array in reversed order are: ");
    for (int i=size-1; i>=0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int sum_of_array(int *arr, int size) {
    int result = 0;
    
    for (int i=0; i<size; i++) {
        result += arr[i];
    }
    return result;
}

void take_input(int *arr, int size) {
    int inp;
    for (int i=0; i<size; i++) {
        printf("Enter the %d element: ", i+1);
        scanf("%d", &inp);
        arr[i] = inp;
    }
}

void copy_array(int *arr1, int *arr2, int size) {
    for (int i=0; i<size; i++) {
        arr2[i] = arr1[i];
    }
}

int ele_in_array(int ele, int *arr, int size) {
    for (int i=0; i<size; i++) {
        if (arr[i] == ele) {
            return 1;
        }
    }
    return 0;
}

int count_duplicates(int *arr, int size) {
    int *dummy = (int *)malloc(sizeof(int) * size);
    int ind = 0;
    int count = 0;
    for (int i=0; i<size; i++) {
        if (ele_in_array(arr[i], dummy, ind)) {
            count++;
        } else {
            dummy[ind] = arr[i];
            ind++;
        }
    }
    printf("The unique elements of the array are: \n");
    print_array(dummy, ind);
    free(dummy);
    return count;
}

void input_2d(int **arr, int x_size, int y_size) {
    int ind;
    
    for (int i=0; i<x_size; i++) {
        for (int j=0; j<y_size; j++) {
            printf("enter the element in (%d, %d): ", i, j);
            scanf("%d", &ind);
            arr[i][j] = ind;
        }
    }
}

void print_2darray(int **arr, int x_size, int y_size) {
    for (int i=0; i<x_size; i++) {
        for (int j=0; j<y_size; j++) {
            printf("The element in (%d, %d): %d\n", i, j, arr[i][j]);


        }
    }
}

int **allocate_2darray(int x_size, int y_size) {
    int **arr = (int **)malloc(sizeof(int *) * x_size);
    int *dummy;
    for (int i=0; i<y_size; i++) {
        dummy = (int *)malloc(sizeof(int) * y_size);
        arr[i] = dummy;
    }
    return arr;
}

void free_2darray(int **arr, int x_size) {
    for (int i=0; i<x_size; i++) {
        free(arr[i]);
    }

    free(arr);
}

void print_matrix(int **matrix, int x_size, int y_size) {
    for (int i=0; i<x_size; i++) {
        for (int j=0; j<y_size; j++) {
            printf("%d ", matrix[i][j]);

        }
        printf("\n");
    }
}

void add_matrix(int **matrix1, int**matrix2, int **result, int x_size, int y_size) {
    for (int i=0; i<x_size; i++) {
        for (int j=0; j<y_size; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }   
}

void lower_triangle(int **matrix, int size) {
    for (int i=1; i<size; i++) {
        for (int j=0; j<i; j++) {
            matrix[i][j] = 0;
        }
    }
}

int calculate_3deter(int **matrix) {
    //   
    return matrix[0][0] * ((matrix[1][1] * matrix[2][2]) - (matrix[1][2] * matrix[2][1])) - matrix[0][1] * ((matrix[1][0] * matrix[2][2]) - (matrix[1][2] * matrix[2][0])) + matrix[0][2] * ((matrix[1][0] * matrix[2][1]) - (matrix[1][1] * matrix[2][0]));
}

int is_sparse(int **matrix, int x_size, int y_size) {
    int zeroes = 0;
    int others = 0;
    for (int i=0; i<x_size; i++) {
        for (int j=0; j<y_size; j++) {
            if (matrix[i][j] == 0) {
                zeroes++;
            }else {
                others++;
            }
        }
    }
    return zeroes > others;
}

int main() {
    /*
    int *arr = (int *)malloc(sizeof(int) * 10);
    int *dummy_arr = (int *)malloc(sizeof(int) *10);
    take_input(arr, 10);
    print_array(arr, 10);
    reverse_print_array(arr, 10);
    printf("The sum of the elements of the array is: %d.\n", sum_of_array(arr, 10));
    copy_array(arr, dummy_arr, 10);
    print_array(dummy_arr, 10);
    printf("The number of duplicates in the array is: %d.\n", count_duplicates(arr, 10));

    int **arr2d = allocate_2darray(3, 3);
    input_2d(arr2d, 3, 3);
    print_2darray(arr2d, 3, 3);

    free_2darray(arr2d, 3);


    free(arr);
    */
    /*
    //for matrix addition
    int size;
    printf("Enter the dimensions of the square matrix: ");
    scanf("%d", &size);
    int **first_2darr = allocate_2darray(size, size);
    int **second_2darr = allocate_2darray(size, size);

    printf("Enter the elements for 1st matrix: \n");
    input_2d(first_2darr, size, size);
    printf("Enter the elements for 2nd matrix: \n");
    input_2d(second_2darr, size, size);
    
    printf("First matrix is: \n");
    print_matrix(first_2darr, size, size);
    printf("Second matrix is: \n");
    print_matrix(second_2darr, size, size);

    int **result_matrix = allocate_2darray(size, size);
    add_matrix(first_2darr, second_2darr, result_matrix, size, size);
    printf("The resultant matrix after addition is: \n");
    print_matrix(result_matrix, size, size);


    free_2darray(first_2darr, size);
    free_2darray(second_2darr, size);
    free_2darray(result_matrix, size);
    */
    
    int size;
    printf("Enter the size of the square matrix: ");
    scanf("%d", &size);
    int **matrix = allocate_2darray(size, size);
    input_2d(matrix, size, size);
    printf("The array before operation is: \n");
    print_matrix(matrix, size, size);
    printf("The array after: \n");
    //lower_triangle(matrix, size);
    print_matrix(matrix, size, size);
    printf("The determinant of this matrix is: %d.\n", calculate_3deter(matrix));
    printf("The matrix is sparse: %d.\n", is_sparse(matrix, size, size));
    free_2darray(matrix, size);

    return 0;
}