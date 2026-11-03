struct Physics_00205B30 {
    char pad[0x20];
    int m_state;
    char pad24[0x180 - 0x24];
    int m_flag;
};

struct Body_00205B30 {
    char pad[0x34];
    Physics_00205B30* m_physics;
};

extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E7360(void* s, unsigned int name, unsigned int value);
extern "C" void func_001E6AE8(void* p, int flags);
extern "C" int func_001F1248(void* p);
extern "C" void func_001F1240(void* p, int a);
extern "C" void func_001EEF18(void* p, int a, int b);
extern "C" void func_0027C0B0(void* p);
extern "C" void* func_00185578(void* self, unsigned int name);
extern "C" void func_001B9978(void* p);
extern "C" void func_00290870(void* p);

class Object_00205B30 {
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
    virtual void V17(int a, int b);
};

class Skater_00205B30 : public Object_00205B30 {
public:
    char pad0C[0x14 - 0xC];
    void* m_trick;
    char pad18[0x2E0 - 0x18];
    void* m_m2E0;
    Body_00205B30* m_body;
    void Reset(int a, int b);
};

extern "C" void func_00206870(Skater_00205B30* self, unsigned int name, void* params);
extern "C" void* func_00203EE0(Skater_00205B30* self);
extern "C" void func_002057E8(Skater_00205B30* self);

void Skater_00205B30::Reset(int a, int b)
{
    Physics_00205B30* phys = m_body->m_physics;
    bool on_ground = false;
    if (phys->m_flag == 0) {
        on_ground = phys->m_state == 1;
    }
    if (on_ground) {
        void* p = func_001E6978(func_001190D0(8));
        func_001E7360(p, 0x91D0D784, 0x1DDE4804);
        func_00206870(this, 0x93A4E402, p);
        if (p) {
            func_001E6AE8(p, 3);
        }
    }
    if (m_trick && func_001F1248(m_trick)) {
        int t = func_001F1248(m_trick);
        func_001F1240(m_trick, 0);
        func_001EEF18(m_trick, t, 0);
    }
    func_0027C0B0(m_m2E0);
    func_001B9978(func_00185578(func_00203EE0(this), 0x5E43A604));
    V15();
    func_002057E8(this);
    V16();
    V17(a, b);
    func_00290870(func_00185578(this, 0xB1D5A3E1));
}
