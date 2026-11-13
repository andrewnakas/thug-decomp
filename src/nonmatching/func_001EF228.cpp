/* fuzzy: 98.9 */
extern void* D_0038E8A4;
extern char D_003655E0[];
extern "C" int func_001EC7A0(unsigned char*);
extern "C" unsigned char* func_001ECA68(unsigned char*);
extern "C" void* func_001E8CD0(unsigned int);
extern "C" unsigned char* func_001ED1C0(unsigned char*, void*, void*);
extern "C" unsigned char* func_001ECE50(unsigned char*, void*, void*);
extern "C" void func_001E6250(void*);
extern "C" void func_001E8D20(void*);
extern "C" void func_001E6F90(void*, void*);
extern "C" void* func_00184D70(int);
extern "C" void* func_001F2F88(void*, int);
extern "C" int func_001E61F0(int);
extern "C" int func_00103F28(const char*, ...);

struct Comp_001EF228 {
    unsigned char m0;
    unsigned char m1;
    unsigned char m2;
    unsigned char m3;
    int m4;
    int m8;
    int mC;
};

extern "C" Comp_001EF228* func_001E4ED8(void*);
extern "C" Comp_001EF228* func_001E5040(int);

struct Script_001EF228 {
    char pad0[0x10];
    unsigned char* m_pc;
    int m14;
    void* m18;
    char pad1c[0xBC - 0x1C];
    int mBC;
    char padc0[8];
    unsigned int mC8;
    int Execute();
    void Skip();
    int Call(int name, int arg);
    int Jump(int name);
    int Eval();
    void Run(int name, void* fn, int a, int b, int c);
};

extern "C" void func_001EF078(Script_001EF228*);
extern "C" int func_001EF0B8(Script_001EF228*, int, int);
extern "C" int func_001EF118(Script_001EF228*, int);
extern "C" int func_001EF140(Script_001EF228*);
extern "C" void func_001EECE8(Script_001EF228*, int, void*, int, int, int);

int Script_001EF228::Execute()
{
    unsigned char op = *m_pc;
    if (op == 0x44) {
        m_pc++;
        int name = func_001EC7A0(m_pc);
        m_pc += 4;
        func_001EF078(this);
        return func_001EF0B8(this, name, 0);
    }
    if (op == 0x43) {
        m_pc++;
        int name = func_001EC7A0(m_pc);
        m_pc += 4;
        func_001EF078(this);
        return func_001EF118(this, name);
    }
    if (op == 0x0E) {
        Comp_001EF228* c = func_001E4ED8(func_001E8CD0(0x10));
        m_pc = func_001ED1C0(m_pc, m18, c);
        int r = c->m8 != 0;
        func_001E6250(c);
        func_001E8D20(c);
        return r;
    }
    int v = func_001EF140(this);
    if (*m_pc == 0x42) {
        void* obj = func_00184D70(v);
        if (!obj)
            return 1;
        m_pc++;
        m_pc = func_001ECA68(m_pc);
        if (*m_pc == 0x44) {
            m_pc++;
            int name = func_001EC7A0(m_pc);
            m_pc += 4;
            func_001EF078(this);
            return func_001EF0B8(this, name, (int)obj);
        }
        int name = func_001EF140(this);
        func_001EF078(this);
        Comp_001EF228* c = func_001E5040(name);
        if (!c && mC8 == 0xFB11E6CD)
            return 0;
        switch (c->m2) {
        case 7:
            func_001EECE8(this, name, func_001F2F88(D_0038E8A4, c->m4), m14, (int)obj, 0);
            return 1;
        case 9:
            return func_001EF0B8(this, name, (int)obj);
        }
        return 0;
    }
    if (*m_pc == 7) {
        m_pc -= 4;
        int name = func_001EC7A0(m_pc);
        m_pc += 5;
        m_pc = func_001ECA68(m_pc);
        Comp_001EF228* c = func_001E4ED8(func_001E8CD0(0x10));
        if (*m_pc == 0x0E)
            m_pc = func_001ED1C0(m_pc, m18, c);
        else
            m_pc = func_001ECE50(m_pc, m18, c);
        if (c->m1) {
            c->m4 = name;
            func_001E6F90(m18, c);
        } else {
            func_001E8D20(c);
        }
        return 1;
    }
    func_001EF078(this);
    Comp_001EF228* c = func_001E5040(v);
    if (!c) {
        if (mC8 == 0xFB11E6CD)
            return 0;
        func_00103F28(D_003655E0, func_001E61F0(v));
        return 1;
    }
    switch (c->m2) {
    case 8:
        return func_001EF118(this, c->mC);
    case 9:
        return func_001EF0B8(this, v, 0);
    case 7:
        func_001EECE8(this, v, func_001F2F88(D_0038E8A4, c->m4), m14, mBC, 0);
        return 1;
    }
    return 0;
}
