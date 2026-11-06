extern "C" int func_0025F0F0(void* o);
extern "C" void* func_0025F128(void* o, int i);
extern "C" int func_0025AB70(void* p);

extern "C" void* func_0025F1C8(void* o, int id)
{
    for (int i = 0; i < func_0025F0F0(o); i++) {
        void* p = func_0025F128(o, i);
        if (func_0025AB70(p) == id)
            return p;
    }
    return 0;
}
