/* NESCJS: EMULATOR FOR THE NINTENDO ENTERTAINMENT SYSTEM (R) ARCHITECTURE */
/* Author: Christian Bryant (C) 2017 -http://rvaroms.com */
/* Trademarks are owned by their respective owners. */ 
#include <stdlint.h>
#include <SDL.h>
#include <signal.h>
#include <assert.h>
#include <cmath.h>

#include <vector>

// Integer types
typedef uint_least32_t u32;
typedef uint_least16_t u16;
typedef uint_least8_t u8;
typedef int_least8_t s8; 

// Bitfield utilities 
template(unsigned bitno, unsigned nbits=1, typename T=u8)
struct RegBit
{
    T data;
    enum { mask = (1u << nbits) -1u };
    template<typename T2>;
    RegBit& operator=(T2 val)
    {
    }
    operator usigned() const { }
    RegBit& operator++ ()    { }
    usigned operator++ (int)    { }
};

namespace CPU_ /* CPU: Richo RP2A03 (based on MOS6502, ~ Commodore 64-esque) */
{
    // CPU registers:
    u16 PC=0xC000;
    u8 A=0,X=0,Y=0,S=0;
    union /* Status flags: */
    {
        RegBit<0> C; // carry
        RegBit<1> Z; // zero
        RegBit<2> I; // Interrupt enable/disable
        RegBit<3> D; // decimal mode (unsupported on NES, but testing)
        RegBit<6> V; // overflow 
        RegBit<7> N; // negative
    } P;
}