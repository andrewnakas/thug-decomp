extern "C" int func_001180C8(void* self);
extern "C" void* func_001180D0(void* self, int i);
extern "C" void func_00118348(void* item, int on);

extern "C" int func_001180E8(void* self)
{
    int n = func_001180C8(self);
    for (int i = 0; i < n; i++) {
        func_00118348(func_001180D0(self, i), 1);
    }
    return 1;
}
