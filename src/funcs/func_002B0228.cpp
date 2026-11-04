struct Link_002B0228 {
    int m0;
};

struct Base_002B0228 {
    char pad0[0x14];
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual int v11(int a, int b);
    virtual void v12();
    virtual int v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24(int a);
    virtual void v25(int a);
};

struct Obj_002B0228 : Base_002B0228 {
    void* m18;
    char pad1C[0x2C - 0x1C];
    Link_002B0228* m2C;
};

struct Team_002B0228 {
    char pad[0x18];
    int m18;
};

struct Pl_002B0228 {
    char pad[0x18];
    Team_002B0228* m18;
    char pad1C[0x30 - 0x1C];
    int m30;
    char m34[0x10];
};

struct Data_002B0228 {
    char m0;
    char pad[3];
    int m4;
};

struct Msg_002B0228 {
    Data_002B0228* m0;
    char pad4[0x1C - 4];
    void* m1C;
};

extern void* D_0038FC78;
extern char D_00379490[];
extern char D_003794A0[];
extern "C" void* func_00240850();
extern "C" Obj_002B0228* func_0023BAD8(void* p, int id, int v);
extern "C" int func_0023BF98(void* p, int v);
extern "C" Obj_002B0228* func_0023BB50(void* p, int idx);
extern "C" Pl_002B0228* func_002A52F0(void* table, unsigned short id);
extern "C" Pl_002B0228* func_002A56E0(void* t);
extern "C" int func_0023C128(void* p);
extern "C" int func_0023DCE0(void* p);
extern "C" void func_00249DC8(void* p);
extern "C" int func_002461E8(Obj_002B0228* o);
extern "C" void* func_0022E358(void* p);
extern "C" int func_0024F540(void* p);
extern "C" void func_00246D18(Obj_002B0228* p, int* out);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E7268(void* p, char* name, int v);
extern "C" void func_001E7200(void* p, unsigned int key, int v);
extern "C" void func_001E70C0(void* p, unsigned int name, char* s);
extern "C" void func_001F0370(char* s, void* a, int b, int c);
extern "C" void func_001F0210(unsigned int name, void* params, void* obj, int a, int b);
extern "C" void func_001E6AE8(void* p, int v);

int Handler_002B0228(Msg_002B0228* msg)
{
    Obj_002B0228* other = 0;
    void* gs = D_0038FC78;
    void* mgr = msg->m1C;
    Data_002B0228* d = msg->m0;
    void* world = func_00240850();
    Obj_002B0228* o = func_0023BAD8(world, d->m4, 1);
    int idx = func_0023BF98(world, 1);
    if (idx >= 0) other = func_0023BB50(world, idx);
    if (o) {
        Pl_002B0228* me;
        Pl_002B0228* pl = func_002A52F0(mgr, (signed char)d->m0);
        me = func_002A56E0(mgr);
        o->v25(pl->m30);
        if (pl->m18) {
            o->v24(pl->m18->m18);
            if (me == pl) {
                int a = func_0023C128(world);
                int b = func_0023DCE0(world);
                if (b < a) {
                    void* s = func_001E6978(func_001190D0(8));
                    func_001E7268(s, D_00379490, a - b);
                    func_001F0370(D_003794A0, s, 0, 0);
                    if (s) func_001E6AE8(s, 3);
                }
                func_00249DC8(o->m18);
            } else {
                int same = 0;
                if (other) same = func_002461E8(o) == func_002461E8(other);
                if (func_0024F540(func_0022E358(gs)) && me->m30 == pl->m30) {
                    if (same) {
                        Link_002B0228* l = o->m2C;
                        if (l->m0) {
                            Obj_002B0228* p = o;
                            while (l && l->m0) {
                                p = func_0023BAD8(world, l->m0, 1);
                                l = p->m2C;
                            }
                            p->v13();
                            if (p != other) other->v11(0, 1);
                        } else {
                            o->v13();
                        }
                        func_00249DC8(other->m18);
                    } else {
                        func_00249DC8(o->m18);
                    }
                    o->v23();
                    int a = func_0023C128(world);
                    int b = func_0023DCE0(world);
                    if (b < a) {
                        int t = 0;
                        func_00246D18(o, &t);
                        void* s = func_001E6978(func_001190D0(8));
                        func_001E7200(s, 0x684A8396, a - b);
                        func_001E70C0(s, 0x9196D920, pl->m34);
                        func_001E70C0(s, 0xB8A88B50, (char*)t);
                        func_001F0210(0xF4748E47, s, 0, 0, 0);
                        if (s) func_001E6AE8(s, 3);
                    }
                }
            }
        }
    }
    return 1;
}
