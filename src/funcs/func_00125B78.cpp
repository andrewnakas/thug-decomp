struct Col_00125B78 {
    unsigned char r, g, b, a;
};

struct Arr_00125B78 {
    char pad[0xC];
    int m_size;
};

extern "C" int func_001E8248(void* params, unsigned int name, Arr_00125B78** out, int required);
extern "C" int func_001E9270(Arr_00125B78* arr, int i);

extern "C" int func_00125B78(void* self, void* params, unsigned int name, Col_00125B78* out)
{
    Arr_00125B78* arr;
    unsigned int c;
    if (func_001E8248(params, name, &arr, 0)) {
        c = 0;
        int n = arr->m_size;
        for (int i = 0; i < n; i++) {
            c |= (func_001E9270(arr, i) & 0xFF) << (i * 8);
        }
        *out = *(Col_00125B78*)&c;
        return 1;
    }
    return 0;
}
