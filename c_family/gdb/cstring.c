#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *str;
    int len;
}CString;

/*
translate a c tring to CString
*/
CString *Init_CString( char *str ){
    CString *p = malloc( sizeof( CString ) );
    p->len = strlen( str );
    p->str = malloc( p->len + 1 );
    strncpy( p->str, str, strlen( str )+1 );
    return p;
}

/*
Free a CString node
*/
void Delete_CString( CString *p ){
    free( p->str );
    free( p );
    return;
}

/*
Remove the last character of a CString and return it.
*/

char Chomp( CString *cstring ){
    char lastchar = *( cstring->str + cstring->len - 1 );
    //Shorten the string by one
    *( cstring->str + cstring->len -1 ) = '\0';
    cstring->len = strlen( cstring->str );
    return lastchar;
}

/*
Appends a char * to a CString
*/
CString *Append_Chars_To_CString( CString *p, char * str ){
    char *newstr = malloc( p->len + strlen(str) + 1 );
    p->len = p->len + strlen( str );
    //Create the new string to replace p->str;
    snprintf( newstr, p->len + 1, "%s%s", p->str, str );
    //Free old string and make CStirng point to the new string
    free( p->str );
    p->str = newstr;
    return p;
}

int main( void ){
    CString *mystr;
    char c;
    mystr = Init_CString( "Hello!" );
    printf( "Init:\n str: '%s' len: %d\n", mystr->str, mystr->len );
    c = Chomp( mystr );
    printf( "Chomp '%c':\n str: '%s' len: %d\n", c, mystr->str, mystr->len );
    mystr = Append_Chars_To_CString( mystr, " world!" );
    printf( "Append:\n str: '%s' len: %d\n", mystr->str, mystr->len );
    Delete_CString( mystr );

    return 0;
}
