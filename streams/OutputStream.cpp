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
// Created by aziabatz on 3/08/22.
//

#include <Library/Streams/OutputStream.hpp>


OutputStream::OutputStream(Integer id, char *streamName, UnsignedChar type) : Stream(id, streamName) {
    this->bufferType = type;
}

OutputStream * OutputStream::operator<<(const Char character){
    return this;
}

OutputStream * OutputStream::operator<<(const Integer integer){

    return this;
}

OutputStream * OutputStream::operator<<(const Char * string){
    return this;
}

OutputStream * OutputStream::operator<<(const Hexadecimal hex){
    return this;
}

#ifndef __NXZ_USERLAND__
int OutputStream::write(char *buffer) {
    return 0;
}
#endif

//todo implement ostream