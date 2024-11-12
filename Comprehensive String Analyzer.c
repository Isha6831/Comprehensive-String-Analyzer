#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
// Function prototypes
int count_characters(char *str);
int count_words(char *str);
int count_spaces(char *str);
int count_vowels(char *str);
int count_consonants(char *str);
int count_digits(char *str);
void to_uppercase(char *str);
void to_lowercase(char *str);
void longest_word(char *str);
void shortest_word(char *str);
int is_palindrome(char *str, int start, int end);
void reverse_string(char *str);
void sort_string(char *str);
void remove_digits(char *str);
void remove_alphabets(char *str);
void execute(char *str);

int main() {
    char str[200];  // Array to store the input string

    // Input string from the user
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);  // Read a line of input

    // Remove newline character if it exists
    char *newline = strchr(str, '\n');
    if (newline) {
        *newline = '\0';  // Replace newline with null character
    }

    // Call the execute function to perform operations
    execute(str);

    return 0;
}

void execute(char *str) {
    
    char str2[200]; // Array to store a copy of the input string for modification
    char str3[200]; // Array to store another copy for modifications
    
    // Copy the original string to str2 and str3
    strcpy(str2, str);
    strcpy(str3, str);
    
    // Display the required information
    printf("\nTotal number of characters: %d\n", count_characters(str));
    printf("Total number of words: %d\n", count_words(str));
    printf("Total number of spaces: %d\n", count_spaces(str));
    printf("Total number of vowels: %d\n", count_vowels(str));
    printf("Total number of consonants: %d\n", count_consonants(str));
    printf("Total number of digits: %d\n", count_digits(str));
    sleep(2);
    
    // Convert to uppercase and lowercase
    to_uppercase(str);
    printf("\nUppercase string: %s\n", str);
    sleep(0.5);
    to_lowercase(str);
    printf("Lowercase string: %s\n", str);
    
    sleep(1);
    
    // Display longest and shortest words
    longest_word(str);
    sleep(0.5);
    shortest_word(str);
    sleep(0.5);
    
    // Palindrome check and reverse
    printf("String is palindrome? %s\n", is_palindrome(str, 0, count_characters(str) - 1) ? "YES" : "NO");
    sleep(1);
    reverse_string(str);
    sleep(0.5);
    
    // Sort the string and display
    sort_string(str);

    sleep(1);
    // Remove digits and alphabetic characters
    remove_digits(str2);
    sleep(0.5);
    remove_alphabets(str3);
}

// Function definitions

// Function to count the total number of characters
int count_characters(char *str) {
    if (*str == '\0') {
        return 0;
    }
    return 1 + count_characters(str + 1);
}

// Function to count the total number of words
int count_words(char *str) {
    if (*str == '\0') {
        return 0;
    }

    if (isspace(*str)) {
        return count_words(str + 1);
    }

    // Skip until next space or end of string
    while (*str != '\0' && !isspace(*str)) {
        str++;
    }

    return 1 + count_words(str);
}

// Function to count spaces
int count_spaces(char *str) {
    if (*str == '\0') {
        return 0;
    }

    if (isspace(*str)) {
        return 1 + count_spaces(str + 1);
    }

    return count_spaces(str + 1);
}

// Function to count vowels
int count_vowels(char *str) {
    if (*str == '\0') {
        return 0;
    }

    char ch = tolower(*str);  // Convert character to lowercase for easy comparison
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
        return 1 + count_vowels(str + 1);
    }

    return count_vowels(str + 1);
}

// Function to count consonants
int count_consonants(char *str) {
    if (*str == '\0') {
        return 0;
    }

    char ch = tolower(*str);
    if (isalpha(ch) && ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u') {
        return 1 + count_consonants(str + 1);
    }

    return count_consonants(str + 1);
}

// Function to count digits
int count_digits(char *str) {
    if (*str == '\0') {
        return 0;
    }

    if (isdigit(*str)) {  // Check if the character is a digit
        return 1 + count_digits(str + 1);
    }

    return count_digits(str + 1);
}

// Function to convert the string to uppercase
void to_uppercase(char *str) {
    while (*str) {
        *str = toupper(*str);
        str++;
    }
}

// Function to convert the string to lowercase
void to_lowercase(char *str) {
    while (*str) {
        *str = tolower(*str);
        str++;
    }
}

// Function to find the longest word in the string
void longest_word(char *str) {
    int max_len = 0, len = 0;
    char *word_start = NULL, *longest = NULL;

    while (*str) {
        if (isspace(*str) || *str == '\0') {
            if (len > max_len) {
                max_len = len;
                longest = word_start;
            }
            len = 0;
        } else {
            if (len == 0) {
                word_start = str;
            }
            len++;
        }
        str++;
    }

    if (longest != NULL) {
        printf("\nLongest word: ");
        while (max_len-- > 0) {
            printf("%c", *longest++);
        }
        printf("\n");
    }
}

// Function to find the shortest word in the string
void shortest_word(char *str) {
    int min_len = 1000, len = 0;
    char *word_start = NULL, *shortest = NULL;

    while (*str) {
        if (isspace(*str) || *str == '\0') {
            if (len < min_len && len > 0) {
                min_len = len;
                shortest = word_start;
            }
            len = 0;
        } else {
            if (len == 0) {
                word_start = str;
            }
            len++;
        }
        str++;
    }

    if (shortest != NULL) {
        printf("Shortest word: ");
        while (min_len-- > 0) {
            printf("%c", *shortest++);
        }
        printf("\n");
    }
}

// Function to check if the string is palindrome
int is_palindrome(char *str, int start, int end) {
    if (start >= end) return 1;
    if (str[start] != str[end]) return 0;
    return is_palindrome(str, start + 1, end - 1);
}

// Function to reverse the string
void reverse_string(char *str) {
    int length = count_characters(str);  // Use the existing count function to get the string length
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
    printf("\nReversed string: %s\n", str);
}

// Function to sort the string in ascending order (Bubble Sort)
void sort_string(char *str) {
    int n = count_characters(str);
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (str[j] > str[j+1]) {
                char temp = str[j];
                str[j] = str[j+1];
                str[j+1] = temp;
            }
        }
    }
    printf("Bubble-sorted string: %s\n", str);
}

// Function to display string without numeric characters
void remove_digits(char *str) {
    char *src = str, *dst = str;
    while (*src) {
        if (!isdigit(*src)) {
            *dst++ = *src;
        }
        src++;
    }
    *dst = '\0';  // Null-terminate the string
    printf("\nString without digits: %s\n", str);
}

// Function to display string without alphabetic characters
void remove_alphabets(char *str) {
    char *src = str, *dst = str;
    while (*src) {
        if (!isalpha(*src)) {
            *dst++ = *src;
        }
        src++;
    }
    *dst = '\0';  // Null-terminate the string
    printf("String without alphabets: %s\n", str);
}

