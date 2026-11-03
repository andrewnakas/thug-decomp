struct VSlot_002676D8 {
    short m_delta;
    short m_pad;
    void* m_fn;
};

struct Comp_002676D8 {
    char m_pad[0x18];
    VSlot_002676D8* m_vtbl;
    void InitFromStructure(void* params)
    {
        VSlot_002676D8* s = &m_vtbl[3];
        ((void (*)(void*, void*))s->m_fn)((char*)this + s->m_delta, params);
    }
};

struct Text_002676D8 {
    char m_pad[0x28];
    float m28;
    float m2C;
    float m30;
    char m_pad2[0x80 - 0x34];
    int m80;
};

struct Font_002676D8 {
    char m_pad[0xB0];
    float mB0;
};

struct Obj_002676D8;

struct Owner_002676D8 {
    char m_pad[0x2C];
    VSlot_002676D8* m_vtbl;
    void Attach(Obj_002676D8* obj)
    {
        VSlot_002676D8* s = &m_vtbl[2];
        ((void (*)(void*, Obj_002676D8*))s->m_fn)((char*)this + s->m_delta, obj);
    }
};

extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E7360(void* params, unsigned int name, unsigned int value);
extern "C" void func_001E6AE8(void* p, int a);
extern "C" int func_001E8A30(void* params, unsigned int name, unsigned int* out, int required);
extern "C" int func_001E8870(void* params, unsigned int name, int* out, int required);
extern "C" int func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" int func_001E8708(void* params, unsigned int name);
extern "C" void* func_001046B0(int size);
extern "C" Comp_002676D8* func_0018B908(void* p);
extern "C" Comp_002676D8* func_001B73B8(void* p);
extern "C" Comp_002676D8* func_001B75C8(void* p);
extern "C" Comp_002676D8* func_001B7818(void* p);
extern "C" Comp_002676D8* func_001B79D0(void* p);
extern "C" void func_001A50D0(void* p);
extern "C" int func_0013EF10(void* p);
extern "C" void func_001A6758(void* p, Obj_002676D8* obj);
extern "C" Font_002676D8* func_001A67A8(void* p);
extern "C" void func_0018DC18(void* p);

extern "C" void func_002569A8(Obj_002676D8* self);
extern "C" void func_00185300(Obj_002676D8* self, void* params, int a);
extern "C" void func_00256A70(Obj_002676D8* self, void* params, Owner_002676D8* owner);
extern "C" void func_00185288(Obj_002676D8* self, Comp_002676D8* comp);
extern "C" void* func_00185578(Obj_002676D8* self, unsigned int name);
extern "C" void* func_00256BD8(Obj_002676D8* self);
extern "C" void func_00185500(Obj_002676D8* self);

struct Obj_002676D8 {
    void Init(Owner_002676D8* owner, void* params);
};

void Obj_002676D8::Init(Owner_002676D8* owner, void* params)
{
    owner->Attach(this);
    func_002569A8(this);
    unsigned int id = 0x88C21962;
    bool has = func_001E8A30(params, 0x09794932, &id, 0) != 0;
    if (has) {
        void* ev = func_001E6978(func_001190D0(8));
        func_001E7360(ev, 0xB6015EA8, 0x222756D5);
        func_001E7360(ev, 0x222756D5, id);
        func_00185300(this, ev, 0);
        if (ev)
            func_001E6AE8(ev, 3);
    }
    func_00256A70(this, params, owner);
    Comp_002676D8* c = func_0018B908(func_001046B0(0x290));
    func_00185288(this, c);
    c->InitFromStructure(params);
    if (has) {
        int v;
        func_001E8870(params, 0x286A8D26, &v, 1);
        func_001A50D0(func_00185578(this, 0xC695136D));
    } else if (func_0013EF10(func_00256BD8(this))) {
        unsigned int t = 0;
        func_001E8398(params, 0xA1DC81F9, &t, 1);
    }
    ((Comp_002676D8*)func_00185578(this, 0xC695136D))->InitFromStructure(params);
    if (!func_001E8708(params, 0x0BF29BC0)) {
        void* ev = func_001E6978(func_001190D0(8));
        func_001E7360(ev, 0xB6015EA8, 0xA432DC41);
        func_001E7360(ev, 0x2D7E583B, 0x6AADF154);
        func_00185300(this, ev, 0);
        if (ev)
            func_001E6AE8(ev, 3);
    }
    ((Text_002676D8*)func_00185578(this, 0x0A015E17))->m30 = 528.0f;
    ((Text_002676D8*)func_00185578(this, 0x0A015E17))->m28 = 216.0f;
    ((Text_002676D8*)func_00185578(this, 0x0A015E17))->m2C = 384.0f;
    ((Text_002676D8*)func_00185578(this, 0x0A015E17))->m80 = 0;
    func_001A6758(func_00185578(this, 0x0A015E17), this);
    func_001A67A8(func_00185578(this, 0x0A015E17))->mB0 = 240.0f;
    c = func_001B73B8(func_001046B0(0x20));
    func_00185288(this, c);
    c->InitFromStructure(params);
    if (!func_001E8708(params, 0x1FB9E477)) {
        c = func_001B75C8(func_001046B0(0x20));
        func_00185288(this, c);
        c->InitFromStructure(params);
    }
    if (!func_001E8708(params, 0x59793E2B)) {
        c = func_001B7818(func_001046B0(0x20));
        func_00185288(this, c);
        c->InitFromStructure(params);
        c = func_001B79D0(func_001046B0(0x24));
        func_00185288(this, c);
        c->InitFromStructure(params);
    }
    func_00185500(this);
    func_0018DC18(func_00185578(this, 0x286A8D26));
}
