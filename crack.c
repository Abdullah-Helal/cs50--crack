#include <cs50.h>
#include <stdio.h>
#include <crypt.h>
#include <string.h>
#include <ctype.h>

// we'll add this last REMEMBER
bool crack(string user_input, string salt, string guess);

// like every other cs50 program we need to have a main method
int main(int argc, string argv[])
{
    // this first if statement checks for 2 different arguements in the command line, if there is not two then it'll spit out an error
    if (argc != 2)
    {
        printf("Usage: ./crack hash\n");
        return 1;
    }
    
    // in the pseudocode, we talked about a way to indicate that we've cracked the password, and this is it 
    // it allows us to catch the case where we couldn't find the password
    bool laughOutLoud = true;
    string user_input = argv[1];
    
    char salt[3];
    
    for (int i = 0; i < 2; i++)
    {
        salt[i] = user_input[i];
    }
    salt[2] = '\0';
    
    string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int alphabet_length = 52;
    
    // Initialize a 1 word string in char array form
    char guess_1[2];
    guess_1[1] = '\0';
    
    // Submit guesses for 1 letter passwords
    // we use the first_
    for (int first_letter_pointer = 0; first_letter_pointer < alphabet_length; first_letter_pointer++)
    {
        guess_1[0] = alphabet[first_letter_pointer];
        
        if (crack(user_input, salt, guess_1))
        {
            printf("Password is: %s\n", guess_1);
            laughOutLoud = false;
            return 0;
        }
    }
    
    // Initialize 2 letter char array, 3rd array spot is for null char
    char guess_2[3];
    guess_2[2] = '\0';
    
    // Submit 2 letter guesses
    for (int first_letter_pointer = 0; first_letter_pointer < alphabet_length; first_letter_pointer++)
    {
        // Set index 1 to a letter, updates after going through all permutations
        guess_2[0] = alphabet[first_letter_pointer];
        
        // Set index 2 to a letter, submit, and iterate through if failing
        for (int second_letter_pointer = 0; second_letter_pointer < alphabet_length; second_letter_pointer++)
        {
            guess_2[1] = alphabet[second_letter_pointer];
            
            if (crack(user_input, salt, guess_2))
            {
                laughOutLoud = false;
                printf("Password is: %s \n", guess_2);
                return 0;
            }
        }
    }
    
    // Initialize 3 letter string char array
    char guess_3[4];
    guess_3[3] = '\0';
    
    for (int first_letter_pointer = 0; first_letter_pointer < alphabet_length; first_letter_pointer++)
    {
        guess_3[0] = alphabet[first_letter_pointer];
        
        for (int second_letter_pointer = 0; second_letter_pointer < alphabet_length; second_letter_pointer++)
        {
            guess_3[1] = alphabet[second_letter_pointer];
            
            for (int third_letter_pointer = 0; third_letter_pointer < alphabet_length; third_letter_pointer++)
            {
                guess_3[2] = alphabet[third_letter_pointer];
                
                if (crack(user_input, salt, guess_3))
                {
                    printf("Password is: %s\n", guess_3);
                    laughOutLoud = false;
                    return 0;
                }
            }
        }
    }
    
    // Initialize character array for a string of 5/ char array of 4
    char guess_4[5];
    guess_4[4] = '\0';
    
    for (int first_letter_pointer = 0; first_letter_pointer < alphabet_length; first_letter_pointer++)
    {
        guess_4[0] = alphabet[first_letter_pointer];
        
        for (int second_letter_pointer = 0; second_letter_pointer < alphabet_length; second_letter_pointer++)
        {
            guess_4[1] = alphabet[second_letter_pointer];
            
            for (int third_letter_pointer = 0; third_letter_pointer < alphabet_length; third_letter_pointer++)
            {
                guess_4[2] = alphabet[third_letter_pointer];
                
                for (int fourth_letter_pointer = 0; fourth_letter_pointer < alphabet_length; fourth_letter_pointer++)
                {
                    guess_4[3] = alphabet[fourth_letter_pointer];
                    
                    if (crack(user_input, salt, guess_4))
                    {
                        printf("Password is: %s\n", guess_4);
                        laughOutLoud = false;
                        return 0;
                    }
                }
            }
        }
    }
    
    // Initialize an string of 5 / a char array of 6 
    char guess_5[6];
    guess_5[5] = '\0';
    
    // Submit all permutations of 5 letters
    for (int first_letter_pointer = 0; first_letter_pointer < alphabet_length; first_letter_pointer++)
    {
        guess_5[0] = alphabet[first_letter_pointer];
        
        for (int second_letter_pointer = 0; second_letter_pointer < alphabet_length; second_letter_pointer++)
        {
            guess_5[1] = alphabet[second_letter_pointer];
            
            for (int third_letter_pointer = 0; third_letter_pointer < alphabet_length; third_letter_pointer++)
            {
                guess_5[2] = alphabet[third_letter_pointer];
                
                for (int fourth_letter_pointer = 0; fourth_letter_pointer < alphabet_length; fourth_letter_pointer++)
                {
                    guess_5[3] = alphabet[fourth_letter_pointer];
                    
                    for (int fifth_letter_pointer = 0; fifth_letter_pointer < alphabet_length; fifth_letter_pointer++)
                    {
                        guess_5[4] = alphabet[fifth_letter_pointer];
                        
                        if (crack(user_input, salt, guess_5))
                        {
                            printf("Password is: %s\n", guess_5);
                            laughOutLoud = false;
                            return 0;
                        }
                    }
                }
            }
        }
    }
    
    if (laughOutLoud)
    {
        printf("LOL LOSER\n");
        return 1;
    }
    
}



bool crack(string user_input, string salt, string guess)
{
    string encrypted_guess = crypt(guess, salt);
    if (strcmp(encrypted_guess, user_input) == 0)
    {
        return true;
    }
    return false;
}
