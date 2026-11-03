extern "C" int func_001E8398(void* params, unsigned int name, unsigned int* out, int req);
extern "C" int func_001E7DE8(void* params, unsigned int name, int* out, int req);

struct Obj_0019EB00 {
    int m_pad[4];
    int m10;
};

struct C_0019EB00 {
    int m_pad[7];
    Obj_0019EB00* m1C;
    void Init(void* params);
};

extern "C" void func_0019EA00(C_0019EB00* self, unsigned int id);

void C_0019EB00::Init(void* params)
{
    unsigned int id;
    if (!func_001E8398(params, 0x222756D5, &id, 0)) func_001E8398(params, 0x09794932, &id, 1);
    func_0019EA00(this, id);
    int v;
    if (func_001E7DE8(params, 0xD3982061, &v, 0) && m1C) m1C->m10 = v;
}
