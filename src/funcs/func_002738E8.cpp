extern void* D_00392068;
extern void* D_0038FC78;

struct Packet_002738E8 {
    unsigned char m0;
    char m1[3];
    int m4;
    int m8;
};

struct Obj_002738E8 {
    char m_pad[0x18];
    int m18;
};

struct Msg_002738E8 {
    Packet_002738E8* m0;
    char m_pad[0x18];
    Obj_002738E8* m1C;
};

extern "C" unsigned char func_002A7660(void* net);
extern "C" void* func_0022DF08(void* sk, int id);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E6B30(void* p);
extern "C" void func_001E6AE8(void* p, int a);
extern "C" void func_001E7A30(void* params, unsigned int name, int type, char* value);
extern "C" char* func_00206A08(void* p);
extern "C" void func_001F0210(unsigned int name, void* params, void* obj, int a, int b);

int HandleMsg_002738E8(Msg_002738E8* msg)
{
    Packet_002738E8* p = msg->m0;
    if (p->m0 != func_002A7660(D_00392068))
        return 3;
    Obj_002738E8* o = msg->m1C;
    void* a = func_0022DF08(D_0038FC78, p->m4);
    if (a) {
        void* b = func_0022DF08(D_0038FC78, p->m8);
        if (b) {
            if (o->m18 == p->m4) {
                void* s = func_001E6978(func_001190D0(8));
                func_001E6B30(s);
                func_001E7A30(s, 0xA4B08520, 3, func_00206A08(b));
                func_001F0210(0x0B3FF911, s, o, 0, 0);
                if (s)
                    func_001E6AE8(s, 3);
            } else if (o->m18 == p->m8) {
                void* s = func_001E6978(func_001190D0(8));
                func_001E6B30(s);
                func_001E7A30(s, 0xA4B08520, 3, func_00206A08(a));
                func_001F0210(0x4D7F6FFA, s, o, 0, 0);
                if (s)
                    func_001E6AE8(s, 3);
            }
        }
    }
    return 1;
}
