struct Obj_0026FF18;
struct Handle_0026FF18;

extern "C" void func_00183C98(Obj_0026FF18* o, Handle_0026FF18* h);
extern "C" void func_00183CB8(Obj_0026FF18* o, Handle_0026FF18* h);

struct Handle_0026FF18 {
    Obj_0026FF18* m_obj;
    Handle_0026FF18* m_prev;
    Handle_0026FF18* m_next;
    Handle_0026FF18(const Handle_0026FF18& h)
    {
        m_prev = 0;
        m_next = 0;
        m_obj = h.m_obj;
        if (m_obj)
            func_00183C98(m_obj, this);
    }
    ~Handle_0026FF18()
    {
        if (m_obj) {
            func_00183CB8(m_obj, this);
            m_obj = 0;
        }
    }
    operator Obj_0026FF18*() const { return m_obj; }
};

struct Mgr_0026FF18;
extern Mgr_0026FF18* D_00389A30;
extern unsigned int D_003764C0[];
extern "C" Handle_0026FF18 func_0012DB48(void* mgr, unsigned int id, int a);
extern "C" unsigned int func_002041F8(void* p);
extern "C" void func_00128818(Obj_0026FF18* o, unsigned int anim);
extern "C" void func_00123EB0(Obj_0026FF18* o, int a, float f);

struct Mgr_0026FF18 {
    Obj_0026FF18* Find(unsigned int id) { return func_0012DB48(this, id, 0); }
};

struct Info_0026FF18 {
    char pad[0x164];
    int m164;
};

struct State_0026FF18 {
    char pad[0x34];
    bool m34;
};

struct Skater_0026FF18 {
    char pad[0xC];
    Info_0026FF18* mC;
    char pad2[0x5B0 - 0x10];
    State_0026FF18* m5B0;
    bool Test()
    {
        if (mC->m164)
            return m5B0->m34;
        return !m5B0->m34;
    }
};

struct C_0026FF18 {
    char pad[0xC];
    void* mC;
    char pad2[0x1C - 0x10];
    int m1C;
    int m20;
    int m24;
    int m28;
    Skater_0026FF18* m2C;
    void Update();
};

void C_0026FF18::Update()
{
    Mgr_0026FF18* mgr = D_00389A30;
    Obj_0026FF18* o = mgr->Find(func_002041F8(mC) + 0x968AE5DD);
    int state = 5;
    if (m28) {
        if (m2C->Test())
            state = 3;
        else
            state = 4;
    } else if (m2C->Test()) {
        if (m24)
            state = 1;
        else
            state = 2;
    } else if (m24) {
        state = 0;
    }
    if (state != m1C) {
        m1C = state;
        if (state == 5) {
            func_00123EB0(o, 1, 0.0f);
        } else {
            func_00128818(o, D_003764C0[state]);
            func_00123EB0(o, 1, 1.0f);
        }
    }
}
