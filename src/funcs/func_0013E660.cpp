struct S_0013E660 {
    unsigned char r, g, b, a;
};

struct A_0013E660 {
    char m_pad0[0xC];
    unsigned int m_size;
    unsigned int GetSize() const { return m_size; }
};

extern "C" short func_0013E9D8(void* self);
extern "C" int func_0013CA70(void* p);
extern "C" void func_0013C478(void* p);
extern "C" int func_0013C4D8(void* p, int a, int b, const S_0013E660& c);
extern "C" bool func_001E8398(void* params, int name, int* out, int required);
extern "C" bool func_001E7DE8(void* params, int name, int* out, int required);
extern "C" bool func_001E8248(void* params, int name, A_0013E660** out, int required);
extern "C" void* func_001E9378(A_0013E660* arr, int i);
extern "C" int func_001E9270(A_0013E660* arr, int i);

class C_0013E660 {
public:
    char m_pad0[0x10];
    void* m_items[36];
    int m_keys[18];
    int Trigger(void* params);
};

int C_0013E660::Trigger(void* params)
{
    int id;
    int result = 0;
    func_001E8398(params, 0xB6F08F39, &id, 1);
    bool any = (id == (int)0xC4E78E22);
    int n = func_0013E9D8(this);
    for (int i = 0; i < n; i++) {
        int b2 = 0;
        if (!func_0013CA70(m_items[i])) {
            if (id == m_keys[i] || any) {
                func_0013C478(m_items[i]);
                result = 1;
            }
        } else {
            A_0013E660* arr;
            int a2;
            S_0013E660 c;
            S_0013E660 t1;
            S_0013E660 t;
            if (func_001E8248(params, 0x64E8E94A, &arr, 0)) {
                c.r = 0x80;
                c.g = 0x80;
                c.b = 0x80;
                c.a = 0x80;
                for (unsigned int j = 0; j < arr->GetSize(); j++) {
                    void* e = func_001E9378(arr, j);
                    func_001E8398(e, 0, &a2, 1);
                    func_001E7DE8(e, 0, &b2, 1);
                    t1 = c;
                    result |= func_0013C4D8(m_items[i], a2, b2, t1) != 0;
                }
            } else if (func_001E8398(params, 0x83418A6A, &a2, 0)) {
                c.r = 0x80;
                c.g = 0x80;
                c.b = 0x80;
                c.a = 0x80;
                A_0013E660* arr2;
                if (func_001E8248(params, 0x318F2BDB, &arr2, 0)) {
                    for (unsigned int j = 0; j < arr2->GetSize(); j++) {
                        t = c;
                        result |= func_0013C4D8(m_items[i], a2, func_001E9270(arr2, j), t) != 0;
                    }
                } else if (func_001E7DE8(params, 0x318F2BDB, &b2, 1)) {
                    t = c;
                    result |= func_0013C4D8(m_items[i], a2, b2, t) != 0;
                }
            }
        }
        if ((id == 0x650FAB6D || id == 0x0FC85BAE) && m_keys[i] == 0x2457F44D) {
            result = 1;
            func_0013C478(m_items[i]);
        }
    }
    return result;
}
