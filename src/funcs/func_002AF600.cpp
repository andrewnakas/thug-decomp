struct S4_002AF600 {
    char c[4];
};

struct Mod_002AF600 {
    int m0[5];
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
    virtual void v11();
    virtual void v12();
    virtual void v13();
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
    virtual void v24();
    virtual void v25();
    virtual int v26();
};

extern char D_00379408[];
extern char D_00379418[];
extern "C" void* func_00240850();
extern "C" void func_0023C780(void* p);
extern "C" Mod_002AF600* func_0023BAD8(void* p, int id, int v);
extern "C" void func_00246630(Mod_002AF600* m);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E6AE8(void* p, int v);
extern "C" int func_001F0D78(char* s);
extern "C" void func_001E73C8(void* p, char* name, int v);
extern "C" void func_001F0938(char* s, void* p, int a, int b, int c, int d, int e, int f, int g, int h);

struct Obj_002AF600 {
    signed char* m0;
};

bool Cmd_002AF600(Obj_002AF600* o)
{
    signed char* p = o->m0;
    void* mgr = func_00240850();
    func_0023C780(mgr);
    int first = *p;
    p++;
    int id;
    for (;;) {
        *(S4_002AF600*)&id = *(S4_002AF600*)p;
        p += 4;
        if (!id)
            break;
        Mod_002AF600* m = func_0023BAD8(mgr, id, 1);
        m->v26();
        func_00246630(m);
    }
    if (first == 1) {
        void* s = func_001E6978(func_001190D0(8));
        func_001E73C8(s, D_00379408, func_001F0D78(D_00379408));
        func_001F0938(D_00379418, s, 0, 0, -1, 0, 0, 0, 0, 0);
        if (s)
            func_001E6AE8(s, 3);
    }
    return true;
}
