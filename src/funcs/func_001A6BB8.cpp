extern "C" void* func_00229DF0(void* e);
extern "C" int func_001E8398(void* params, unsigned int name, unsigned int* out, int req);
extern "C" int func_001E8180(void* params, unsigned int name, void** out, int req);
extern "C" void func_00184B30(void* obj, unsigned int id, void* params, int a, int b);
extern "C" void func_00184AB0(void* obj, unsigned int id, void* params);

struct C_001A6BB8 {
    int m_pad[3];
    void* mC;
    int m10[130];
    void* m218;
    void Enter(void* e);
};

void C_001A6BB8::Enter(void* e)
{
    void* p = func_00229DF0(e);
    unsigned int id;
    m218 = e;
    if (func_001E8398(p, 0x3AEFE377, &id, 0)) {
        void* w = 0;
        func_001E8180(p, 0x7031F10C, &w, 0);
        func_00184B30(mC, id, w, 0, 0);
    } else if (func_001E8398(p, 0x86125749, &id, 0)) {
        void* w2 = 0;
        func_001E8180(p, 0x7031F10C, &w2, 0);
        func_00184AB0(mC, id, w2);
    }
}
