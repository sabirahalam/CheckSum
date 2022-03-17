#include <iostream>
#include <climits>


//the 5 functions
unsigned int add_checksum(unsigned int n);

void add_checksum( unsigned int array[], std::size_t capacity );

bool verify_checksum( unsigned int n );

unsigned int remove_checksum( unsigned int n);

void remove_checksum( unsigned int array[], std::size_t capacity );

#ifndef MARMOSET_TESTING
int main();
#endif

#ifndef MARMOSET_TESTING
int main() {

    // Function 1
    unsigned int n{ 12345678 };
    unsigned int check = add_checksum(n);
    std::cout << "The value " << n << " with checksum added is " << check << "." << std::endl;


    // Function 2
    const std::size_t capacity{ 3 };
    unsigned int array[capacity]{ 20201122, 20209913, 20224012 };

    add_checksum(array, capacity);

    std::cout << "Series with checksums added: ";
    for (std::size_t i {0}; i < capacity; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;


    // Function 3
    if (verify_checksum(check)) {
        std::cout << "The checksum is valid." << std::endl;
    }

    else {
        std::cout << "The checksum is invalid." << std::endl;
    }


    // Function 4
    unsigned int verify = remove_checksum(check);
    std::cout << "The value " << check << " without the checksum added is " << verify << "." << std::endl;


    // Function 5
    remove_checksum(array, capacity);
    std::cout << "Series without checksums added: ";
    for (std::size_t i {0}; i < capacity; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;


    return 0;
}
#endif


unsigned int add_checksum(unsigned int n) {

    // If n is is the correct value within the range, then function will calculate the checksum
    if (n >= 0 && n <= 99999999) {

        // Creates an array of 9 elements, the 9th being the checksum to be calculated
        int array[9]; 
        int new_array[9];

        // Puts the 8 digit integer into an array
        for (int i = 7; i >= 0; i--) {
            array[i] = n % 10;
            new_array[i] = array[i];
            n /= 10;
        }
        // Starting from the rightmost digit to the leftmost, multiplying every other digit by 2
        for (int j = 7; j > 0; j -= 2) {
            new_array[j] = new_array[j] * 2;
            
            // If result of multiplication is greater than 9, summing the individual digits of the doubled number and replacing it with the sum
            int double_sum = 0, m;
            if (new_array[j] > 9) {
                m = new_array[j] % 10;
                double_sum = double_sum + m;
                new_array[j] /= 10;
                new_array[j] += double_sum;
            }
        }

        // Sum of all the digits excluding the checksum digit 
        int sum = 0;
        for (int k = 0; k < 8; k++) {
            sum += new_array[k];
        }

        // Multiplying the result from Step 2 by 9
        sum = sum * 9;
     
        // Computing the checksum digit d
        int checksum = sum % 10;

        // Assigning checksum value to the 9th digit in the array
        array[8] = checksum;

        // Printing out every element in the array into one integer
        for (int m = 0; m < 9; m++) {
            n = n * 10;
            n = n + array[m];
        }
     }

    // If n is greater than an 8 - digit number, returning the maximum unsigned integer value to signal an error
    else if (n > 99999999) {

        return UINT_MAX;
       
    }
    return n;
} 


void add_checksum(unsigned int array[], std::size_t capacity) {

    // Takes each indidual element in the array and puts it into the add_checksum function to compute the checksum
    for (int i = 0; i < capacity; i++){
        array[i] = add_checksum(array[i]);
    }   
}


bool verify_checksum(unsigned int n) {

    if (n >= 0 && n <= 999999999) {

        // Creates an array of 9 elements, the 9th being the checksum to be calculated
        int array[9];
        int new_array[9];

        // Puts the 8 digit integer into an array
        for (int i = 8; i >= 0; i--) {
            array[i] = n % 10;
            new_array[i] = array[i];
            n /= 10;
        }

        // Starting from the rightmost digit to the leftmost, multiplying every other digit by 2
        for (int j = 7; j > 0; j -= 2) {
            new_array[j] = new_array[j] * 2;

            // If result of multiplication is greater than 9, summing the individual digits of the doubled number and replacing it with the sum
            int double_sum = 0, m;
            if (new_array[j] > 9) {
                m = new_array[j] % 10;
                double_sum = double_sum + m;
                new_array[j] /= 10;
                new_array[j] += double_sum;
            }
        }

        // Sum of all the digits excluding the checksum digit 
        int sum = 0;
        for (int k = 0; k < 8; k++) {
            sum += new_array[k];
        }

        // Multiplying the result from Step 2 by 9
        sum = sum * 9;
        

        // Computing the checksum digit d
        int checksum = sum % 10;

        if (checksum == array[8]) {

            return true;
        }
    }

    else {
        return false;
    }
    return 0;
}



unsigned int remove_checksum(unsigned int n) {

    if (verify_checksum(n) == false) {

        return UINT_MAX;
    }
    
    else {

        int array[9];
        // Puts the 9 digit integer into an array
        for (int i = 8; i >= 0; i--) {
            array[i] = n % 10;
            n /= 10;
        }

        // Printing out every element in the array into one integer
        for (int m = 0; m < 8; m++) {
            n = n * 10;
            n = n + array[m];
        }

    }

    return n;
}


void remove_checksum(unsigned int array[], std::size_t capacity) {
    
 // Takes each indidual element in the array and puts it into the remove_checksum function to remove the checksum digit
    for (int i = 0; i < capacity; i++){
        array[i] = remove_checksum(array[i]);
    }  

}
