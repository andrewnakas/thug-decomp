extern "C" int func_001E8618(void* params, unsigned int name);
extern "C" int func_001E8398(void* params, unsigned int name, unsigned int* out, int req);
extern "C" void* func_00187B48(void* mgr, unsigned int id);
extern "C" void* func_00185578(void* obj, unsigned int name);
extern "C" int func_001E7EB0(void* params, unsigned int name, float* out, int req);
extern void* D_0038C608;

struct C_0019CBE8 {
    int m_pad[7];
    void* m1C;
    void* m20;
    int m_pad2[31];
    float mA0;
    float mA4;
    float mA8;
    float mAC;
    void InitFromParams(void* params);
};

void C_0019CBE8::InitFromParams(void* params)
{
    if (func_001E8618(params, 0x0431C185)) {
        unsigned int id;
        func_001E8398(params, 0x0431C185, &id, 1);
        m1C = func_00187B48(D_0038C608, id);
        m20 = func_00185578(m1C, 0xE47F1B79);
    }
    func_001E7EB0(params, 0x9213625F, &mAC, 0);
    func_001E7EB0(params, 0x14849B6D, &mA0, 0);
    func_001E7EB0(params, 0xBD3D3CA9, &mA4, 0);
    func_001E7EB0(params, 0xFF7EBAF6, &mA8, 0);
}
