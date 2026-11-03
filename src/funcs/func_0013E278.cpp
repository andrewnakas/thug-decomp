struct S_0013E278 {
    unsigned char r, g, b, a;
};

struct A_0013E278 {
    char m_pad0[0xC];
    unsigned int m_size;
    unsigned int GetSize() const { return m_size; }
};

extern "C" short func_0013E9D8(void* self);
extern "C" int func_0013CA70(void* p);
extern "C" void func_00131178(float h, float s, float v, float* r, float* g, float* b);
extern "C" void func_0013C438(void* p, const S_0013E278& c);
extern "C" int func_0013C4D8(void* p, int a, int b, const S_0013E278& c);
extern "C" bool func_001E8398(void* params, int name, int* out, int required);
extern "C" bool func_001E7DE8(void* params, int name, int* out, int required);
extern "C" bool func_001E8248(void* params, int name, A_0013E278** out, int required);
extern "C" void* func_001E9378(A_0013E278* arr, int i);
extern "C" bool func_0013DEA0(void* self, int key, float h, float s, float v);
extern "C" int func_001E9270(A_0013E278* arr, int i);

class C_0013E278 {
public:
    char m_pad0[0x10];
    void* m_items[36];
    int m_keys[18];
    int SetColour(void* params, float h, float s, float v);
};

int C_0013E278::SetColour(void* params, float h, float s, float v)
{
    int id;
    int result = 0;
    func_001E8398(params, 0xB6F08F39, &id, 1);
    float r, g, b;
    func_00131178(h, s, v, &r, &g, &b);
    S_0013E278 c;
    c.a = 0xFF;
    c.r = (int)(r * 255.0f + 0.5f);
    c.g = (int)(g * 255.0f + 0.5f);
    c.b = (int)(b * 255.0f + 0.5f);
    bool any = (id == (int)0xC4E78E22);
    int n = func_0013E9D8(this);
    for (int i = 0; i < n; i++) {
        int b2 = 0;
        if (!func_0013CA70(m_items[i])) {
            if (id == m_keys[i] || any) {
                S_0013E278 t = c;
                func_0013C438(m_items[i], t);
                result = 1;
            }
        } else {
            A_0013E278* arr;
            int a2;
            if (func_001E8248(params, 0x64E8E94A, &arr, 0)) {
                for (unsigned int j = 0; j < arr->GetSize(); j++) {
                    void* e = func_001E9378(arr, j);
                    func_001E8398(e, 0, &a2, 1);
                    func_001E7DE8(e, 0, &b2, 1);
                    S_0013E278 t = c;
                    result |= func_0013C4D8(m_items[i], a2, b2, t) != 0;
                }
            } else if (func_001E8398(params, 0x83418A6A, &a2, 0)) {
                A_0013E278* arr2;
                if (func_001E8248(params, 0x318F2BDB, &arr2, 0)) {
                    for (unsigned int j = 0; j < arr2->m_size; j++) {
                        S_0013E278 t = c;
                        result |= func_0013C4D8(m_items[i], a2, func_001E9270(arr2, j), t) != 0;
                    }
                } else if (func_001E7DE8(params, 0x318F2BDB, &b2, 1)) {
                    S_0013E278 t = c;
                    result |= func_0013C4D8(m_items[i], a2, b2, t) != 0;
                }
            }
        }
        if ((id == 0x650FAB6D || id == 0x0FC85BAE) && m_keys[i] == 0x2457F44D) {
            func_0013DEA0(this, 0x2457F44D, h, s, v);
        }
    }
    return result;
}
