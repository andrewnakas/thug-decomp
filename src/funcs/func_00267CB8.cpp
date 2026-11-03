struct Obj_00267CB8;

struct VSlot_00267CB8 {
    short m_delta;
    short m_pad;
    void* m_fn;
};

struct Owner_00267CB8 {
    char m_pad[0x2C];
    VSlot_00267CB8* m_vtbl;
    void Attach(Obj_00267CB8* obj)
    {
        VSlot_00267CB8* s = &m_vtbl[2];
        ((void (*)(void*, Obj_00267CB8*))s->m_fn)((char*)this + s->m_delta, obj);
    }
    void CreateIcon(void* params);
};

struct Text_00267CB8 {
    char m_pad[0x20];
    unsigned int m20;
    int m24;
    float m28;
    float m2C;
    float m30;
    int m34;
    float m38;
};

struct Font_00267CB8 {
    char m_pad[0xB0];
    float mB0;
};

struct Obj_00267CB8 {
    char m_pad[0x50];
    char m50[4];
};

extern "C" void* func_001046B0(int size);
extern "C" Obj_00267CB8* func_002568D8(void* p);
extern "C" void func_002569A8(Obj_00267CB8* self);
extern "C" void func_00183F08(Obj_00267CB8* self, int a);
extern "C" void func_00229FF8(void* params, void* pos);
extern "C" void func_00256A70(Obj_00267CB8* self, void* params, Owner_00267CB8* owner);
extern "C" void func_001F0210(unsigned int name, void* params, Obj_00267CB8* obj, int a, int b);
extern "C" void func_00185500(Obj_00267CB8* self);
extern "C" Text_00267CB8* func_00185578(Obj_00267CB8* self, unsigned int name);
extern "C" void func_001A6758(Text_00267CB8* p, Obj_00267CB8* obj);
extern "C" Font_00267CB8* func_001A67A8(Text_00267CB8* p);
extern "C" void func_0018DC18(void* p);

void Owner_00267CB8::CreateIcon(void* params)
{
    Obj_00267CB8* obj = func_002568D8(func_001046B0(0x160));
    func_002569A8(obj);
    func_00183F08(obj, 2);
    Attach(obj);
    func_00229FF8(params, obj->m50);
    func_00256A70(obj, params, this);
    func_001F0210(0xF3EEC45E, params, obj, 0, 0);
    func_00185500(obj);
    func_001F0210(0x955A2767, params, obj, 0, 0);
    Text_00267CB8* t = func_00185578(obj, 0x0A015E17);
    t->m38 = 24.0f;
    t->m30 = 44.0f;
    t->m28 = 48.0f;
    t->m2C = 12.0f;
    func_001A6758(t, obj);
    func_001A67A8(t)->mB0 = 24.0f;
    t->m20 |= 0x400;
    func_0018DC18(func_00185578(obj, 0x286A8D26));
    func_001F0210(0x48CA2D26, 0, obj, 0, 0);
}
