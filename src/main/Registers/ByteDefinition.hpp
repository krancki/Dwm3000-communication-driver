#pragma once

struct ByteDefinition
{
    int index;
    int size;

    ByteDefinition(int _index, int _size)
    {
        index = _index;
        size = _size;
    }
};