/*  Grace Provost
 *  gprovost@pdx.edu
 *  Program 2
 *  10/18/19
 *  CS 162
 *
 *  PURPOSE: This program is intended to help users create and organize common phrases they use in everyday messages with a signature. The user will enter 4 phrases and 1 signature, and then will be able to choose which phrases to place in a message in whatever order they prefer followed by their signature. They will be able to do re-create messages from the phrases as much as they like.
 *
 * _______ CODE ALGORITHM______
 *
 * 1. Initialize constants STRING_LENGTH = 131 and NUMBER_OF_PHRASES = 4
 * 2. Initialize variables two structs to hold a character array and integer array, along with their sizes
 * 3. Declare function prototypes
 *  - clearBufferString()
 *  - getResponse()
 *  - transferManipulation()
 *  - getPhraseOrder()
 *  - resetArray()
 *  - sanitizePhrase()
 *  - sanitizeSignature()
 *  - createLetter()
 * 4. Initialize variables:
 *  - charArray phrases[NUMBER_OF_PHRASES]
 *  - intArray phraseOrder
 *  - int i
 *  - charArray signature
 *  - bool repeatProgram = false
 * 3. helper functions:
 *  - int getString(char array[], int arraySize)
 *    - obtains input from the user and provides error feedback
 *    - returns the string size for convenience
 *  - bool getResponse(void)
 *    - gets a user response to a y / n question
 *    - returns a boolean, true if 'y'
 *  - void clearBufferStream
 *  - void transferManipulation
 *    - will take the manipulated c string and place it back in it's original variable
 *  - void getPhraseOrder
 *    - retreives the phrase order from the user
 *    - places it in an array
 *  - void resetArray
 *      - clears out the contents of the array and replaces it with -1
 *  - void sanitizeSignature
 *      - manipulates the signature
 *  - void sanitizePhrase
 *      - manipulates the phrases
 *  - void createLetter
 *      - prints out the phrases the user selected
 * 4. cout to user a welcome and explain purpose of program
 *  - provide examples of what phrases may look like
 * 5. create a for loop that will loop 4 times for phrase input with increment starting at 1 for i
 *  - prompt user for a phrase
 *  - use getString()
 *  - check that the user inputted a string that was below the max amount
 *  - if not, prompt for re-renty
 *  - if valid, place into one of the prompt variables based on the number of i in the for loop
 * 6. prompt user for a signature
 *  - use getString()
 *  - check for validity, if not prompt for re-entry
 *  - if valid, place into the signature variable
 * 7. sanitize phrases
 *  - use a loop to check within each position
 *  - capitalize the very first character
 *  - check for multiple spaces and truncate if there are more than one next to each other
 *  - place manipulated phrase into the manipulationArray
 *  - check if final character before the '\0' is one of the accepted puncuations, if not, add a '.' in the manipulated array
 *  - strcpy(manipulatedArray, originalPhraseVariable, sizeOfManipulatedArray)
 * 8. Sanitize the signature
 *  - use a loop to check within each position
 *  - capitalize each character that comes after a space
 *  - truncate multiple spaces
 *  - place manipulated phrase into the manipulationArray
 *  - strcpy(manipulatedArray, signature, sizeOfManipulatedArray)
 * 9. wrap steps 10-15 in a while loop with repeatProgram as conditional
 * 10. cout the 4 phrases next to a correlated number
 * 11. Get the phrase order
 *  - Create a do-while loop using the getAnotherPhrase bool
 *  - prompt the user to enter a phrase number
 *  - if invalid, prompt user for re-entry of a valid number 
 *  - place the desired phrase variable number into the phraseOrder[4] array
 *  - prompt the user if they would like to add another phrase
 *      - 'n' addPhrase = false
 *      - 'y' addPhrase = true
 *  - keep track of numbers entered into phaseOrder with phraseOrder.size
 * 12. Once the use has indicated they are done or the 4th phrase is hit, use createLetter() 
 *  - for-loop over phaseOrder with phraseOrder.size
 *  - access phraseOrder[i] to obtain the numerical order
 *  - use phrases[phraseOrder[i] - 1] to obtain the phrase
 *  - cout phrase
 *  - cout signature
 * 14. ask user if they want to create a new letter with phrases
 *      - 'N' repeatProgram = false
 *      - 'Y' repeatProgram = true
 * 15. if user wants to repeat program, must clear out the phaseOrder array with resetArray()
 */

#include <iostream> 
#include <cctype>
#include <cstring>

using namespace std;

// STRUCTS / CONSTANTS

// yes these are globals, simply so the structs
// can have access to the same constant as the rest of the program
// please forgive my purposeful error

// string length will be 131 to include the
// '\0' and true length will be 130
const int STRING_LENGTH = 131;
// number of phrases for the phrase order array
const int NUMBER_OF_PHRASES = 4;
// a struct to hold the strings and their
// lengths together
struct charArray {
    int size;
    char array[STRING_LENGTH];
};
// a struct to hold an array of integers
// and the array size
struct intArray {
    int size;
    int array[NUMBER_OF_PHRASES];
};


// FUNCTION PROTOTYPES

// a helper function for cleaning out the buffer
// since we will be doing it multiple times
void clearBufferStream(void);

// this helper obtains characters and places them into an array
// via array reference
// placement happens insde the while loop expression
// since arrays use references, nothing needs to be returned
// while also validating proper length of input
// it takes an array reference to place the string
// as well as the array size desired
int getString(char array[], int arraySize);

// this helper obtains a single character
// checks if it is a valid y / n response
// and returns a boolean based on if the response
// is yes = true, no = false
bool getResponse(void);

// this function takes the manipulationArray, character struct, and manipulation count
// and transfers the manipulated array back into the original character array within the struct
// nothing is returned since all the manipulations take place within references
void transferManipulation(char manipulationArray[], charArray& charStruct, int manipulationCount);

// this function retreives the order of the phrases
// the user will use and places them into the phraseOrder array
// it also keeps track of the size of the array
// so we don't read into garbage
// since users don't have to print out all phrases
void getPhraseOrder(intArray& phraseOrder);

// this helper will clear out an array's contents / reset the array given
// with the value -1
void resetArray(int array[]);

// this helper provides sanitation of all the phrases
// it takes in the phrases array 'phrases[]' which hold charArray structs
// loops over them, then proceeds to loop over each character array
// based on the size of the array
// and manipulate that array by removing extra spaces
// then transfering the manipulated array back to its original location
void sanitizePhrase(charArray phrases[]);

// this helper provides sanitization of the signature struct
// it loops over each character of the array inside the struct
// up to the arrays size
// checking for multiple spaces and where to capitalize characters
// and then transfers the manipulations back into the original array
void sanitizeSignature(charArray& signature);

// This helper function creates and displays the letter formed from the 
// choices the user made
// it retures the phraseOrder struct, phrases array, and signature struct
void createLetter(intArray& phraseOrder, charArray phrases[], charArray& signature);

int main() 
{
    // VARIABLES

    // accumulator for for-loop because we have to
    int i;
    // an array to contain the string structs
    // for the phrases
    // so they can be easily accessed from within a loop
    // the position of the size matches to the phrase arrays as such:
    // phrases[0] = phrase1 
    // phrases[1] = phrase2 
    // phrases[2] = phrase3 
    // phrases[3] = phrase4 
    charArray phrases[NUMBER_OF_PHRASES];
    // initalize the size of each
    phrases[0].size = 0;
    phrases[1].size = 0;
    phrases[2].size = 0;
    phrases[3].size = 0;
    // a string struct to hold the signature
    charArray signature;
    // initialize the size
    signature.size = 0;
    // manipulation array to place characters while the original array is looped through
    // and manipulated
    // a struct to contain the phrase order a user desires
    // the order array is instansiated with 0
    // as phrases will be 1-4
    intArray phraseOrder;
    // to initalize the array
    resetArray(phraseOrder.array);
    // used for the while expression to repeat the program
    bool repeatProgram = false;
    
    // CODE

    cout << "Welcome, this is a program to help construct a letter out of common phrases." << endl;
    cout << "You will need to enter 4 phrases followed by your signature. Phrases could be: " << endl;
    cout << "\"Thank you, how are you doing?\"" << endl;
    cout << "\"I am well, let's get together soon!\"" << endl;
    cout << "\"Thursday November 29th, 2019\"" << endl;
    cout << "Phrases can be no longer than 130 characters. If you do not include an '!', '.', or '?', a '.' will be appended to your phrase for you." << endl;
    cout << "Now let's enter your phrases!" << endl;
    
    // obtain the phrases from the user
    for(i = 1; i <= NUMBER_OF_PHRASES; ++i)
    {
       cout << "Enter phrase number " << i << ": "; 
    // get the phrase array reference from 'getPhraseArray()' based on the value of 'i'
    // then with that returned reference, get the string input from the user
    // with 'getString()' with a max length of STRING_LENGTH - 1 (130) 
    // so cin.get() will go up to a max size of 129 and place '\0' in 130
    // this will save room to check for punctuation and add any in 130 if the user did not 
    // 'getString()' also returns the size of the string
    // which allows us to place it into the 'phrases' at a position that is 1 less than i
    // since arrays are zero indexed
       phrases[i - 1].size = getString(phrases[i - 1].array, STRING_LENGTH -1);
    }

    // obtain the signature from the user
    cout << "Next, let's entery your signature. Signatures are no more than 130 characters" << endl;
    cout << "Enter your signature: ";
    // obtain the signature string using 'getString()'
    // with the max string length of 131, so up to 130 characters can be placed
    // as .get() will naturally stop at STRING_LENGTH - 1
    // and since 'getString' returns the array size, set the signatureSize variable
    signature.size = getString(signature.array, STRING_LENGTH);

    // sanitize the phrase arrays
   sanitizePhrase(phrases);

   // sanitize the signature
   sanitizeSignature(signature);

   // a do-while loop in case the user wants to display
   // phrases many times
   do 
   {
       // explain the next steps
        
       cout << "Alright, now to construct your letter you need to pick the phrases you'd like to use." << endl;
       cout << "You will enter which phrases you want by typing in the corresponding number one at a time." << endl;
       cout << "They will appear in order entered. You do not have to pick all 4, and you can repeat:" << endl;
       // print out the phrases corresponding to numbers
       for(i = 1; i <= NUMBER_OF_PHRASES; ++i)
       {
           cout << "Phrase " << i << ": " << phrases[i - 1].array << endl;
       }

       getPhraseOrder(phraseOrder);
       // display the phrases 
       createLetter(phraseOrder, phrases, signature);
       
       // if the user would like to do it again
       cout << "Would you like to create another letter with your phrases? (y/n): ";
       repeatProgram = getResponse();
       // the phraseOrder array will need to be cleared out
       if (repeatProgram) resetArray(phraseOrder.array);
   }
   while (repeatProgram);
    
   cout << "Goodbye!" << endl;
    return 0;
}


// HELPER FUNCTIONS


// This helper function creates and displays the letter formed from the 
// choices the user made
// it retures the phraseOrder struct, phrases array, and signature struct
void createLetter(intArray& phraseOrder, charArray phrases[], charArray& signature)
{
    // for looping
    int i;
    // for easier understanding within loop
    int order = -1;
    cout << "~~~~~ Your Letter ~~~~~" << endl;
   // only loop through the amount used
   for(i = 0; i < phraseOrder.size; ++i) 
   {
       // obtain the order
       order = phraseOrder.array[i];
       // since the order is off by one, account for that here
       // since arrays are indexed at 0
       if (order > 0) cout << phrases[order - 1].array << endl;
   }
   cout << "~ "<< signature.array << endl;
   return;
}



// this helper provides sanitization of the signature struct
// it loops over each character of the array inside the struct
// up to the arrays size
// checking for multiple spaces and where to capitalize characters
// and then transfers the manipulations back into the original array
void sanitizeSignature(charArray& signature)
{
   // reset manipulation count from previous use;
   int manipulationCount = 0;
   // for looping
   int i;
   // current character within the loop that manipulates the inputted phrases
   char currChar = '\0';
   // next character within the loop that manipulates the inputted phrases
   // used to help truncate spaces
   char nextChar = '\0';
   // previous character within the loop that manipulates the inputted phrases
   // used to help with capitalizing signature
   char prevChar = '\0';
   // manipulation array to place characters while the original array is looped through
   // and manipulated
   char manipulationArray[STRING_LENGTH] = {'\0'};
   
   for(i = 0; i < signature.size; ++i)
   {
       // obtain previous, current, and next characters
       prevChar = signature.array[i - 1];
       currChar = signature.array[i];
       nextChar = signature.array[i + 1];
        // if the current and previous characters are not spaces or 
        // the current character is a space and the next is not
        if ((prevChar != ' ' && currChar != ' ') || (currChar == ' ' && nextChar != ' ')) 
        {
            manipulationArray[manipulationCount] = currChar;
            // bump our manipulation array count here
            manipulationCount++;
        }
        // if the previous character was a space and the current is not,
        // uppercase it and add
        if (prevChar == ' ' && currChar != ' ') 
        {
            manipulationArray[manipulationCount] = toupper(currChar);
            // bump our manipulation array count here
            manipulationCount++;
        }
   }
   transferManipulation(manipulationArray, signature, manipulationCount);
   return;
}
// this helper provides sanitation of all the phrases
// it takes in the phrases array 'phrases[]' which hold charArray structs
// loops over them, then proceeds to loop over each character array
// based on the size of the array
// and manipulate that array by removing extra spaces
// then transfering the manipulated array back to its original location
void sanitizePhrase(charArray phrases[]) {
    // for looping
    int j;
    // for looping
    int i;
    // used to store array size for easier understanding within the loop that
    // manipulates the inputted phrases
    int size = 0;
    // current character within the loop that manipulates the inputted phrases
    char currChar = '\0';
    // next character within the loop that manipulates the inputted phrases
    // used to help truncate spaces
    char nextChar = '\0';
    // manipulation array to place characters while the original array is looped through
    // and manipulated
    char manipulationArray[STRING_LENGTH] = {'\0'};
    // used to keep track of the manipulationArray count when
    // sanitizing the phrases and signature
    int manipulationCount = 0;
    
    for(i = 1; i <= NUMBER_OF_PHRASES; ++i)
    {
        // store the array size in an easier to understand variable
        size = phrases[i - 1].size;
        // reset manipulation count from previous use;
        manipulationCount = 0;
               
        // use the size of the phrase stored within 'phrases' so we can loop individually over 
        // each character to do our sanitization and no more
        for(j = 0; j < size; ++j)
        {
            // obtain the current character and next character in the phrase  
            currChar = phrases[i - 1].array[j]; 
            nextChar = phrases[i - 1].array[j + 1]; 
            // if the current characater is not a space, just add it
            // or if the current character is a space and the next is not a space
            // add that space
            if (currChar != ' ' || (currChar == ' ' && nextChar != ' ')) 
            {
                manipulationArray[manipulationCount] = currChar;
                // bump our manipulation array count only here
                manipulationCount++;
            }
            // if this is the last character of the current phrase
            // and it is not a '.', '!', or '?'
            // add '.' to the manipulated array at the next position (the end)
            if (j + 1 == size 
                    && (currChar != '!'
                        && currChar != '?'
                        && currChar != '.')) 
            {
                // since we will always have bumped the manipulation count above in the previous if statement, can simply use 'manipulation' count without '+ 1'
                manipulationArray[manipulationCount] = '.';
                // bump the size again here
                manipulationCount++;
            }
        }
       transferManipulation(manipulationArray, phrases[i - 1], manipulationCount);
    }
   return;
}
 


// a helper function for cleaning out the buffer
 // since we will be doing it multiple times
 void clearBufferStream(void)
 {
  // clear out the errorstate
  // just in case it exists
  cin.clear();
  // ignore the rest of what is in the stream
  // up to 200 characters or
  // until carriage return is hit '\n'
  // and we can flush out the carriage return
  cin.ignore(200,'\n');
  return;
 }


 // this helper obtains characters and places them into an array
 // via array reference
 // placement happens insde the while loop expression
 // since arrays use references, nothing needs to be returned
 // while also validating proper length of input
 // it takes an array reference to place the string
 // as well as the array size desired
 int getString(char array[], int arraySize)
 {
     // if the buffer stream is in error state
     while(!cin.get(array, arraySize, '\n')
             // or the next character in the buffer is not a carriage return
             || cin.peek() != '\n')
     {
             // insert a break so we are not on the same line as "enter phrase number...:"
             cout << endl;
             if(cin.peek() != '\n') cout << "You entered too many characters, please try again: ";
             else cout << "Invalid input, please try again: ";
             // clear out that dirty stream
             clearBufferStream();
     }
     // clear out that dirty stream
     clearBufferStream();
     // return the length of the array since we can measure it here and will need it later
     return strlen(array);
 }


 // this helper obtains a single character
 // checks if it is a valid y / n response
 // and returns a boolean based on if the response
 // is yes = true, no = false
 bool getResponse(void)
 {
     char response = '\0';
     // if the buffer stream is in error state
     while(!cin.get(response)
             // if response is not equal to y
             || (tolower(response) != 'y'
                 // if the response is not equal to n
                 && tolower(response) != 'n')
             // or the next character in the buffer is not a carriage return
             || cin.peek() != '\n')
     {
             if(cin.peek() != '\n') cout << "You entered too many characters, please try again: ";
             else cout << "Invalid input, please try again: ";
             // clear out that dirty stream
             clearBufferStream();
     }
             // clear out that dirty stream
             clearBufferStream();
     // return a boolean
     return tolower(response) == 'y';
 }


 // this function takes the manipulationArray, character struct, and manipulation count
 // and transfers the manipulated array back into the original character array within the struct
 // nothing is returned since all the manipulations take place within references
 void transferManipulation(char manipulationArray[], charArray& charStruct, int manipulationCount)
 {
    // capitalize the first character of the array
    manipulationArray[0] = toupper(manipulationArray[0]);
    // add the null terminator
    manipulationArray[manipulationCount] = '\0';
    // the manipulated array may now be smaller than the original size
    // and our manipulationCount has the true size of the array
    // does not include the size of the null terminator
    charStruct.size = manipulationCount;
    // place the contents of the manipulation array back in the phrase
    // only go up to the size of the array, because manipulationArray
    // may contain leftovers from previous maniplations
    // include + 1 in the copying so the null terminator is copied as well
    strncpy(charStruct.array, manipulationArray, manipulationCount + 1);
   return;
 }


 // this function retreives the order of the phrases
 // the user will use and places them into the phraseOrder array
 // it also keeps track of the size of the array
 // so we don't read into garbage
 // since users don't have to print out all phrases
 void getPhraseOrder(intArray& phraseOrder)
 {
     // for the placement in the order
     int count = 0;
     // create a condition for the while loop
     bool getAnotherPhrase = false;
     // an easier to understand variable
     int number = 1;
     do
     {
         cout << "Enter a number: ";
         // while the buffer is in an error state
         while(!(cin >> number)
                 // or the number is less than 1
                 || number < 1
                 // or the number is greater than 4
                 || number > 4)
         {
             cout << "Invalid entry, please try again: ";
             clearBufferStream();
         }
         // add the number to the array
         phraseOrder.array[count] = number;
         count++;
         // clear out that pesky '\n'
         clearBufferStream();
         // if we have not yet reached our maximum size in the array
         if (count < NUMBER_OF_PHRASES)
         {
         cout << "Would you like to add another phrase? (y/n): ";
         getAnotherPhrase = getResponse();
         }
         else getAnotherPhrase = false;
         // set the size of the array
         phraseOrder.size = count;
     }
     while(getAnotherPhrase);
     return;
 }


 // this helper will clear out an array's contents / reset the array given
 // with the value -1
 void resetArray(int array[])
 {
     // for looping
     int i;
     for (i = 0; i < NUMBER_OF_PHRASES; ++i) array[i] = -1;
     return;
 }
