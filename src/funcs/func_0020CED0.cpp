struct Array_0020CED0 {
    int m0;
    int m4;
    int m8;
    unsigned int mC;
};

extern "C" bool func_001E8248(void* params, unsigned int name, Array_0020CED0** out, int required);
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" unsigned int func_001E9300(Array_0020CED0* a, unsigned int i);
extern "C" int func_0020CEC8(unsigned int name);

bool Cmd_0020CED0(void* params, void* script)
{
    Array_0020CED0* arr = 0;
    unsigned int name;
    if (func_001E8248(params, 0, &arr, 0)) {
        unsigned int i = 0;
        if (arr->mC) {
            do {
                if (func_0020CEC8(func_001E9300(arr, i))) return true;
                i++;
            } while (i < arr->mC);
        }
    }
    name = 0;
    if (func_001E8398(params, 0, &name, 0)) {
        if (func_0020CEC8(name)) return true;
    }
    return false;
}
