/*
 * Simple.cpp
 *
 *  Created on: Sep 27, 2018
 *      Author: ipas
 */

#include "SimpleArray.h"

/**
 * Constructors / Destructor
 */
template <class T, class SZ>
SimpleArray<T, SZ>::SimpleArray(SZ initSize) {
    bufferLength = 0;
    bufferSize   = initSize;
    buffer       = new T[bufferSize];
}

template <class T, class SZ>
SimpleArray<T, SZ>::~SimpleArray() {
    delete[] buffer;
}

/**
 * Accessing / Properties
 */
template <class T, class SZ>
SZ SimpleArray<T, SZ>::length(void) {
    return bufferLength;
}

template <class T, class SZ>
SZ SimpleArray<T, SZ>::size() {
    return bufferSize;
}

template <class T, class SZ>
T SimpleArray<T, SZ>::operator [](SZ index) {
    return buffer[index];
}

/**
 * Comparators
 */
template <class T, class SZ>
int SimpleArray<T, SZ>::compare(SimpleArray<T, SZ> & arr) {
    SZ i;
    for (i = 0; i < bufferLength && i < arr.length(); i++) {
        if (buffer[i] != arr[i])
            break;
    }
    if (bufferLength >= arr.length())
        return bufferLength - i;  // How many items left, NOT be compared nor equal
    else
        return arr.length() - i;
}

template <class T, class SZ>
bool SimpleArray<T, SZ>::operator ==(SimpleArray<T, SZ> & arr) {
    return ((bufferLength == arr.length()) && (compare(arr) == 0));
}

template <class T, class SZ>
bool SimpleArray<T, SZ>::operator !=(SimpleArray<T, SZ> & arr) {
    return !(*this == arr);
}

/**
 * Manipulators
 */
template <class T, class SZ>
SZ SimpleArray<T, SZ>::append(T item) {
    if (bufferLength < bufferSize) {
        buffer[bufferLength++] = item;
        return 1;
    }
    return 0;
}

template <class T, class SZ>
SZ SimpleArray<T, SZ>::append(SimpleArray<T, SZ> & array) {
    SZ cnt = 0;
    for (SZ i = 0; i < array.length() && i < bufferSize; i++) {
        cnt += append(array[i]);  // TODO: break after full.
    }
    return cnt;
}

template <class T, class SZ>
SZ SimpleArray<T, SZ>::remove(SZ index, SZ count) {
    if (index >= bufferLength)
        return 0;
    if (index+count >= bufferLength)
        count = bufferLength - index;

    T * tmp = new T[bufferSize];
    SZ i, j = 0;
    for (i = 0; i < index; i++, j++) {
        tmp[j] = buffer[i];
    }
    for (i = index+count; i < bufferLength; i++, j++) {
        tmp[j] = buffer[i];
    }
    delete[] buffer;
    buffer = tmp;
    bufferLength = j;
    return count;
}

template <class T, class SZ>
void SimpleArray<T, SZ>::clear() {
    bufferLength = 0;
}