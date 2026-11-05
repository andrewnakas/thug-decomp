extern int D_0038881C;
extern "C" int func_001092D0();
extern "C" int func_001092E0();
extern "C" int func_001094D0(const void* buf, int size, int count, void* f);
extern "C" int func_00110768(const void* buf, int size, int count, void* f);
extern "C" int func_00110260(const void* buf, int size, int count, void* f);
extern "C" int func_00111038(const void* buf, int size, int count, void* f)
{
    if (func_001092D0()) {
        int r = func_001094D0(buf, size, count, f);
        if (func_001092E0()) {
            return r;
        }
    }
    if (D_0038881C) {
        return func_00110260(buf, size, count, f);
    }
    return func_00110768(buf, size, count, f);
}
