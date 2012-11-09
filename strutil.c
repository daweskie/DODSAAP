/*
 *
 * Copyright (C) 2011 Institute for Information Technology and Electrical Engineering
 * of Pollack Mihály Faculty of Engineering University of Pécs
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/**
FILE NAME: strutil.c
AUTHOR: 

String utilities

*/

/**
    returns the length of string. Teminator \0 is not included.
    NULL safe
    \param str the string
    \return if string is NULL returns 0 otherwise returns the length of string without terminal \0
*/
int strLen(const char *str)
{
    if (!str || !*str)
        return 0;
    int i=0;
    while (*str++)
        i++;
    return i;
}

/**
strStartWidth

    finds the given pattern in str from the begin
    \param str original string to find within it. str can be NULL
    \param pattern for search. pattern can be NULL
    \return index of first occurence of pattern or -1 if not
*/
int strStartWith(const char *str, const char *pattern)
{
}

/**
strEndWith

    finds the given pattern in str from the end
    \param str original string to find within it. str can be NULL
    \param pattern for search. pattern can be NULL
    \return index of first occurence of pattern or -1 if not
*/
int strEndWith(const char *str, const char *pattern)
{
}


/**
strIndexOfChar
    
    returns the first index of the given char or -1 if not
    \param str the original str to find within it. str can be NULL
    \param ch the char to find within str.
    \return index of first occurence of ch or -1 if not
*/
int strIndexOfChar(const char *str, const char ch)
{
}


/**
strIsEmpty
    
    checks str is empty. str can be NULL
    \param str to check
    \return 0 if str is NULL || length of str is 0 

*/
int strIsEmpty(const char *str)
{
}


/**
strIsBlank
    
    checks str is empty or blank(contains only whitespace)
    \param str to check. str can be NULL
    \return 0 if str is NULL || length of str is 0 or all of char is whitespace

*/
int strIsBlank(const char *str)
{
}


/**
strIsAlpha
    
    checks is str contains only alpha characters (a-zA-Z)
    \param str str to check. str can be NULL
    \return 0 if not only alpha || str is empty
*/
int strIsAlpha(const char *str)
{
}


/**
strIsNumeric
    
    checks is str contains only numeric characters (0-9)
    \param str str to check. str can be NULL
    \return 0 if not only numeric || str is empty
*/
int strIsNumeric(const char *str)
{
}


/**
strReplaceChar
    
    changes the first occurence of char ins str to an another char
    \param str the original str to change into. str can be NULL
    \param findCh char to find within str
    \param chgCh char to change
*/
void strReplaceChar(char *str, char findCh, char chgCh)
{
}


/**
strDup
    
    returns a copy of given string.
    \param str the source string. str can be NULL
    \return the copy of str.
            Caller must free the copy
*/
char *strDup(const char *str)
{
}


/**
strToLowerCase
    
    change all alphanumeric chars to lower case
    \param str original str to change. str can be NULL
*/
void strToLowerCase(char *str)
{
}


/**
strToUpperCase
    
    change all alphanumeric chars to lower case
    \param str original str to change. str can be NULL
*/
void strToUpperCase(char *str)
{
}


/**
strTrim
    
    removes leading and trailing whitespace.
    \param str original string to processing. str can be NULL.
*/
void strTrim(char *str)
{
}


/**
strConst
    
    returns a new string to fill the given character and length
    \param ch character to fill
    \param length the length of the new string. if length is 0, returns an empty string
    \return the new string. Caller must free the copy
*/
char *strConst(char ch, int length)
{
}


/**
strCenter
    
    returns a copy of given str justified to center.
    \param str. the original str to justify with spaces. str can be NULL
    \param length the new length of the string.
    \return the new copy of string.
            if length is 0, it returns NULL
            if length is less than the length of string it returns a copy of str.
            Caller must free the copy
*/
char *strCenter(const char *str, int length)
{
}


/**
strLeft
    
    returns a copy of given str justified to left.
    \param str. the original str to justify with spaces. str can be NULL
    \param length the new length of the string.
    \return the new copy of string.
            if length is 0, it returns NULL
            if length is less than the length of string it returns a copy of str.
            Caller must free the copy
*/
char *strLeft(const char *str, int length)
{
}


/**
strChop
    
    removes the last char of str.
    \param str. original string to processing. str can be NULL
*/
void strChop(char *str)
{
}


/**
strRemoveStr
    
    removes pattern from str
    \param str original string to remove from. str can be NULL
    \param pattern for removing. pattern can be NULL
*/
void strRemoveStr(char *str, char *pattern)
{
}


/**
strReverse
  
  reverse the given string
  \param str string to reverse str can be NULL
  \return the new reversed string
          Caller must free the copy
*/
char *strReverse(const char *str)
{
}


/**
strCapitalize
  
  capitalize the first char of all words in string. str can be NULL
  \param str to capitalize
*/
void strCapitalize(char *str)
{
}

