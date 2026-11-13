/* force: {"kind": "ga", "before": [127, 128]} */
/* near miss: 17 words, only $s4/$s5 swapped between 'printed' flag and loop index */
struct Ent_0024D350 {
    unsigned int m0;
    unsigned int m4;
    unsigned int m8;
    int mC;
    int m10;
    int m14;
    int m18;
    int m1C;
    int m20;
};

extern void* D_0038FC78;
extern char D_00374410[];
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" void func_001E7200(void* params, unsigned int name, int value);
extern "C" void* func_0022DD38(void* self);
extern "C" void* func_00203360(void* p);
extern "C" int func_0023A168(void* sk, unsigned int a, int b, int c, int d);
extern "C" int func_0023A278(void* sk, unsigned int a, int b, int c, int d);
extern "C" void func_001F0370(char* s, int a, int b, int c);

struct Obj_0024D350;
extern "C" int func_0024E048(Obj_0024D350* self);
extern "C" int func_0024DFD0(Obj_0024D350* self);
extern "C" void func_0024D568(Obj_0024D350* self);
extern "C" void func_0024D7F8(Obj_0024D350* self, int i);

struct Obj_0024D350 {
    char pad[0x20];
    void* m20;
    char pad24[0x80];
    Ent_0024D350 mA4[30];
    void Fn();
};

void Obj_0024D350::Fn()
{
    int v;
    if (func_001E7DE8(m20, 0x60B827D5, &v, 0)) {
        if (!v) return;
        func_001E7200(m20, 0x60B827D5, 0);
    }
    bool any = false;
    if (func_0024E048(this) || func_0024DFD0(this)) any = true;
    void* sk = func_00203360(func_0022DD38(D_0038FC78));
    if (any) {
        func_0024D568(this);
        return;
    }
    bool printed = false;
    for (int i = 0; i < 30; i++) {
        if (mA4[i].m10) continue;
        if (mA4[i].m0) {
            if (!func_0023A168(sk, mA4[i].m0, mA4[i].m1C, mA4[i].m14, 1)) {
                if (!mA4[i].m4) continue;
                if (!func_0023A168(sk, mA4[i].m4, mA4[i].m1C, mA4[i].m14, 1)) continue;
            }
            if (!printed) func_001F0370(D_00374410, 0, 0, 0);
            printed = true;
            func_0024D7F8(this, i);
        } else if (mA4[i].m8) {
            if (!func_0023A278(sk, mA4[i].m8, mA4[i].m1C, mA4[i].m14, mA4[i].m20)) continue;
            if (!printed) func_001F0370(D_00374410, 0, 0, 0);
            printed = true;
            func_0024D7F8(this, i);
        }
    }
}
