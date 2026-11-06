/* fuzzy: 98.9 */
typedef int qword_00271D80 __attribute__((mode(TI)));

struct Vec_00271D80 {
    union {
        qword_00271D80 q;
        float c[4];
    };
    Vec_00271D80() {}
    Vec_00271D80(const Vec_00271D80& o) { q = o.q; }
};

struct Array_00271D80 {
    char pad0[0xC];
    unsigned int mC;
};

class Item_00271D80;

class Node_00271D80 {
public:
    int m0;
    int m4;
    int m8;
    Item_00271D80* mC;
    Item_00271D80* m10;
    virtual ~Node_00271D80();
};

class Item_00271D80 : public Node_00271D80 {
public:
    unsigned int m18;
    unsigned int m1C;
    int m20;
    unsigned int m24;
    int m28;
    unsigned int m2C;
    unsigned int m30;
    int m34;
    int m38;
    int m3C;
    int m40;
    int pad44[3];
    Vec_00271D80 m50;
    Vec_00271D80 m60;
    Array_00271D80* m70;
    Item_00271D80* Valid(unsigned k = 0) { return k < ~(unsigned)m4 ? this : 0; }
    Item_00271D80* Next() { return mC->Valid(); }
};

struct Head_00271D80 {
    int m0;
    int m4;
    int m8;
    Item_00271D80* mC;
    Item_00271D80* m10;
    Item_00271D80* First() { return mC->Valid(); }
};

class Gap_00271D80 {
public:
    int m0;
    int m4;
    int m8;
    Gap_00271D80* mC;
    Gap_00271D80* m10;
    int pad14[5];
    unsigned int m28;
    Gap_00271D80* Valid(unsigned k = 0) { return k < ~(unsigned)m4 ? this : 0; }
    Gap_00271D80* Next() { return mC->Valid(); }
};

struct GapHead_00271D80 {
    int m0;
    int m4;
    int m8;
    Gap_00271D80* mC;
    Gap_00271D80* m10;
    Gap_00271D80* First() { return mC->Valid(); }
};

struct Info_00271D80;

struct Cfg_00271D80 {
    char pad0[0xA0];
    int mA0;
};

struct Ent_00271D80 {
    char pad0[0x5B0];
    Cfg_00271D80* m5B0;
};

struct Skater_00271D80 {
    char pad0[0x18];
    unsigned int m18;
    char pad1C[0x31C - 0x1C];
    int m31C;
};

struct Comp_00271D80 {
    char pad0[0x13F4];
    int m13F4;
};

struct Script_00271D80 {
    char pad0[0xB8];
    int mB8;
};

extern void* D_0038FC78;
extern void* D_0038C7B0;
extern char D_00376658[];
extern char D_00376668[];
extern char D_00376678[];

extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" bool func_001E7C80(void* params, unsigned int name, char** out, int required);
extern "C" bool func_001E8180(void* params, unsigned int name, void** out, int required);
extern "C" bool func_001E8708(void* params, unsigned int name);
extern "C" bool func_00229F78(int node, int id);
extern "C" int func_003331D0(char* buf, char* fmt, ...);
extern "C" int func_0023A278(Info_00271D80* info, unsigned int a, int b, int c, int d);
extern "C" int func_0023A168(Info_00271D80* info, unsigned int a, int b, int c, int d);
extern "C" int func_0023AB48(Info_00271D80* info, Array_00271D80* a, int b);
extern "C" void func_0026CD88(Gap_00271D80* g);
extern "C" void* func_00230628(void* p);
extern "C" void func_0026D208(void* mgr, char* name, Vec_00271D80 pos, Vec_00271D80 dir);
extern "C" void func_0026D2A8(void* mgr, char* name);
extern "C" void func_00237100(Info_00271D80* info, char* text, int score, int a);
extern "C" Comp_00271D80* func_00185578(Skater_00271D80* obj, unsigned int name);
extern "C" void func_00184BC0(Skater_00271D80* obj, unsigned int a, int b, int c, int d, int e);
extern "C" unsigned int func_001055B0(unsigned int crc, char* str);
extern "C" void func_00189750(void* mgr, unsigned int a, unsigned int id, unsigned int b, void* c, int d);

struct Obj_00271D80;
extern "C" void func_002717A0(Obj_00271D80* self, void* params, Script_00271D80* script);

struct Obj_00271D80 {
    char pad0[0xC];
    Skater_00271D80* mC;
    char pad10[0xC];
    Head_00271D80 m1C;
    char pad30[4];
    GapHead_00271D80 m34;
    char pad48[8];
    Info_00271D80* m50;
    Ent_00271D80* m54;
    void RemoveGap(Item_00271D80* n)
    {
        Gap_00271D80* next;
        for (Gap_00271D80* g = m34.First(); g; g = next) {
            next = g->Next();
            if (g->m28 == n->m18) {
                func_0026CD88(g);
                break;
            }
        }
    }
    void End(void* params, Script_00271D80* script);
};

void Obj_00271D80::End(void* params, Script_00271D80* script)
{
    if (m54->m5B0->mA0)
        return;
    unsigned int type = 0;
    func_001E8398(params, 0x3B442E26, &type, 0);
    Item_00271D80* n = m1C.First();
    while (n) {
        Item_00271D80* next = n->Next();
        if (n->m18 == type && (n->m18 || func_00229F78(n->m20, script->mB8))) {
            if (n->m1C & 0xFFFF0000) {
                delete n;
            } else {
                char* name;
                if (!func_001E7C80(params, 0xC4745838, &name, 0))
                    name = D_00376658;
                char text[0x100];
                func_003331D0(text, D_00376668, name);
                if (n->m2C) {
                    bool ok = false;
                    if (n->m24 || n->m30 || n->m70->mC) {
                        if (n->m24 && n->m28 < func_0023A278(m50, n->m24, n->m34, n->m38, n->m40))
                            ok = true;
                        else if (n->m30 && n->m28 < func_0023A168(m50, n->m30, n->m34, n->m38, n->m40))
                            ok = true;
                        else if (n->m70->mC) {
                            if (func_0023AB48(m50, n->m70, n->m3C) > 0)
                                ok = true;
                        }
                        if (ok)
                            RemoveGap(n);
                    } else {
                        RemoveGap(n);
                    }
                }
                func_0026D208(func_00230628(D_0038FC78), name, n->m50, n->m60);
                int score = 0;
                if (func_001E7DE8(params, 0xCD66C8AE, &score, 0) && mC->m31C) {
                    func_00237100(m50, text, score, 0x10);
                    func_00185578(mC, 0x270F56E1)->m13F4 = 1;
                    func_0026D2A8(func_00230628(D_0038FC78), name);
                    func_00184BC0(mC, 0x541A2485, -1, 0, 0, 0);
                }
                unsigned int target;
                if (func_001E8398(params, 0x7C9E51AB, &target, 0)) {
                    unsigned int t = target;
                    Skater_00271D80* obj = mC;
                    int a = func_001E8708(params, 0x20209C31);
                    func_00184BC0(obj, t, script->mB8, a, func_001E8708(params, 0x23627FD7), 0);
                }
                void* sub = 0;
                if (func_001E8180(params, 0xEC1CD520, &sub, 0))
                    func_002717A0(this, sub, script);
                func_00189750(D_0038C7B0, func_001055B0(type, D_00376678), 0xFFFFFFFF, mC->m18, params, 1);
                Item_00271D80* p = m1C.First();
                while (p) {
                    if (p == n) {
                        delete n;
                        break;
                    }
                    p = p->Next();
                }
                next = m1C.First();
            }
        }
        n = next;
    }
}
