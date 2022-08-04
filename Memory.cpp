/**
 * \copyright Copyright (c) 2021-2022, AZZ (aka) Blackburn
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
 *
 * 1* Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
 *
 * 2* Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
 *
 * 3* Neither the name of copyright holders nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
 *
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS “AS IS” AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * \author Ahmed Ziabat
 * \date 4/08/22 11:07
 */

//
// Created by aziabatz on 1/08/22.
//

#include <Library/Memory/Memory.hpp>
#include <Library/util.hpp>
#ifdef NZX_MEM_ALLOC
//TODO #include <memalloc.h>
#endif

#define MEM_ITERATION(start, end, code) for(UnsignedChar * byte = (UnsignedChar *) start; byte < ((UnsignedChar*)start+threshold); byte++){ \
    code                                                                                                                                    \
    }                                                                                                                                       \

Pointer Memory::findFirstOccurrence(const Pointer pointer, const UnsignedChar *searchingByte, Size threshold) {
    for(UnsignedChar * byte = (UnsignedChar *) pointer; byte < ((UnsignedChar*)pointer+threshold); byte++){
        if(*byte == *searchingByte){
            return byte;
        }
    }
    return nullptr;
}

Integer Memory::compareMemory(const Pointer left, const Pointer right, Size threshold) {
    UnsignedChar * byteL;
    UnsignedChar * byteR;
    for(byteL = (UnsignedChar *) left,byteR = (UnsignedChar *) right;
            byteL < ((UnsignedChar *)left + threshold);
            byteL++){
        if(*byteL < * byteR){
            return -1;
        }
        if(*byteL > *byteR){
            return 1;
        }
    }
    return 0;
}

Pointer Memory::setMemory(Pointer destination, char fillingByte, Size threshold) {
    for(UnsignedChar * byte = (UnsignedChar *) destination; byte < ((UnsignedChar*)destination+threshold); byte++){
        *byte = fillingByte;
    }
    return destination;
}

static const void * __unrestricted_memcpy(void * dest, void * src, unsigned int n){
    unsigned char * destination = static_cast<unsigned char *>(dest);
    unsigned char * source = static_cast<unsigned char *>(src);
    for(unsigned int c=0;c<n;c++){
        destination[c] = source[c];
    }
    return dest;
}

Pointer Memory::copyMemory(Pointer destination, const Pointer source, Size threshold) {
    //Are the same
    if(source == destination){
        return destination;
    }
    //check if overlap: if dest start or dest is in between src limits
    if(BETWEEN(destination, source, (UnsignedChar*)source+threshold) ||
        BETWEEN((UnsignedChar*)destination+threshold, source, (UnsignedChar*)source+threshold)){
        return nullptr;//overlap detected
    }
    /*for (Size byte = 0; byte < threshold; ++byte) {
        *((UnsignedChar*) destination+byte) = *((UnsignedChar*) source+byte);
    }*/
    __unrestricted_memcpy(destination, source, threshold);
    return destination;
}

Pointer Memory::copyMemoryWithOverlap(Pointer destination, const Pointer source, Size threshold) {

#ifdef NZX_MEM_ALLOC
    //TODO implement memory allocation
    UnsignedChar * tempBuffer;
#else
    //16-kbytes auxiliary byffer

    Integer bufferSize = 1024;
    Integer tempBuffer[bufferSize];

    /*
     * mientras no 16k ni threshold
     *  1a parte> copiar a buffer
     *  2a parte> copiar de buffer a dest
     */
    for(Size i=0; i<threshold;i+=bufferSize){
        //save to buffer
        __unrestricted_memcpy(tempBuffer, source, threshold);
        //restore to dest
        __unrestricted_memcpy(destination, tempBuffer, threshold);
    }
#endif
    return destination;
}

