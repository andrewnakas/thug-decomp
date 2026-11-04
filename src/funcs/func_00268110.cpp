extern char D_00376108[];
extern char D_003911A8[];
extern char D_003911B0[];

struct Str_00268110 {
    char m[16];
};

struct Obj_00268110;

struct VSlot_00268110 {
    short m_delta;
    short m_pad;
    void* m_fn;
};

struct Owner_00268110 {
    char m_pad[0x2C];
    VSlot_00268110* m_vtbl;
    void Attach(Obj_00268110* obj)
    {
        VSlot_00268110* s = &m_vtbl[2];
        ((void (*)(void*, Obj_00268110*))s->m_fn)((char*)this + s->m_delta, obj);
    }
};

struct Bounds_00268110 {
    char m_pad[0x3C];
    float m3C;
    float m40;
    float m44;
    float m48;
};

extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E7360(void* params, unsigned int name, unsigned int value);
extern "C" void func_001E6AE8(void* p, int a);
extern "C" unsigned int func_001F0D78(char* s);
extern "C" void func_00104008(Str_00268110* s);
extern "C" void func_00131688(Str_00268110* ret, char* a, char* b);
extern "C" void func_00104170(Str_00268110* s, Str_00268110* o);
extern "C" void func_001040A8(Str_00268110* s, int flags);
extern "C" char* func_001041B8(Str_00268110* s);
extern "C" void func_0013D2F0(void* p, char* name, int a, int b, int c, int d, int e);
extern "C" void func_0013D950(void* p, int a);
extern "C" void func_0018DC18(void* p);

extern "C" void func_002569A8(Obj_00268110* self);
extern "C" void func_00185300(Obj_00268110* self, void* params, int a);
extern "C" void func_00256A70(Obj_00268110* self, void* params, Owner_00268110* owner);
extern "C" void func_00183E90(Obj_00268110* self, unsigned int id);
extern "C" void* func_00185578(Obj_00268110* self, unsigned int name);
extern "C" void* func_00256BD8(Obj_00268110* self);
extern "C" void func_00185500(Obj_00268110* self);

struct Obj_00268110 {
    char m_pad[0x50];
    char m50[4];
    void Init(Owner_00268110* owner, void* params);
};

extern "C" void func_00229FF8(void* params, void* pos);

void Obj_00268110::Init(Owner_00268110* owner, void* params)
{
    owner->Attach(this);
    func_002569A8(this);
    void* ev = func_001E6978(func_001190D0(8));
    func_001E7360(ev, 0xB6015EA8, 0x286A8D26);
    func_00185300(this, ev, 0);
    if (ev)
        func_001E6AE8(ev, 3);
    func_00256A70(this, params, owner);
    func_00183E90(this, func_001F0D78(D_00376108));
    Bounds_00268110* b = (Bounds_00268110*)func_00185578(this, 0xCE0CA665);
    b->m3C = 1000000.0f;
    b->m40 = 1000001.0f;
    b->m44 = 1000002.0f;
    b->m48 = 1000003.0f;
    Str_00268110 s;
    Str_00268110 t;
    func_00104008(&s);
    func_00131688(&t, D_003911A8, D_003911B0);
    func_00104170(&s, &t);
    func_001040A8(&t, 2);
    void* m = func_00256BD8(this);
    func_0013D2F0(m, func_001041B8(&s), 0, 1, 0, 0, 0);
    func_0013D950(func_00256BD8(this), 1);
    func_00229FF8(params, m50);
    func_00185500(this);
    func_0018DC18(func_00185578(this, 0x286A8D26));
    func_001040A8(&s, 2);
}
