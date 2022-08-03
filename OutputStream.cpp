//
// Created by aziabatz on 3/08/22.
//

#include "Library/Streams/OutputStream.hpp"


OutputStream::OutputStream(Integer id, char *streamName, UnsignedInteger buffer) : Stream(id, streamName) {

}

#ifndef __NXZ_USERLAND__
int OutputStream::write(char *buffer) {
    return 0;
}
#endif
