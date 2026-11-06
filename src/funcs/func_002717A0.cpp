typedef int qword_002717A0 __attribute__((mode(TI)));

struct Vec_002717A0 {
    union {
        qword_002717A0 q;
        float c[4];
    };
    Vec_002717A0() {}
    Vec_002717A0(float x, float y, float z, float w)
    {
        c[0] = x;
        c[1] = y;
        c[2] = z;
        c[3] = w;
    }
};

class Item_002717A0;

class Node_002717A0 {
public:
    int m0;
    int m4;
    int m8;
    Item_002717A0* mC;
    Item_002717A0* m10;
    virtual ~Node_002717A0();
};

class Item_002717A0 : public Node_002717A0 {
public:
    unsigned int m18;
    unsigned int m1C;
    int m20;
    unsigned int m24;
    int m28;
    unsigned int m2C;
    int m30;
    int m34;
    int m38;
    int m3C;
    int m40;
    int pad44[3];
    Vec_002717A0 m50;
    Vec_002717A0 m60;
    void* m70;
    Item_002717A0* Valid(unsigned k = 0) { return k < ~(unsigned)m4 ? this : 0; }
};

struct Head_002717A0 {
    int m0;
    int m4;
    int m8;
    Item_002717A0* mC;
    Item_002717A0* m10;
    Item_002717A0* First() { return mC->Valid(); }
};

struct Array_002717A0 {
    char pad0[0xC];
    unsigned int mC;
    unsigned int Size() { return mC; }
};

struct Src_002717A0 {
    char pad0[0x50];
    Vec_002717A0 m50;
    char pad60[0x30];
    Vec_002717A0 m90;
};

struct Info_002717A0 {
    char pad0[0x58];
    int m58;
};

struct Cfg_002717A0 {
    char pad0[0xA0];
    int mA0;
};

struct Ent_002717A0 {
    char pad0[0x5B0];
    Cfg_002717A0* m5B0;
};

struct Sub_002717A0 {
    char pad0[0x180];
    int m180;
};

struct Mgr_002717A0 {
    char pad0[0x34];
    Sub_002717A0* m34;
};

struct Glob_002717A0 {
    char pad0[0xAC];
    unsigned int mAC;
};

struct Script_002717A0 {
    char pad0[0xB8];
    int mB8;
};

extern Glob_002717A0* D_00392808;

extern "C" void* func_001046B0(int size);
extern "C" Item_002717A0* func_0026CC30(void* p);
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" bool func_001E7C80(void* params, unsigned int name, char** out, int required);
extern "C" bool func_001E8248(void* params, unsigned int name, Array_002717A0** out, int required);
extern "C" bool func_001E8A30(void* params, unsigned int name, unsigned int* out, int required);
extern "C" bool func_001E8708(void* params, unsigned int name);
extern "C" unsigned int func_001E9300(Array_002717A0* a, int index);
extern "C" unsigned int func_001E53A0(unsigned int name, int a);
extern "C" int func_001F0D78(char* s);
extern "C" void func_001E66C0(void* dst, Array_002717A0* src);
extern "C" Src_002717A0* func_00203EE0(void* obj);

struct Obj_002717A0;
extern "C" int func_0023A778(Info_002717A0* info, unsigned int a, int b, int c);
extern "C" int func_0023A5D8(Info_002717A0* info, int a, int b, int c);
extern "C" void func_00271C90(Obj_002717A0* self, void* params, Script_002717A0* script);
extern "C" void func_00271560(Obj_002717A0* self, int* a, int* b);
extern "C" void func_002710B8(Obj_002717A0* self, int a, int b);

static inline void Append_002717A0(Head_002717A0* head, Item_002717A0* node)
{
    node->m10 = (Item_002717A0*)head;
    node->mC = head->mC;
    head->mC->m10 = node;
    head->mC = node;
}

struct Obj_002717A0 {
    char pad0[0xC];
    void* mC;
    char pad10[0xC];
    Head_002717A0 m1C;
    char pad30[0x20];
    Info_002717A0* m50;
    Ent_002717A0* m54;
    int pad58;
    Mgr_002717A0* m5C;
    void Add(void* params, Script_002717A0* script);
};

void Obj_002717A0::Add(void* params, Script_002717A0* script)
{
    if (m54->m5B0->mA0)
        return;
    unsigned int type = 0;
    func_001E8398(params, 0x3B442E26, &type, 0);
    Item_002717A0* n = m1C.First();
    while (n) {
        Item_002717A0* next = n->mC->Valid();
        if (n->m18 == type && n->m20 == script->mB8)
            delete n;
        n = next;
    }
    n = func_0026CC30(func_001046B0(0x80));
    Append_002717A0(&m1C, n);
    n->m18 = type;
    n->m20 = script->mB8;
    n->m30 = 0;
    n->m50 = func_00203EE0(mC)->m50;
    Src_002717A0* src = func_00203EE0(mC);
    n->m60 = Vec_002717A0(-src->m90.c[0], -src->m90.c[1], -src->m90.c[2], -src->m90.c[3]);
    unsigned int id;
    if (func_001E8398(params, 0xA26994E6, &id, 0)) {
        n->m2C = id;
        unsigned int node;
        char* name;
        Array_002717A0* arr;
        if (func_001E8398(params, 0x95E16467, &node, 0)) {
            n->m24 = node;
            int angle;
            if (func_001E7DE8(params, 0xEDF5DB70, &angle, 0)) {
                n->m38 = func_001E8708(params, 0x1C39F1B9);
                n->m34 = angle / 180;
            }
            func_001E7DE8(params, 0xA4BEE6A1, &n->m40, 0);
            n->m28 = func_0023A778(m50, node, n->m34, n->m40);
        } else if (func_001E7C80(params, 0x3EAFA520, &name, 0)) {
            n->m30 = func_001F0D78(name);
            int angle;
            if (func_001E7DE8(params, 0xEDF5DB70, &angle, 0)) {
                n->m38 = func_001E8708(params, 0x1C39F1B9);
                n->m34 = angle / 180;
            }
            func_001E7DE8(params, 0xA4BEE6A1, &n->m40, 0);
            n->m28 = func_0023A5D8(m50, n->m30, n->m34, n->m40);
        } else if (func_001E8248(params, 0x1E26FD3E, &arr, 0)) {
            func_001E66C0(n->m70, arr);
            n->m3C = m50->m58;
        }
        func_00271C90(this, params, script);
    }
    n->m1C = 0;
    Array_002717A0* flags = 0;
    func_001E8248(params, 0xF4FABE45, &flags, 0);
    if (flags) {
        for (unsigned int i = 0; i < flags->Size(); i++)
            n->m1C |= func_001E53A0(func_001E9300(flags, i), 0);
    } else {
        unsigned int f;
        if (func_001E8A30(params, 0xF4FABE45, &f, 0))
            n->m1C |= func_001E53A0(f, 0);
    }
    unsigned int extra = 0;
    if (func_001E8398(params, 0x2760DE9E, &extra, 0))
        n->m1C |= extra;
    if (func_001E8708(params, 0xC442E33D))
        n->m1C |= 0x600;
    else if (!func_001E8708(params, 0xE3ED4ADE) && !(n->m1C & 0x600))
        n->m1C |= 0x800;
    if ((m5C->m34->m180 && (n->m1C & 0x800)) || D_00392808->mAC != 0xD443A2BC) {
        int a;
        int b;
        func_00271560(this, &a, &b);
        func_002710B8(this, a, b);
    }
}
