extern char D_003908E0[];
extern char D_003908E8[];
extern char D_003908F0[];
extern char D_003908F8[];
extern char D_00390900[];
extern char D_003753B0[];
extern char D_003753C0[];

typedef int qword_00255578 __attribute__((mode(TI)));

struct Vec_00255578 {
    union {
        qword_00255578 q;
        struct {
            float x, y, z, w;
        } f;
    };
};

extern Vec_00255578 D_00452120;

struct Heap_00255578 {
    char m_pad[0xDC];
    int mDC;
    char m_pad2[0x11C - 0xE0];
    int m11C;
};
extern Heap_00255578* D_00388A70;
extern int D_00388818;

struct Str_00255578 {
    char m[16];
};

struct Obj_00255578;

struct VSlot_00255578 {
    short m_delta;
    short m_pad;
    void* m_fn;
};

struct Owner_00255578 {
    char m_pad[0x2C];
    VSlot_00255578* m_vtbl;
    void Attach(Obj_00255578* obj)
    {
        VSlot_00255578* s = &m_vtbl[2];
        ((void (*)(void*, Obj_00255578*))s->m_fn)((char*)this + s->m_delta, obj);
    }
};

struct Skate_00255578;
extern Skate_00255578* D_0038FC78;

extern "C" Owner_00255578* func_0022E040(Skate_00255578* sk);
extern "C" char* func_0022E3C8(Skate_00255578* sk, int index);
extern "C" void func_001325A0();
extern "C" void func_0010A950(void*, int);
extern "C" void func_0010A9B0(void*);
extern "C" int func_003331D0(char* buf, char* fmt, ...);
extern "C" bool func_001E8890(void* params, char* name, char** out, int required);
extern "C" bool func_001E8A50(void* params, char* name, void** out, int required);
extern "C" bool func_001E88F8(void* params, char* name, int* out, int required);
extern "C" void func_00104008(Str_00255578* s);
extern "C" void func_00131688(Str_00255578* ret, char* a, char* b);
extern "C" void func_00104170(Str_00255578* s, Str_00255578* o);
extern "C" void func_001040A8(Str_00255578* s, int flags);
extern "C" char* func_001041B8(Str_00255578* s);
extern "C" void func_00255500(char* name);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E6AC8(void* dst, void* src);
extern "C" void func_001E7910(void* params, char* name, void* value);
extern "C" void func_001F0210(unsigned int name, void* params, Obj_00255578* obj, int a, int b);

extern "C" void func_002569A8(Obj_00255578* self);
extern "C" void func_00256A70(Obj_00255578* self, void* params, Owner_00255578* owner);
extern "C" void func_00185500(Obj_00255578* self);
extern "C" void func_00255968(Obj_00255578* self, unsigned int name);

struct Mat_00255578 {
    float m[4][4];
    void Ident()
    {
        m[0][0] = 1.0f; m[0][1] = 0.0f; m[0][2] = 0.0f; m[0][3] = 0.0f;
        m[1][0] = 0.0f; m[1][1] = 1.0f; m[1][2] = 0.0f; m[1][3] = 0.0f;
        m[2][0] = 0.0f; m[2][1] = 0.0f; m[2][2] = 1.0f; m[2][3] = 0.0f;
        m[3][0] = 0.0f; m[3][1] = 0.0f; m[3][2] = 0.0f; m[3][3] = 1.0f;
    }
};

struct Obj_00255578 {
    char m_pad[0x50];
    Vec_00255578 m50;
    char m_pad2[0x10];
    Mat_00255578 m70;
    void Init(void* params);
};

void Obj_00255578::Init(void* params)
{
    Skate_00255578* sk = D_0038FC78;
    func_0022E040(sk)->Attach(this);
    func_002569A8(this);
    func_00256A70(this, params, func_0022E040(sk));
    func_001325A0();
    if (D_00388818)
        func_0010A950(D_00388A70, D_00388A70->m11C);
    else
        func_0010A950(D_00388A70, D_00388A70->mDC);
    char* name;
    for (int i = 0; i < 4; i++) {
        char buf[256];
        func_003331D0(buf, D_003908E0, i);
        if (func_001E8890(params, buf, &name, 0)) {
            Str_00255578 s;
            Str_00255578 t;
            func_00104008(&s);
            func_00131688(&t, name, D_003908E8);
            func_00104170(&s, &t);
            func_001040A8(&t, 2);
            func_00255500(func_001041B8(&s));
            func_00131688(&t, name, D_003908F0);
            func_00104170(&s, &t);
            func_001040A8(&t, 2);
            func_00255500(func_001041B8(&s));
            func_001040A8(&s, 2);
        }
    }
    if (func_001E8890(params, D_003753B0, &name, 0) || func_001E8890(params, D_003908F8, &name, 0)) {
        Str_00255578 s;
        Str_00255578 t;
        func_00104008(&s);
        func_00131688(&t, name, D_003908E8);
        func_00104170(&s, &t);
        func_001040A8(&t, 2);
        func_00255500(func_001041B8(&s));
        func_00131688(&t, name, D_003908F0);
        func_00104170(&s, &t);
        func_001040A8(&t, 2);
        func_00255500(func_001041B8(&s));
        func_001040A8(&s, 2);
    } else {
        void* prof;
        int index;
        if (!func_001E8A50(params, D_00390900, &prof, 0) && func_001E88F8(params, D_003753C0, &index, 0)) {
            char* src = func_0022E3C8(D_0038FC78, index) + 0x4C;
            void* s = func_001E6978(func_001190D0(8));
            func_001E6AC8(s, src);
            func_001E7910(params, D_00390900, s);
        }
    }
    m50 = D_00452120;
    m70.Ident();
    func_001F0210(0x24C71BC7, params, this, 0, 0);
    func_00185500(this);
    func_001F0210(0xBBAB79DE, params, this, 0, 0);
    func_00255968(this, 0x23DB4AEA);
    func_0010A9B0(D_00388A70);
}
