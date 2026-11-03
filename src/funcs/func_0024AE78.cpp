extern char D_00373F58[];
extern char D_00373F70[];
extern void* D_0038FC78;

struct Goal_0024AE78 {
    char pad[0x20];
    void* m_params;
    char pad24[0x88];
    int m_AC;
    char padB0[0x14];
    int m_challenge;
    int m_C8;
};

extern "C" void* func_0024AD70();
extern "C" void* func_00240850();
extern "C" void* func_0023BAD8(void* a, int b, int c);
extern "C" void* func_00244528(void* a);
extern "C" bool func_001E7DE8(void* params, unsigned int key, int* out, int required);
extern "C" void func_001E6B90(void* params, unsigned int key);
extern "C" void func_001E7200(void* params, unsigned int key, int value);
extern "C" int func_00103F28(const char* fmt, ...);
extern "C" void func_001E6C28(void* params, char* name);
extern "C" bool func_001E8708(void* params, unsigned int key);
extern "C" bool func_001E8248(void* params, unsigned int key, void** out, int required);
extern "C" int func_00245FB8(Goal_0024AE78* g, void* arr);
extern "C" unsigned int func_001E9300(void* arr, int i);
extern "C" void* func_0022E368(void* mgr, int a);
extern "C" void* func_00262330(void* a, unsigned int key);
extern "C" bool func_001E8398(void* params, unsigned int key, unsigned int* out, int required);
extern "C" void* func_001E5548(unsigned int key, int create);
extern "C" bool func_001E8180(void* params, unsigned int key, void** out, int required);
extern "C" bool func_001E88B0(void* params, unsigned int key, char** out, int required);
extern "C" void func_001E70C0(void* params, unsigned int key, char* value);
extern "C" bool func_001E7C80(void* params, unsigned int key, char** out, int required);

void func_0024AE78(Goal_0024AE78* goal)
{
    void* params = func_0024AD70();
    void* info = func_00244528(func_0023BAD8(func_00240850(), goal->m_AC, 1));
    func_001E7DE8(params, 0x1D7750FA, &goal->m_C8, 1);
    func_001E6B90(goal->m_params, 0x1D7750FA);
    func_001E7200(goal->m_params, 0x1D7750FA, goal->m_C8);
    func_001E6B90(goal->m_params, 0xF3D0C702);
    if (func_001E7DE8(params, 0x1931AC3B, &goal->m_challenge, 0)) {
        func_00103F28(D_00373F58, goal->m_challenge);
        func_001E7200(goal->m_params, 0xF3D0C702, goal->m_challenge);
    }
    int tries;
    func_001E7DE8(params, 0x62396931, &tries, 1);
    func_001E6C28(goal->m_params, D_00373F70);
    func_001E7200(goal->m_params, 0x25BAD847, tries);
    func_001E6B90(goal->m_params, 0x06922090);
    func_001E6B90(goal->m_params, 0xD41AAC2A);
    func_001E6B90(goal->m_params, 0xA1617634);
    if (func_001E8708(info, 0xBC167894)) {
        void* arr;
        func_001E8248(params, 0x79704516, &arr, 1);
        int idx = func_00245FB8(goal, arr);
        unsigned int key = func_001E9300(arr, idx);
        unsigned int name;
        func_001E8398(func_00262330(func_0022E368(D_0038FC78, 0), 0xD544AA2D), key, &name, 1);
        char* text;
        if (name) {
            void* p;
            func_001E8180(func_001E5548(name, 1), 0x7031F10C, &p, 1);
            func_001E88B0(p, 0xA1DC81F9, &text, 1);
        }
        func_001E70C0(goal->m_params, 0xD41AAC2A, text);
        char* s;
        func_001E7C80(info, 0xA1617634, &s, 1);
        func_001E70C0(goal->m_params, 0xA1617634, s);
    } else {
        char* a;
        func_001E7C80(info, 0xD41AAC2A, &a, 1);
        func_001E70C0(goal->m_params, 0xD41AAC2A, a);
        char* b;
        func_001E7C80(info, 0x06922090, &b, 1);
        func_001E70C0(goal->m_params, 0x06922090, b);
    }
}
