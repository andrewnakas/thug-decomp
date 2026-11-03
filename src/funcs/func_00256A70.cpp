struct Comp_00256A70 {
    int m_data[6];
    virtual void V0();
    virtual void V1();
    virtual void V2(void* params);
};

extern "C" Comp_00256A70* func_00185578(void* obj, unsigned int id);
extern "C" void func_002569A8(void* obj);
extern "C" void func_001A8210(Comp_00256A70* c, void* params);
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" bool func_001E8180(void* params, unsigned int name, int* out, int required);
extern "C" void func_00183E90(void* obj, unsigned int v);
extern "C" void func_00184AB0(void* obj, unsigned int a, int b);

struct Obj_00256A70 {
    void InitFromStructure(void* params);
};

void Obj_00256A70::InitFromStructure(void* params)
{
    if (!func_00185578(this, 0x0A015E17))
        func_002569A8(this);
    func_001A8210(func_00185578(this, 0x0A015E17), params);
    unsigned int a = 0;
    func_001E8398(params, 0xA1DC81F9, &a, 0);
    if (a)
        func_00183E90(this, a);
    unsigned int b = 0;
    if (func_001E8398(params, 0x2CA8A299, &b, 0)) {
        int c = 0;
        func_001E8180(params, 0x7031F10C, &c, 0);
        func_00184AB0(this, b, c);
    }
    func_00185578(this, 0x0A015E17)->V2(params);
    func_00185578(this, 0xCE0CA665)->V2(params);
}
