struct Array_00184758 {
    char pad0[0xC];
    unsigned int m_count;
    unsigned int GetSize() { return m_count; }
};

extern "C" int func_001E8248(void* params, const char* name, Array_00184758** out, int required);
extern "C" int func_001E7DE8(void* params, const char* name, int* out, int required);
extern "C" int func_001E9300(Array_00184758* a, unsigned int i);
extern "C" int func_001E53A0(int id, int a);

class Obj_00184758 {
public:
    unsigned int GetMask(void* params);
};

unsigned int Obj_00184758::GetMask(void* params)
{
    int v = 0;
    Array_00184758* arr = 0;
    unsigned int mask = 0;
    func_001E8248(params, 0, &arr, 0);
    if (arr) {
        for (unsigned int i = 0; i < arr->GetSize(); i++) {
            mask |= 1 << func_001E53A0(func_001E9300(arr, i), 0);
        }
        return mask;
    }
    if (func_001E7DE8(params, 0, &v, 0)) {
        mask = 1 << v;
    }
    return mask;
}
