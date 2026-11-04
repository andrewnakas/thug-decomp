extern int D_00388A70;
extern "C" void func_0010A8D8(int pool, void* p);
extern "C" void func_00135590(void* o, int flags);
extern "C" void func_0010DCD0(void* o);
extern "C" void func_00139D10(void* tex);

struct HashTable_00134B50 {
    int m0;
    void* m4;
    int m8;
    int mC;
    void* m10;
    ~HashTable_00134B50();
    void Reset();
    void* Next(int* key);
};

struct Obj28_00132C48 {
    char pad[0x28];
    virtual ~Obj28_00132C48();
};

struct Obj14_00132C48 {
    char pad[0x14];
    virtual ~Obj14_00132C48();
};

struct ElemBase_00132C48 {
    char pad[0xC];
    virtual ~ElemBase_00132C48();
};

struct Elem_00132C48 : ElemBase_00132C48 {
    int m10;
    static void operator delete[](void* p) { func_0010A8D8(D_00388A70, p); }
};

struct Slot_00207DF8 {
    char pad[0x30];
    ~Slot_00207DF8();
};

struct Slots_00132C48 {
    char pad[0x30];
    Slot_00207DF8 m_slots[400];
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

struct Scene_00132C48 {
    char pad0[0xD0];
    HashTable_00134B50* m_D0;
    Slots_00132C48* m_D4;
    char m_D8[0x84];
    Elem_00132C48* m_15C;
    int m_160;
    char pad164[0x80];
    void* m_1E4;
    char pad1E8[0x90];
    Obj14_00132C48* m_278;
    Obj14_00132C48* m_27C;
    virtual void V0();
    virtual ~Scene_00132C48();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

Scene_00132C48::~Scene_00132C48()
{
    if (m_D0) {
        m_D0->Reset();
        Obj28_00132C48* o;
        while ((o = (Obj28_00132C48*)m_D0->Next(0)) != 0) {
            func_00135590(o, 0x40);
            delete o;
        }
        delete m_D0;
    }
    delete m_D4;
    delete[] m_15C;
    if (m_160) {
        func_0010DCD0(m_D8);
    }
    delete m_278;
    delete m_27C;
    if (m_1E4) {
        func_00139D10(m_1E4);
    }
}
