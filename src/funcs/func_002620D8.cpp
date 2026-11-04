struct Array_002620D8 {
    int m_pad[3];
    int m_size;
};

struct Info_002620D8 {
    int m_0;
    unsigned int m_a;
    unsigned int m_b;
    int m_flag;
};

extern void* D_0038FC78;

extern "C" bool func_001E8A80(void* s, unsigned int name, Array_002620D8** out, int required);
extern "C" void* func_001E9378(Array_002620D8* a, int index);
extern "C" int func_00264738(Info_002620D8* info);
extern "C" void func_001E7A68(void* s, unsigned int name, int type, unsigned int value);
extern "C" void func_001E7200(void* s, unsigned int name, int value);
extern "C" void func_001E6B90(void* s, unsigned int name);
extern "C" void* func_0022DD38(void* mgr);
extern "C" void* func_00185578(void* obj, unsigned int id);
extern "C" void func_001F0210(unsigned int name, int a, int b, int c, int d);

struct Goal_002620D8 {
    bool SetEntry(int index, Info_002620D8* info, int notify);
};

extern "C" void* func_00262358(Goal_002620D8* self);
extern "C" void func_001AB7C0(void* comp, Goal_002620D8* goal);

bool Goal_002620D8::SetEntry(int index, Info_002620D8* info, int notify)
{
    Array_002620D8* arr;
    func_001E8A80(func_00262358(this), 0, &arr, 1);
    if (index < 0 || index >= arr->m_size)
        return false;
    unsigned int a = info->m_a;
    unsigned int b = info->m_b;
    if (func_00264738(info)) {
        a = 0xF60C9090;
        b = 0xF60C9090;
    }
    void* s = func_001E9378(arr, index);
    func_001E7A68(s, 0x5B077CE1, 0xD, a);
    func_001E7A68(s, 0xA92A2280, 0xD, b);
    if (info->m_flag)
        func_001E7200(s, 0xB56A8816, 1);
    else
        func_001E6B90(s, 0xB56A8816);
    if (notify) {
        void* skater = func_0022DD38(D_0038FC78);
        if (skater)
            func_001AB7C0(func_00185578(skater, 0x270F56E1), this);
    }
    func_001F0210(0xFAB5C6EB, 0, 0, 0, 0);
    return true;
}
