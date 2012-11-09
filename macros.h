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
FILE NAME: strutil.c
AUTHOR: students of Embedded Systems faculty

   useful macros for utils
*/

#ifndef _MACROS_H_
#define _MACROS_H_

#define MALLOC(ptr,size) do { ptr=malloc(size); if (!ptr) exit(EXIT_FAILURE);} while(0)

#define FREE(ptr) do {free(ptr); ptr = NULL;} while(0)

#define MAX(a,b) ((a)<(b)) ? (b) : (a)

#define MIN(a,b) ((a)>(b)) ? (b) : (a)

#define AVERAGE(x,y) (((x)+(y))/2.0)

#define LOBYTE(w) ((uint8_t)(w))

#define HIBYTE(w) ((uint8_t)((((uint16_t)(w)>>8) & 0xff)))

#define BIT_CLEAR(val,mask) ((val) &=(~(mask)))

#define BIT_SET(val,mask) ((val) |= (mask))

#define BIT_TOGGLE(val,mask) ((val) ^= (mask))

#endif // _MACROS_H_
