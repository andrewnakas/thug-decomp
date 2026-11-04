extern "C" int func_0010FC30();

struct Setting_002056C8 {
    int m0;
    int m_value;
    int m_stamp;
    void Set(int v)
    {
        if (m_value != v) {
            m_value = v;
            m_stamp = func_0010FC30();
        }
    }
};

struct Prefs_002056C8 {
    char pad[0x24];
    Setting_002056C8 m24[23];
};

struct Flag_002056C8 {
    char pad[0x28];
    int m_value;
};

struct Engine_002056C8 {
    char pad[0x59C];
    Flag_002056C8* m_flag;
    char pad5A0[0x5B0 - 0x5A0];
    Prefs_002056C8* m_prefs;
};

extern "C" void func_00277E80(void* p);
extern "C" void* func_00185578(void* self, unsigned int name);
extern "C" void func_00291068(void* p);
extern "C" void func_0026FA48(void* p);

static inline void Set_002056C8(Engine_002056C8* e, int i, int value)
{
    e->m_prefs->m24[i].Set(value);
    if (i == 7)
        e->m_flag->m_value = value;
}

class Object_002056C8 {
public:
    int m0;
    int m4;
    virtual void V00();
    virtual void V01();
    virtual void V02();
    virtual void V03();
    virtual void V04();
    virtual void V05();
    virtual void V06();
    virtual void V07();
    virtual void V08();
    virtual void V09();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
};

class Skater_002056C8 : public Object_002056C8 {
public:
    char pad0C[0x2C8 - 0xC];
    char* m_m2C8;
    char pad2CC[0x2D8 - 0x2CC];
    void* m_m2D8;
    char pad2DC[0x2E0 - 0x2DC];
    Engine_002056C8* m_engine;
    void Refresh();
};

void Skater_002056C8::Refresh()
{
    func_00277E80(m_m2D8);
    func_00291068(func_00185578(this, 0x589E5FB3));
    V16();
    for (int i = 0; i < 23; i++) {
        Set_002056C8(m_engine, i, 1);
        Set_002056C8(m_engine, i, 0);
    }
    func_0026FA48(m_m2C8 + 0x24);
}
