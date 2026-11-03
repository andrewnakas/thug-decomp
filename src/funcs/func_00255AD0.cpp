struct Comp_00255AD0 {
    int m_data[6];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6(int arg);
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10(unsigned int name, void* params, int a);
};

extern "C" Comp_00255AD0* func_00185578(void* obj, unsigned int id);
extern "C" void func_001A18C8(Comp_00255AD0* c, int a, int b, float v);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E72B0(void* s, unsigned int name, float v);
extern "C" void func_001E6AE8(void* s, int in_chrg);

struct Obj_00255AD0 {
    char m_pad[0x170];
    float m_level;
    int m_174;
    void SetLevel(float level);
};

void Obj_00255AD0::SetLevel(float level)
{
    m_level = level;
    if (level > 1.0f)
        m_level = 1.0f;
    if (m_level < 0.0f)
        m_level = 0.0f;
    if (func_00185578(this, 0x72AD7B23)) {
        func_001A18C8(func_00185578(this, 0x72AD7B23), 0, 0, m_level);
        void* p = func_001E6978(func_001190D0(8));
        func_001E72B0(p, 0xF0D90109, m_level);
        func_00185578(this, 0x72AD7B23)->V10(0xBD4EDD44, p, 0);
        if (p)
            func_001E6AE8(p, 3);
    }
    if (func_00185578(this, 0x72AD7B23))
        func_00185578(this, 0x72AD7B23)->V6(0);
    m_174 = 0;
}
