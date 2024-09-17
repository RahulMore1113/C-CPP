#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> //While using boolean {_Bool}

int main()
{
    // Enum
    //  enum gender {male, female};
    //  enum gender myGender;
    //  myGender = male;
    //  enum gender anotherGender = female;

    // Character
    //  char myChar = '\n';
    //  printf("%c", myChar);

    // Boolean
    //  bool myBool = true;
    //  bool anotherBool = false;

    // Taking input from user & printing that
    //  int myFavoriteNumber = 0;
    //  printf("Please enter your favorite number\n");
    //  scanf("%d", &myFavoriteNumber);
    //  printf("Your entered number: %d\n", myFavoriteNumber);
    //  printf("Hello World");

    enum Company
    {
        GOOGLE,
        FACEBOOK,
        XEROX,
        YAHOO = 10,
        EBAY,
        MICROSOFT
    };
    enum Company xerox = XEROX;
    enum Company google = GOOGLE;
    enum Company ebay = EBAY;
    enum Company facebook = FACEBOOK;
    printf("The value of the xerox is: %d\n", xerox);
    printf("The value of the google is: %d\n", google);
    printf("The value of the ebay is: %d\n", ebay);
    printf("The value of the facebook is: %d\n", facebook);

    return 0;
}