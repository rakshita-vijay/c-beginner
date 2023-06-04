#include <stdio.h>

int main()
{
    enum Company {GOOGLE, FACEBOOK, XEROX, YAHOO = 10, EBAY = 20, MICROSOFT};

    enum Company google = GOOGLE;
    enum Company facebook = FACEBOOK;
    enum Company xerox = XEROX;
    enum Company yahoo = YAHOO;
    enum Company ebay = EBAY;
    enum Company microsoft = MICROSOFT;

    printf("XEROX is: %i\n", xerox);
    printf("GOOGLE is: %i\n", google);
    printf("EBAY is: %i\n", ebay);
}
