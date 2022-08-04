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

#include <Library/String.hpp>

namespace str=String;

Integer str::integerToString(Integer integer, str::String string){
    Integer i, sign=false;

    if(integer < 0){
        sign = true;
        integer = -integer;//we need the absolute value
    }

    i = 0;
    do{
        /*The modulo 10th of a number(the rest of the div)
         * will tell us the digit from right(lesser) to left(greater)
         *
         * For example(conversion of "12"):
         *
         * The first modulo 12 % 10 will give us 2 thus the first character in
         * the string shall be '2'.
         * In the next iteration(see while condition below) we discard the digit 2
         * by dividing by 10. This is:
         * 12/10 = 1(rest 2 is discarded as we are dividing integers)
         * Then we do the same until we finish the whole number
         *
         * */
        string[i++] = (integer%10) + '0';
        //division will discard the computed digit to go for the next
    }while((integer/=10)>0);

    if(sign<0){
        string[i++] = '-';
    }

    string[i++] = '\0';

    str::reverseString(string);

    return i;
}