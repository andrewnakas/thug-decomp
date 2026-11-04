struct Cat_00206B60 {
    void* m_params;
    void* m_rot;
    void* m_pos;
};

extern "C" int func_00103F28(const char* fmt, ...);
extern "C" bool func_001E8248(void* s, unsigned int name, void** out, int required);
extern "C" bool func_001E8180(void* s, unsigned int name, void** out, int required);
extern "C" void* func_001E9378(void* arr, int i);
extern "C" void func_001E6AC8(void* dst, void* src);
extern "C" void func_001E66C0(void* dst, void* src);
extern "C" void func_001F0210(unsigned int name, void* params, int a, int b, int c);

extern char D_00366E88[];

struct Skater_00206B60 {
    char pad[0x248];
    Cat_00206B60* m_cats[11];
    void LoadCATInfo(void* params);
};

void Skater_00206B60::LoadCATInfo(void* params)
{
    func_00103F28(D_00366E88);
    void* arr = 0;
    func_001E8248(params, 0x1E26FD3E, &arr, 0);
    for (int i = 0; i < 11; i++) {
        void* s = func_001E9378(arr, i);
        void* p = 0;
        func_001E8180(s, 0x26A7CADF, &p, 1);
        func_001E6AC8(m_cats[i]->m_params, p);
        void* pos = 0;
        func_001E8248(s, 0x6B19FC8F, &pos, 1);
        func_001E66C0(m_cats[i]->m_pos, pos);
        void* rot = 0;
        func_001E8248(s, 0x2E628EE6, &rot, 1);
        func_001E66C0(m_cats[i]->m_rot, rot);
    }
    func_001F0210(0x33FE5817, 0, 0, 0, 0);
}
