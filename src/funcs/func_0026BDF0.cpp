extern "C" void* func_00187B48(void* mgr, int id);
extern "C" void func_00184950(void* obj);
extern "C" void func_00184BC0(void* obj, int a, int b, int c, int d, int e);
extern void* D_0038C608;
extern void* D_0038FC78;

struct Flags_0026BDF0 {
    char pad[8];
    int m8;
    int mC;
};

struct Game_0026BDF0 {
    char pad[0x2C];
    Flags_0026BDF0* m2C;
};

struct Obj_0026BDF0 {
    char pad0[4];
    int m4;
    char pad8[0x30 - 8];
    int m30;
    int m34;
    unsigned int m38;
    unsigned int m3C;
    int m40;
    char pad44[0x84 - 0x44];
    int m84;
    void SetState(int state);
};

void Obj_0026BDF0::SetState(int state)
{
    if (m30 == state) return;
    if (m30) {
        if (m34) {
            for (int i = 0; m38; i++) {
                if (m38 & 1) {
                    void* o = func_00187B48(D_0038C608, m34 + i);
                    if (o) func_00184950(o);
                }
                m38 >>= 1;
            }
        } else {
            Flags_0026BDF0* f = ((Game_0026BDF0*)D_0038FC78)->m2C;
            if (f) {
                for (int i = 0; m3C; i++) {
                    if (m3C & 1) {
                        void* o = func_00187B48(D_0038C608, i);
                        f->m8 = 0;
                        f->mC = 1;
                        func_00184BC0(o, m84, m4, 0, 0, 0);
                        f->mC = 0;
                    }
                    m3C >>= 1;
                }
            }
        }
    }
    m30 = state;
    m40 = -1;
}
