/*
 * ResStream
 *
 * Original file: ResStream.cpp
 * Area:          world
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of ResStream.cpp here, in the order they appear in the library.
 */

#include "ResStream.h"
#include "../persistence/FileStream.h"

ResStream::ResStream(int mode) {}
ResStream::ResStream() {}

ResStream::ResStream(const char* name, int mode)
{
    int size;
    void* buffer = FileStream::Load(name, &size);
    Open(mode, size, buffer);
    unknown1053 = true;
}
ResStream::~ResStream()
{
    Close();
    char* d = data;
    if (d) {
        // No-op write-back of the just-loaded pointer (no behaviour change). The store
        // reuses the 1036 offset pseudo inside the delete block, making it global, so
        // only two block-local quantities remain and local-alloc sorts them correctly
        // (retail: PIC base r2, vtable r3); postreload deletes the store as a no-op.
        data = d;
        delete[] d;
    }
}
