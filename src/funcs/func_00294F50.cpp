extern "C" void* func_001190D0(int);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E6AE8(void* p, int v);

struct Mod_00294F50 {
    char pad[0x14];
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
};
extern "C" void* func_00240850();
extern "C" void func_0023B5A8(void*, int, void*);
extern "C" Mod_00294F50* func_0023BAD8(void*, int, int);
extern "C" void func_00246508(Mod_00294F50*);

struct Obj_00294F50;
extern "C" void func_002929B0(Obj_00294F50*, void*);
extern "C" int func_00292748(Obj_00294F50*);

struct Obj_00294F50 {
    char pad0[0x2A4];
    unsigned char m2A4;
    void Start(int flag);
};

void Obj_00294F50::Start(int flag)
{
    void* st = func_001E6978(func_001190D0(8));
    func_002929B0(this, st);
    void* m = func_00240850();
    func_0023B5A8(m, func_00292748(this), st);
    Mod_00294F50* o = func_0023BAD8(m, func_00292748(this), 1);
    func_00246508(o);
    if (flag) m2A4 = 0;
    if (m2A4) o->v23();
    if (st) func_001E6AE8(st, 3);
}
