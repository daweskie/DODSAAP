/*
 *
 * Copyright (C) 2011 Institute for Information Technology and Electrical Engineering
 * of Pollack Mihály Faculty of Engineering University of Pécs
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY{} without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/**
\brief String utilities

\author AUTHOR: Zoltan Zidarics mailto:zamek42@gmail.com
\David Dobo
\mainpage

    Different string functions which is not in strings.h or simplify the strings functions.

*/

#ifndef STRUTIL_H_INCLUDED
#define STRUTIL_H_INCLUDED

#include <stdint.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include "macros.h"
//#include <glob.h>

//struct StringBuilder {
  //  uint16_t pos;
    //size_t size;
    //char *chars;
//};

/**
 \defgroup strings String functions
 @{
    Different string functions which is not in strings.h or simplify the strings functions.
 @}
 */

/**
strStartWith
    finds the given pattern in str from the begin
    \ingroup strings
    \param str original string to find within it. str can be NULL
    \param pattern for search. pattern can be NULL
    \return index of first occurence of pattern or -1 if not
*/
int strStartWith(const char *str, const char *pattern){
    if ( !str || !*str || !pattern || !*pattern )
        return -1;

    const char *temp = pattern;
    int begin = 0, index = 0;

    while ( *str && *temp )
    {
        if ( *str == *temp )                // egyezés
        {
            index++, str++, temp++;
            continue;
        }

        else if ( index )                   // nincs, de előzőleg volt
        {
            str -= index - 1;
            temp = pattern;
            begin++;
            index = 0;
            continue;
        }
        else                                // nincs találat
        {
            index = 0;
            str++, begin++;
            continue;
        }
    }

    if ( !*str && *temp )                   // forrásnak vége van, de minta még nem ért a végére
        return -1;


    if ( index )
        return begin;

    return -1;
}

/**
strEndWith
    finds the given pattern in str from the end
    \ingroup strings
    \param str original string to find within it. str can be NULL
    \param pattern for search. pattern can be NULL
    \return index of first occurence of pattern or -1 if not
*/
int strEndWith(const char *str, const char *pattern)
{
    if (! (str && pattern && *str && *pattern) )
        return -1;

    char *sb = str, *pb=pattern;

    while (*str++);

    while (*pattern++);

    str--;
    pattern--;
    while (pattern > pb && str > sb && (*str-*pattern) == 0);

    return pattern == pb ? str - sb : -1;
}

/**
strIsEmpty
    checks str is empty. str can be NULL
    \ingroup strings
    \param str to check
    \return -1 if str is NULL || length of str is 0

*/
int strIsEmpty(const char *str)
{
    if(!str || !*str){
        return -1;
        }
            return 0;
}


/**
strIsBlank
    checks str is empty or blank(contains only whitespace)
    \ingroup strings
    \param str to check. str can be NULL
    \return 0 if str is NULL || length of str is 0 or all of char is whitespace

*/
int strIsBlank(const char *str)

{
    if (!str || !*str)
        return 0;

    int karpo;
    int len = strlen(str);
    for(karpo=0;karpo!=len;karpo++)
        if (!isspace(*(str+karpo)))
            return 1;

    return 0;

}


/**
strIsAlpha
    checks is str contains only alpha characters (a-zA-Z)
    \ingroup strings
    \param str str to check. str can be NULL
    \return 0 if not only alpha || str is empty
*/


int strIsAlpha(const char *str){

	register char c;

	if (!str || !*str)
		return 0;

	while ((c = *str++)) {
		if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')))
			return 0;
	}
	return 1;
}

/**
strIsNumeric
    checks is str contains only numeric characters (0-9)
    \ingroup strings
    \param str str to check. str can be NULL
    \return 0 if not only numeric || str is empty
*/
int strIsNumeric(const char *str)
{
    if (!str || !*str)
        return 0;

    register char c;

    while ((c=*str++))
        if (c < '0' || c > '9')
            return 0;

    return 1;
}

/**
strReplaceChar
    changes the first occurence of char ins str to an another char
    \ingroup strings
    \param str the original str to change into. str can be NULL
    \param findCh char to find within str
    \param chgCh char to change
*/
void strReplaceChar(char *str, char findCh, char chgCh)
{
     char c;

	if (!str || !*str)
        return;

    for (; (c=*str); str++)
        if (c==findCh) {
            *str=chgCh;
            return;
        }
}
/**
strToLowerCase
    change all alphanumeric chars to lower case
    \ingroup strings
    \param str original str to change. str can be NULL
*/
void strToLowerCase(char *str)
{
if (!str || !*str)
        return;

    register char ccc;
    while ((ccc=*str)) {
        if (ccc>='A' && ccc <='Z')
            *str |= 0x20;
        str++;
    }
}

/**
strToUpperCase
    change all alphanumeric chars to lower case
    \ingroup strings
    \param str original str to change. str can be NULL
*/
void strToUpperCase(char *str){
    if (!str || !*str)
        return;
    register char ccc;
    while ((ccc=*str)) {
        if (ccc>='a' && ccc <='z')
            *str &= ~0x20;
        str++;
    }
}

/**
strTrim
    removes leading and trailing whitespace.
    \ingroup strings
    \param str original string to processing. str can be NULL.
*/
void strTrim(char *str)
{
    if (!str || !*str)
        return;

    char *kezd=str;
    while(isspace(*kezd))
    ++kezd;

    char *veg=kezd;
    while (*veg++);
    --veg;
    --veg;

    while (isspace(*veg))
        --veg;

    if (veg < kezd) {
        *str='\0';
        return;
    }

    int i=veg-kezd;

    for (;i>=0; --i)
        *str++ = *kezd++;
    *str='\0';
}



/**
strConst
    returns a new string to fill the given character and length
    \ingroup strings
    \param ch character to fill
    \param length the length of the new string. if length is 0, returns an empty string
    \return the new string. Caller must free the copy
*/
char *strConst(char ch, int length)
{

char *ujstr, *atmenet;

	MALLOC(ujstr, length*sizeof(char)+1);

    for (atmenet=ujstr; length>0; length--,*atmenet++ = ch)
        ;

    *atmenet='\0';
	return ujstr;
}


/**
strCenter
    returns a copy of given str justified to center.
    \ingroup strings
    \param str the original str to justify with spaces. str can be NULL
    \param length the new length of the string.
    \return the new copy of string.
            if length is 0, it returns NULL
            if length is less than the length of string it returns a copy of str.
            Caller must free the copy
*/
char *strCenter(const char *str, int length)
{
    if ( !str || !*str || length < 1 )
        return NULL;

    const int strLngth = strLen( str );

    if ( length <= strLngth )
        return strDup( str );

    char *newStr;
    const int spaces = length - strLngth;                 // szóközök száma összesen
    int i;

    MALLOC( newStr, length + 1 ) ;

    char *temp = newStr;

    for ( i = 0; i < spaces / 2; i++ )                    // srting előtt álló szőközök
        *newStr++ = ' ';

    strcpy( newStr, str );

    newStr += strLngth;

    if ( spaces & 1 )                                     // páratlan szóköz vizsgálat
        for ( i = 0; i < ( spaces / 2 ) + 1; i++ )        // a string mögött eggyel több lesz
            *newStr++ = ' ';                              // a C nyelv sajátossága miatt

    else                                                  // páratlan szóköz esetén
        for ( i = 0; i < spaces / 2; i++ )
            *newStr++ = ' ';

    *newStr = '\0';

    return temp;
}



/**
strLeft
    returns a copy of given str justified to left.
    \ingroup strings
    \param str the original str to justify with spaces. str can be NULL
    \param length the new length of the string.
    \return the new copy of string.
            if length <= 0, there isn't any memory, it isn't string -> returns NULL
            if length is less than the length of string, copy the first "length" pieces of characters and returns with them.
            Caller must free the copy
*/
char *strLeft(const char *str, int length)
{
    if (!str || !*str || length<=0)
            return NULL;

    char *cstr,*atmenet;
    char c;
    int maxlength=((length+1)*sizeof(char));
    int bsw;

    MALLOC(cstr,maxlength);
    atmenet=cstr;

    bsw=0;
    c=*str;

    while (maxlength>>1)
    {
        if (c==' ' && bsw==0)
            str++;

        else if (c!='\0')
        {
            bsw=1;
            *cstr=*str;
            cstr++;
            str++;
            maxlength--;
        }

        else
         {
            *cstr++=' ';
            maxlength--;
        }
        c=*str;
    }

    *++cstr='\0';

    return atmenet;

}


/**
strRight
    returns a copy of given str justified to right
    \ingroup strings
    \param str the original str to justify with spaces. str can be NULL
    \param length the new length of the string.
    \return the new copy of string.
            if length is 0, it returns NULL.
            if length is less than the length of string it returns a copy of str.
            Caller must free the copy
*/
char *strRight(char *str, int length)
{
     if (!str || !*str || length<=0)
        return NULL;

    int strh = strlen(str);
    int i;
    int lmins = length-strh;
    char *string;
    MALLOC(string,length*sizeof(char));

    if (strh >= length)
        return str;

    char *temp=string;
    for (i=0; i<lmins; i++)
        *string++ = ' ';

    char c;
    while((c=*str++))
        *string++=c;

    return temp;

}




/**
strChomp
    removes the last line end chars of str.
    It can handle Macintosh/linux/windows eol format
    \ingroup strings
    \param str original string to processing. str can be NULL
    \return the beginning of original string
*/
void strChomp(char *str)
{
     if(!str || !*str)
        return str;

    char *b=str;

    while(*++str)
        ;
    --str;
    register char c;
    while ((c=*str) && str >= b)  {
        if (c != '\r' && c != '\n')
            return b;
        *str--='\0';
    }
    return b;
}


/**
strReplaceStr
    replace substring of string to new str
    \ingroup strings
    \param str original string to replace within. str can be NULL
    \param pattern to find within str. pattern can be NULL
    \param replace replace. can be NULL
    \return a new copy of replaced string
            Caller must free the copy

*/
char *strReplaceStr(char *str, char *pattern, char *replace)
{
    if (!str || !*str || !pattern || !*pattern || !replace )
        return 0;

    char *originalStr=str;
    char *originalPattern=pattern;
    int countMatch=0;

    while(*str)
    {
        if(*str==*pattern)
        {
            pattern++;
            if(!*pattern)
            {
                countMatch++;
                pattern=originalPattern;
            }
        }
        else
        {
            pattern=originalPattern;
            if(*str==*pattern)
                pattern++;
        }
        str++;
    }
    pattern=originalPattern;
    str=originalStr;

    if(!countMatch)
        return 0;

    int replaceLen=strlen(replace);
    int patternLen=strlen(pattern);
    int mValue=(( strlen(str)-(patternLen*countMatch))+(replaceLen*countMatch)+1);

    char *newStr=NULL;
    MALLOC(newStr,mValue*sizeof(char));

    char *originalNewStr=newStr;
    char *temp=NULL;

    while(*str)
    {
        temp=strstr(str,pattern);
        if(temp==str)
        {
            strncpy(newStr,replace,replaceLen);
            newStr=newStr+replaceLen-1;
            str=str+patternLen-1;
        }
        else
            *newStr=*str;
        str++;
        newStr++;
    }
    return originalNewStr;
}
/**
strRemoveStr
    removes pattern from str
    \ingroup strings
    \param str original string to remove from. str can be NULL
    \param pattern for removing. pattern can be NULL
*/
void strRemoveStr(char *str, char *pattern)
{
    if (!str || !*str || !pattern || !*pattern)
        return ;

    int patternh=strlen(pattern);
    int strh=strlen(str);

    if (patternh>strh)
        return ;
    int i,l,z;
    for (i=0; i<(strh-patternh+1);i++){

           if (*(str+i)==(*(pattern))){
            for (l=0; l<patternh;l++){
                if (*(str+i+l)!=*(pattern+l))
                    break;

                if(l==patternh-1){
                    for (z=0;z<strh-i-patternh;z++)

                        *(str+i+z)= *(str+i+patternh+z);
                           *(str+strh-patternh)= '\0';
                        strh=strh-patternh;
                        }
                    }
                }
            }


/**
strReverse
  reverse the given string
  \ingroup strings
  \param str string to reverse str can be NULL
  \return the new reversed string
          Caller must free the copy
*/
char *strReverse(const char *str2)
{
    if(!str2 || !*str2)
        return NULL;

    int l = strlen(str2);

    char *ns;
    MALLOC(ns,(l+1)*sizeof(char));
    char *begin=ns;
    str2+=l-1;

    while(l--)
        *ns++=*str2--;
    *ns='\0';
    return begin;
}


/**
strCapitalize
  capitalize the first char of all words in string. str can be NULL
  \ingroup strings
  \param str to capitalize
*/
void strCapitalize(char *str)
{
    if ( !str || !*str )
        return;

    register char ch = *str, temp;


    if ( islower( ch ) )                                  // első karakter nagybetúsítése
        *str++ -= 0x20;

    while ( ( ch = *str++ ) )
    {
        temp = *str;
        if ( isspace( ch ) && isalpha( temp ) )         // minden további karakert nagybetűsít,
            if ( islower( temp ) )                     // mely előtt szóköz található
                    *str++ -= 0x20;
    }
}

/**
strFindInArray
   find a string in a string array. If the pattern isn't in the array, it returns the default value.
   \ingroup strings
   \param pattern to find
   \param arr_size the size of the array
   \param arr the array
   \param def default value if the pattern isn't in array
   \return if the pattern is in the arr, the index of founded item or def
*/
int strFindInArray(char *pattern, int arr_size, char *arr[], int def){}


/**
strBufferToHex
    get a string buffer converted hexadecimal values of input
    \ingroup strings
    \param buffer input buffer. It can be NULL
    \param buffer_length length of input buffer. It can be 0
    \param hexBuffer output buffer. It can be NULL, but if not NULL, need to be enough memory to store output length * 3 char
    \return the address of output buffer
*/
char *strBufferToHex(char *buffer, int buffer_length, char *hexBuffer)
{
    if (!buffer || !hexBuffer || buffer_length <=0)
        return NULL;

    char *temp=hexBuffer;

    for (;buffer_length;--buffer_length) {
        unsigned char ch=*buffer++;
        hexBuffer += sprintf(hexBuffer, "%02X ", ch);
    }
    return temp;
}

}
/**
 \defgroup stringbuilder String builder
 @{
 Stringbuilder is resource to build strings.
 Create it with \link strNewStringBuilder() \endlink. It creates a new builder, which can
 append different chars and strings to builded string. If the string is longer than the initial
 size of builder, it generates a new buffer.
 The data type is struct StringBuilder which has chars field to use as string.

 The clear of Stringbuilder is strClearBuilder(), which set it to empty string.
 The strFreeBuilder is free the entire StringBuilder.
 @}
 */

/**
    strNewStringBuilder
    \ingroup stringbuilder
    Create a new StringBuilder with the given capacity.
    \param capacity the initial capacity of builder. If the capacity is less than 0
        it creates the default size of buffer which is \link DEF_STRING_BUILDER_LEN \endlink
    \return the pointer to a new struct StringBuilder
*/
//struct StringBuilder *strNewStringBuilder(uint16_t capacity){}

/**
    strAppendStr
    \ingroup stringbuilder
    Appends a string to the builder.
    \param builder is a pointer to the StringBuilder. If the builder is NULL, it creates a
    new StringBuilder.
    \param str the string to append to Builder. If str is NULL it only create a new StringBuilder.
    \return the pointer to the stringbuilder.
*/
//struct StringBuilder *strAppendStr(struct StringBuilder *builder, const char *str){}

/**
    strAppendChar
    \ingroup stringbuilder
    Appends a char to the builder.
    \param builder is a pointer to the StringBuilder. If the builder is NULL, it creates a
    new StringBuilder.
    \param ch the char to append to Builder.
    \return the pointer to the stringbuilder.
*/
//struct StringBuilder *strAppendChar(struct StringBuilder *builder, char ch){}

/**
    strFreeBuilder
    \ingroup stringbuilder
    Free the given builder
    \param builder to be freeing. builder can be NULL.
*/
//void strFreeBuilder(struct StringBuilder *builder){}


/**
    strClearBuilder
    \ingroup stringbuilder
    Clear the given builder. It set the length to 0
    \param builder to be clearing. sb can be NULL.
*/
//void strClearBuilder(struct StringBuilder *builder){}




#endif // STRUTIL_H_INCLUDED


