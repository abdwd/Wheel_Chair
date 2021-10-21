/*
 * STD_TYPES.h
 *
 * Created: 9/1/2021 9:01:25 PM
 *  Author: Karim Essam
 */ 


#ifndef STD_TYPES_H_
#define STD_TYPES_H_

typedef unsigned char			u8;
typedef unsigned short int		u16;
typedef unsigned long int		u32;

typedef char					s8;
typedef short int				s16;
typedef long int				s32;

typedef float					f32;
typedef double					f64;


#define NULL_PTR    ((void*)0)

typedef unsigned char         uint8;          /*           0 .. 255             */
typedef signed char           sint8;          /*        -128 .. +127            */
typedef unsigned short        uint16;         /*           0 .. 65535           */
typedef signed short          sint16;         /*      -32768 .. +32767          */
typedef unsigned long         uint32;         /*           0 .. 4294967295      */
typedef signed long           sint32;         /* -2147483648 .. +2147483647     */
typedef unsigned long long    uint64;         /*       0..18446744073709551615  */
typedef signed long long      sint64;
typedef float                 float32;
typedef double                float64;

#endif /* STD_TYPES_H_ */
