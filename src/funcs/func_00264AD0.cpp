extern char D_00375EB8[];
extern char D_00375EC8[];
extern char D_00391000[];
extern char D_00391008[];
extern char D_00391010[];

extern "C" float func_00341068(float x);
extern "C" float func_00340F60(float x);

struct Vec_00264AD0 {
    float x, y, z, w;
    Vec_00264AD0() {}
    Vec_00264AD0(float ax, float ay, float az) { x = ax; y = ay; z = az; w = 1.0f; }
    void RotateX(float a)
    {
        float s = func_00341068(a);
        float c = func_00340F60(a);
        float ny = c * y - s * z;
        float nz = s * y + c * z;
        y = ny;
        z = nz;
    }
    void RotateY(float a)
    {
        float s = func_00341068(a);
        float c = func_00340F60(a);
        float nx = c * x + s * z;
        float nz = -s * x + c * z;
        x = nx;
        z = nz;
    }
    void RotateZ(float a)
    {
        float s = func_00341068(a);
        float c = func_00340F60(a);
        float nx = c * x - s * y;
        float ny = s * x + c * y;
        x = nx;
        y = ny;
    }
};

struct Obj_00264AD0 {
    char m_pad[0x14];
    void* m14;
    char m_pad2[0x1AC - 0x18];
    float m1AC;
    float m1B0;
    float m1B4;
    char m_pad3[0x1C4 - 0x1B8];
    unsigned int m1C4;
    void SetDir(float x, float y, float z) { m1AC = x; m1B0 = y; m1B4 = z; }
};

struct VSlot_00264AD0 {
    short m_delta;
    short m_pad;
    void* m_fn;
};

struct Owner_00264AD0 {
    char m_pad[0x2C];
    VSlot_00264AD0* m_vtbl;
    void Attach(Obj_00264AD0* obj)
    {
        VSlot_00264AD0* s = &m_vtbl[2];
        ((void (*)(void*, Obj_00264AD0*))s->m_fn)((char*)this + s->m_delta, obj);
    }
    void Spawn(void* params);
};

extern "C" bool func_001E8A50(void* params, char* name, unsigned int* out, int required);
extern "C" bool func_001E81F0(void* params, char* name, void** out, int required);
extern "C" void func_001F0210(unsigned int name, void* params, void* obj, int a, int b);
extern "C" void* func_001324B0();
extern "C" Obj_00264AD0* func_001414D0(void* mgr, unsigned int* type, int a);
extern "C" void func_001410B0(void* mgr, unsigned int* type);
extern "C" int func_00141538(void* mgr, unsigned int* id, Obj_00264AD0* obj);
extern "C" void func_00183E90(Obj_00264AD0* obj, unsigned int id);
extern "C" bool func_001E8038(void* params, char* name, Vec_00264AD0* out, int required);
extern "C" double func_0033ECA8(float x);
extern "C" void func_00103F28(char* fmt, ...);
extern "C" void func_00256A70(Obj_00264AD0* obj, void* params, Owner_00264AD0* owner);
extern "C" void func_001EE9E0(void* p);
extern "C" void func_001EEB60(void* p);

void Owner_00264AD0::Spawn(void* params)
{
    unsigned int script = 0;
    func_001E8A50(params, D_00375EB8, &script, 1);
    unsigned int id = 0;
    func_001E8A50(params, D_00391000, &id, 1);
    if (!script)
        return;
    void* sp = 0;
    func_001E81F0(params, D_00391008, &sp, 0);
    func_001F0210(script, sp, 0, 0, 0);
    void* mgr = func_001324B0();
    unsigned int type = 0x502335A1;
    Obj_00264AD0* obj = func_001414D0(mgr, &type, 1);
    void* mgr2 = func_001324B0();
    unsigned int type2 = 0x502335A1;
    func_001410B0(mgr2, &type2);
    func_00141538(func_001324B0(), &id, obj);
    obj->m1C4 = id;
    func_00183E90(obj, id);
    Vec_00264AD0 ang;
    Vec_00264AD0 dir(0.0f, 1.0f, 0.0f);
    func_001E8038(params, D_00391010, &ang, 0);
    func_00103F28(D_00375EC8, func_0033ECA8(ang.x), func_0033ECA8(ang.y), func_0033ECA8(ang.z));
    dir.RotateX(ang.x);
    dir.RotateY(ang.y);
    dir.RotateZ(ang.z);
    obj->SetDir(dir.x, dir.y, dir.z);
    Attach(obj);
    func_00256A70(obj, params, this);
    func_001EE9E0(obj->m14);
    func_001EEB60(obj->m14);
}
