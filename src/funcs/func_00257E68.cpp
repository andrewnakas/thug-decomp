struct Array_00257E68 {
    int m0;
    int m4;
    int m8;
    unsigned int mC;
};

extern "C" bool func_001E7EB0(void* params, unsigned int name, float* out, int required);
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" bool func_001E8248(void* params, unsigned int name, Array_00257E68** out, int required);
extern "C" bool func_001E8870(void* params, unsigned int name, void** out, int required);
extern "C" unsigned int func_001E9300(Array_00257E68* a, unsigned int i);
extern "C" bool func_00257CA0(void* self, void* params, int a, int b, float r, unsigned int name);
extern "C" int func_00229668(unsigned int id, int a);
extern "C" bool func_00256E10(void* self, int id, int r, int b);
extern "C" unsigned short* func_00229C98(void* p, unsigned short* n);

extern "C" bool func_00257E68(void* self, void* params, int a, int b)
{
    unsigned short n;
    float r = 0.0f;
    unsigned int name;
    Array_00257E68* arr;
    unsigned int id;
    void* grp;
    unsigned short* list;
    if (!b) {
        if (!func_001E7EB0(params, 0xC48391A5, &r, 0)) return false;
        r = r * 12.0f;
        r = r * r;
    }
    arr = 0;
    if (func_001E8398(params, 0x7321A8D6, &name, 0)) {
        return func_00257CA0(self, params, a, b, r, name);
    }
    if (func_001E8248(params, 0x7321A8D6, &arr, 1)) {
        unsigned int i = 0;
        if (!arr->mC) return false;
        do {
            if (func_00257CA0(self, params, a, b, r, func_001E9300(arr, i))) goto found;
            i++;
        } while (i < arr->mC);
        return false;
    }
    if (func_001E8398(params, 0xA1DC81F9, &id, 0)) {
        return func_00256E10(self, func_00229668(id, 1), (int)r, b);
    }
    if (func_001E8870(params, 0x6C4E7971, &grp, 0)) {
        n = 0;
        list = func_00229C98(grp, &n);
        for (int j = 0; j < n; j++) {
            if (func_00256E10(self, list[j], (int)r, b)) goto found;
        }
        return false;
    found:
        return true;
    }
    return false;
}
