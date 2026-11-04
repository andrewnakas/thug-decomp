extern "C" void* func_001A0718(void* a);
extern "C" void func_00119770(void* o, int* a, int* b, int* c);

extern "C" void func_001A0E50(void* a, int* x, int* y, int* z)
{
    *x = 0;
    *y = 0;
    *z = 0;
    if (func_001A0718(a)) {
        func_00119770(func_001A0718(a), x, y, z);
    }
}
