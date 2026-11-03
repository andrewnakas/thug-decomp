struct Array_0020B728 {
    int m0;
    int m4;
    int m8;
    int m_size;
};

struct Script_0020B728 {
    char m_pad[0x18];
    void* m_params;
};

extern char D_0036FEC0[];

extern "C" bool func_001E8248(void* params, unsigned int name, Array_0020B728** out, int required);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" Array_0020B728* func_001E93A0(Array_0020B728* array, int index);
extern "C" void func_001E7268(void* params, const char* name, int value);

bool func_0020B728(void* params, Script_0020B728* script)
{
    Array_0020B728* array;
    func_001E8248(params, 0, &array, 1);
    int index = 0;
    if (func_001E7DE8(params, 0x0BA453B9, &index, 0)) {
        array = func_001E93A0(array, index);
        if (func_001E7DE8(params, 0x92AD0203, &index, 0)) {
            array = func_001E93A0(array, index);
            if (func_001E7DE8(params, 0xE5AA3295, &index, 0)) {
                array = func_001E93A0(array, index);
            }
        }
    }
    func_001E7268(script->m_params, D_0036FEC0, array->m_size);
    return true;
}
