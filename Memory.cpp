//
// Created by aziabatz on 1/08/22.
//

#include <cstddef>
#include <iostream>
#include "Library/Memory/Memory.hpp"
#include "Library/util.hpp"
#ifdef NZX_MEM_ALLOC
//TODO #include <memalloc.h>
#endif

#define MEM_ITERATION(start, end, code) for(UnsignedChar * byte = (UnsignedChar *) start; byte < ((UnsignedChar*)start+threshold); byte++){ \
    code                                                                                                                                    \
    }                                                                                                                                       \

const Pointer Memory::findFirstOccurrence(const Pointer pointer, const UnsignedChar *searchingByte, Size threshold) {
    for(UnsignedChar * byte = (UnsignedChar *) pointer; byte < ((UnsignedChar*)pointer+threshold); byte++){
        if(*byte == *searchingByte){
            return byte;
        }
    }
    return nullptr;
}

const Integer Memory::compareMemory(const Pointer left, const Pointer right, Size threshold) {
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

const Pointer Memory::setMemory(Pointer destination, char fillingByte, Size threshold) {
    for(UnsignedChar * byte = (UnsignedChar *) destination; byte < ((UnsignedChar*)destination+threshold); byte++){
        *byte = fillingByte;
    }
    return destination;
}

static const void * __unrestricted_memcpy(void * dest, void * src, unsigned int n){
    unsigned char * destination = static_cast<unsigned char *>(dest);
    unsigned char * source = static_cast<unsigned char *>(src);
    for(int c=0;c<n;c++){
        destination[c] = source[c];
    }
    return dest;
}

const Pointer Memory::copyMemory(Pointer destination, const Pointer source, Size threshold) {
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

const Pointer Memory::copyMemoryWithOverlap(Pointer destination, const Pointer source, Size threshold) {
    UnsignedChar * tempBuffer;
#ifdef NZX_MEM_ALLOC
    //TODO implement memory allocation
#else
    //16-kbytes auxiliary byffer

    int bufferSize;
    tempBuffer[bufferSize];

    /*
     * mientras no 16k ni threshold
     *  1a parte> copiar a buffer
     *  2a parte> copiar de buffer a dest
     */
    for(int i=0; i<threshold;i+=bufferSize){
        //save to buffer
        __unrestricted_memcpy(tempBuffer, source, threshold);
        //restore to dest
        __unrestricted_memcpy(destination, tempBuffer, threshold);
    }
#endif
    return destination;
}

