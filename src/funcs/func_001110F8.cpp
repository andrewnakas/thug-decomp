extern int D_0038881C;
extern "C" int func_001092D0();
extern "C" int func_001092E0();
extern "C" int func_001094F8(void* f, int offset, int whence);
extern "C" int func_001107F8(void* f, int offset, int whence);
extern "C" int func_00110280(void* f, int offset, int whence);
extern "C" int func_001110F8(void* f, int offset, int whence)
{
    if (func_001092D0()) {
        int r = func_001094F8(f, offset, whence);
        if (func_001092E0()) {
            return r;
        }
    }
    if (D_0038881C) {
        return func_00110280(f, offset, whence);
    }
    return func_001107F8(f, offset, whence);
}
