# CS162_program2

  Grace Provost
  gprovost@pdx.edu
  Program 2
  10/18/19
  CS 162

 PURPOSE: This program is intended to help users create and organize common phrases they use in everyday messages with a signature. The user will enter 4 phrases and 1 signature, and then will be able to choose which phrases to place in a message in whatever order they prefer followed by their signature. They will be able to do re-create messages from the phrases as much as they like.

 _______ CODE ALGORITHM______

 1. Initialize constants STRING_LENGTH = 131 and NUMBER_OF_PHRASES = 4
 2. Initialize variables two structs to hold a character array and integer array, along with their sizes
 3. Declare function prototypes
  - clearBufferString()
  - getResponse()
  - transferManipulation()
  - getPhraseOrder()
  - resetArray()
  - sanitizePhrase()
  - sanitizeSignature()
  - createLetter()
 4. Initialize variables:
  - charArray phrases[NUMBER_OF_PHRASES]
  - intArray phraseOrder
  - int i
  - charArray signature
  - bool repeatProgram = false
 3. helper functions:
  - int getString(char array[], int arraySize)
    - obtains input from the user and provides error feedback
    - returns the string size for convenience
  - bool getResponse(void)
    - gets a user response to a y / n question
    - returns a boolean, true if 'y'
  - void clearBufferStream
  - void transferManipulation
    - will take the manipulated c string and place it back in it's original variable
  - void getPhraseOrder
    - retreives the phrase order from the user
    - places it in an array
  - void resetArray
      - clears out the contents of the array and replaces it with -1
  - void sanitizeSignature
      - manipulates the signature
  - void sanitizePhrase
      - manipulates the phrases
  - void createLetter
      - prints out the phrases the user selected
 4. cout to user a welcome and explain purpose of program
  - provide examples of what phrases may look like
 5. create a for loop that will loop 4 times for phrase input with increment starting at 1 for i
  - prompt user for a phrase
  - use getString()
  - check that the user inputted a string that was below the max amount
  - if not, prompt for re-renty
  - if valid, place into one of the prompt variables based on the number of i in the for loop
 6. prompt user for a signature
  - use getString()
  - check for validity, if not prompt for re-entry
  - if valid, place into the signature variable
 7. sanitize phrases
  - use a loop to check within each position
  - capitalize the very first character
  - check for multiple spaces and truncate if there are more than one next to each other
  - place manipulated phrase into the manipulationArray
  - check if final character before the '\0' is one of the accepted puncuations, if not, add a '.' in the manipulated array
  - strcpy(manipulatedArray, originalPhraseVariable, sizeOfManipulatedArray)
 8. Sanitize the signature
  - use a loop to check within each position
  - capitalize each character that comes after a space
  - truncate multiple spaces
  - place manipulated phrase into the manipulationArray
  - strcpy(manipulatedArray, signature, sizeOfManipulatedArray)
 9. wrap steps 10-15 in a while loop with repeatProgram as conditional
 10. cout the 4 phrases next to a correlated number
 11. Get the phrase order
  - Create a do-while loop using the getAnotherPhrase bool
  - prompt the user to enter a phrase number
  - if invalid, prompt user for re-entry of a valid number
  - place the desired phrase variable number into the phraseOrder[4] array
  - prompt the user if they would like to add another phrase
      - 'n' addPhrase = false
      - 'y' addPhrase = true
  - keep track of numbers entered into phaseOrder with phraseOrder.size
 12. Once the use has indicated they are done or the 4th phrase is hit, use createLetter()
  - for-loop over phaseOrder with phraseOrder.size
  - access phraseOrder[i] to obtain the numerical order
  - use phrases[phraseOrder[i] - 1] to obtain the phrase
  - cout phrase
  - cout signature
 14. ask user if they want to create a new letter with phrases
      - 'N' repeatProgram = false
      - 'Y' repeatProgram = true
 15. if user wants to repeat program, must clear out the phaseOrder array with resetArray()
