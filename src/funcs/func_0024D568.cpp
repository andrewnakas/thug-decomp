struct Ent_0024D568 {
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
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" void* func_0022DD38(void* self);
extern "C" void* func_00203360(void* p);
extern "C" int func_0023A168(void* sk, unsigned int a, int b, int c, int d);
extern "C" int func_0023A278(void* sk, unsigned int a, int b, int c, int d);
extern "C" void func_001F0210(unsigned int name, void* params, int a, int b, int c);
extern "C" void* func_00240850();
extern "C" bool func_0023BD18(void* self, unsigned int id);

struct Obj_0024D568;
extern "C" int func_0024E048(Obj_0024D568* self);
extern "C" void func_0024D7F8(Obj_0024D568* self, int i);
extern "C" unsigned int func_00246258(Obj_0024D568* self);

struct Obj_0024D568 {
    char pad[0x20];
    void* m20;
    char pad24[0x80];
    Ent_0024D568 mA4[30];
    int m4DC;
    int m4E0;
    int m4E4[30];
    void Fn();
};

void Obj_0024D568::Fn()
{
    void* sk = func_00203360(func_0022DD38(D_0038FC78));
    int need;
    func_001E7DE8(m20, 0x67DD90CA, &need, 1);
    for (int i = 0; i < 30; i++) {
        bool printed = false;
        if (!m4E4[i]) continue;
        int done = 0;
        for (int j = 0; j < 30; j++) {
            if (mA4[j].m8) {
                if (!mA4[j].m10 && mA4[j].m18 == i)
                    if (func_0023A278(sk, mA4[j].m8, mA4[j].m1C, mA4[j].m14, mA4[j].m20) > 0)
                        done++;
            } else if (mA4[j].m0) {
                if (!mA4[j].m10 && mA4[j].m18 == i && func_0023A168(sk, mA4[j].m0, mA4[j].m1C, mA4[j].m14, mA4[j].m20) > 0)
                    done++;
                else if (mA4[j].m4 && !mA4[j].m10 && mA4[j].m18 == i)
                    if (func_0023A168(sk, mA4[j].m4, mA4[j].m1C, mA4[j].m14, mA4[j].m20) > 0)
                        done++;
            }
        }
        if (done < need) continue;
        for (int j = 0; j < 30; j++) {
            if (!mA4[j].m10 && mA4[j].m18 == i) {
                if (!printed) func_001F0210(0xE4EA743A, 0, 0, 0, 0);
                printed = true;
                func_0024D7F8(this, j);
            }
        }
        m4E4[i] = 0;
        if (func_0024E048(this)) {
            void* mgr = func_00240850();
            func_0023BD18(mgr, func_00246258(this));
        }
    }
}
