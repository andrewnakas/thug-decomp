struct Msg_002918E0 {
    unsigned char m0;
    char pad1;
    unsigned short m2;
    void* m4;
    char pad[0x18];
};
extern void* D_00392068;
extern "C" void* func_002A52F0(void* table, unsigned short id);
extern "C" int func_002B1FC8(void*);
extern "C" void func_001FA800(Msg_002918E0*);
extern "C" int func_002B30A0(void*);
extern "C" void* func_002A39E0(void*, int);
extern "C" void func_00200C00(void*, Msg_002918E0*);

struct Obj_002918E0 {
    char pad0[0x1C];
    int m1C;
    int Set(int id, int val, int unused, int send);
};

int Obj_002918E0::Set(int id, int val, int unused, int send)
{
    if (send) {
        void* mg = D_00392068;
        void* pl = func_002A52F0(mg, id);
        if (pl && func_002B1FC8(pl)) {
            char data[16];
            Msg_002918E0 msg;
            func_001FA800(&msg);
            void* conn = func_002A39E0(mg, func_002B30A0(pl));
            data[0] = id;
            msg.m0 = 0x2A;
            msg.m2 = 2;
            data[1] = val;
            msg.m4 = data;
            func_00200C00(conn, &msg);
        }
    }
    int old = m1C;
    m1C = val;
    return old;
}
