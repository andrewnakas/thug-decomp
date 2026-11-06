struct Arr_00123350 {
    char pad[0xC];
    unsigned int m_size;
    unsigned int GetSize() { return m_size; }
};

struct Sub_00123350 {
    int m0;
};

extern "C" int func_001E8248(void* params, unsigned int name, Arr_00123350** out, int req);
extern "C" unsigned int func_001E9300(Arr_00123350* a, unsigned int i);
extern "C" int func_001E7C80(void* params, unsigned int name, const char** out, int req);
extern "C" char* func_00331A9C(char* dst, const char* src);
extern "C" void func_001228A8(Sub_00123350* s, void* params);

class Obj_00123350 {
public:
    int m0;
    int m4;
    Sub_00123350 m8;
    char padC[0x40 - 0xC];
    unsigned int m_ids[(0x4460 - 0x40) / 4];
    char m_name[0x20];
    void Init(void* params);
};

void Obj_00123350::Init(void* params)
{
    Arr_00123350* a;
    unsigned int i = 0;
    unsigned int* p = m_ids;
    func_001E8248(params, 0x99790D96, &a, 1);
    for (; i < a->GetSize(); i++) {
        *p++ = func_001E9300(a, i);
    }
    const char* name;
    func_001E7C80(params, 0xA7E7A264, &name, 1);
    func_00331A9C(m_name, name);
    func_001228A8(&m8, params);
}
