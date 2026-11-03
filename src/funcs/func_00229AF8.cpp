extern char D_0038FB58[];

struct Array_00229AF8 {
    char pad[0xC];
    unsigned int m_size;
};

extern "C" void func_00229AD0();
extern "C" void func_00229828();
extern "C" void func_002298D0();
extern "C" void func_00229890();
extern "C" Array_00229AF8* func_001E55B8(unsigned int key, int a);
extern "C" void* func_001E9378(Array_00229AF8* a, unsigned int i);
extern "C" bool func_001E84E8(void* params, char* name, unsigned int* out, int required);
extern "C" char* func_001ED9D8(unsigned int key);
extern "C" int func_00331BB8(const char* s);
extern "C" unsigned int func_00105488(const char* s, int len);
extern "C" void func_00229998(unsigned int key, int val);

void func_00229AF8()
{
    func_00229AD0();
    func_00229828();
    Array_00229AF8* arr = func_001E55B8(0xC472ECC5, 0);
    for (unsigned int i = 0; i < arr->m_size; i++) {
        void* e = func_001E9378(arr, i);
        unsigned int key = 0;
        func_001E84E8(e, D_0038FB58, &key, 0);
        if (key) {
            char* name = func_001ED9D8(key);
            if (name) {
                int len = func_00331BB8(name);
                for (int j = 1; j <= len; j++)
                    func_00229998(func_00105488(name, j), i);
            }
        }
    }
    func_002298D0();
    func_00229890();
}
