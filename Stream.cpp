//
// Created by aziabatz on 31/07/22.
//

#include "Library/Streams/Stream.hpp"

Stream::Stream(Integer ID, char *streamName) {
    this->ID = ID;
    //todo memcpy name
}

Integer Stream::getId() const {
    return ID;
}

const char *Stream::getStreamName() const {
    return streamName;
}
