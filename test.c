/*
 *
 * Copyright (C) 2010 Institute for Information Technology and Electrical Engineering
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
FILE NAME: test.c
AUTHOR:

Tests for  strutil
*/

#include <stdio.h>
#include <assert.h>

#include "strutil.h"


void testStrLen()
{
    strLen(NULL);
    assert(strLen("")==0);
    assert(strLen(" ")==1);
    assert(strLen("123456")==6);
}

int testStrStartWith()
{
    assert(1!=1);
}

int testStrEndWith()
{
    assert(1!=1);
}

int testStrIndexOfChar()
{
    assert(1!=1);
}

int testStrIsEmpty()
{
    assert(1!=1);
}

int testStrIsBlank()
{
    assert(1!=1);
}

int testStrIsAlpha()
{
    assert(1!=1);
}

int testStrIsNumeric()
{
    assert(1!=1);
}

void testStrReplaceChar()
{
    assert(1!=1);
}

char testStrDup()
{
    assert(1!=1);
}

void testStrToLowerCase()
{
    assert(1!=1);
}

void testStrToUpperCase()
{
    assert(1!=1);
}

void testStrTrim()
{
    assert(1!=1);
}

char testStrConst()
{
    assert(1!=1);
}

char testStrCenter()
{
    assert(1!=1);
}

char testStrLeft()
{
    assert(1!=1);
}

void testStrChop()
{
    assert(1!=1);
}

void testStrRemoveStr()
{
    assert(1!=1);
}

char testStrReverse()
{
    assert(1!=1);
}

void testStrCapitalize()
{
    assert(1!=1);
}

void testAll()
{
    testStrLen();
    testStrStartWith();
    testStrEndWith();
    testStrIndexOfChar();
    testStrIsEmpty();
    testStrIsBlank();
    testStrIsAlpha();
    testStrIsNumeric();
    testStrReplaceChar();
    testStrDup();
    testStrToLowerCase();
    testStrToUpperCase();
    testStrTrim();
    testStrConst();
    testStrCenter();
    testStrLeft();
    testStrChop();
    testStrRemoveStr();
    testStrReverse();
    testStrCapitalize();
}

