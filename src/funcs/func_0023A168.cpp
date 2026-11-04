extern "C" void* func_001E5548(unsigned int key, int create);
extern "C" bool func_001E8180(void* params, unsigned int key, void** out, int required);
extern "C" bool func_001E8398(void* params, unsigned int key, unsigned int* out, int required);
extern "C" void* func_001E55B8(unsigned int key, int a);
extern "C" void* func_001E9378(void* a, int i);
extern "C" bool func_001E7D70(void* params, unsigned int key, char** out, int required);
extern "C" unsigned int func_001F0D78(const char* s);
extern "C" void func_00239A18(void* obj, unsigned int key, int a, int b);

void func_0023A168(void* obj, unsigned int key, int a, int b, int depth)
{
    if (depth > 1) {
        void* p;
        unsigned int k;
        char* s;
        int i = depth;
        func_001E8180(func_001E5548(key, 1), 0x7031F10C, &p, 1);
        for (; i > 1; i--) {
            func_001E8398(p, 0x6E855102, &k, 0);
            func_001E8180(func_001E9378(func_001E55B8(k, 1), 0), 0x7031F10C, &p, 1);
        }
        func_001E7D70(p, 0xA1DC81F9, &s, 1);
        key = func_001F0D78(s);
    }
    func_00239A18(obj, key, a, b);
}
