struct Array_00218EE8 {
    int m0;
    int m4;
    int m8;
    unsigned int mC;
};

extern "C" bool func_001E8248(void* params, unsigned int name, Array_00218EE8** out, int required);
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" unsigned int func_001E9300(Array_00218EE8* a, unsigned int i);
extern "C" int func_0020CF90(unsigned int name);

bool Cmd_00218EE8(void* params, void* script)
{
    Array_00218EE8* arr = 0;
    unsigned int name;
    if (func_001E8248(params, 0, &arr, 0)) {
        unsigned int i = 0;
        if (arr->mC) {
            do {
                if (func_0020CF90(func_001E9300(arr, i))) return true;
                i++;
            } while (i < arr->mC);
        }
    }
    name = 0;
    if (func_001E8398(params, 0, &name, 0)) {
        if (func_0020CF90(name)) return true;
    }
    return false;
}
