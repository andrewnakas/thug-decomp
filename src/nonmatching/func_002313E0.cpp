/* fuzzy: 94.5 */
/* sym: __12Msg_002313E0 = 0x001FA800 */
extern "C" void* memcpy(void*, const void*, unsigned int);

extern char D_00371C78[];
extern char D_003730A0[];
extern char D_003730B8[];
extern void* D_00392068;

struct It_002313E0 {
    int m0;
    int m4;
    void* m8;
    It_002313E0() { m8 = D_00371C78; m4 = 0; }
    ~It_002313E0() { m8 = D_00371C78; }
};

struct Msg_002313E0 {
    unsigned char m_type;
    char pad1;
    unsigned short m_size;
    void* m_data;
    int m8;
    int mC;
    unsigned char m10;
    char pad11[0xF];
    Msg_002313E0();
};

// derived wrapper: its implicit inline ctor keeps &msg out of a saved register at the ctor call (game: addiu a0,sp,0x130 in the jal delay slot).
struct MsgX_002313E0 : Msg_002313E0 {
};

struct Packet_002313E0 {
    unsigned int m_time;
    int m_key;
    char m_flag;
    char m_count;
    char m_data[0x106];
};

struct Info_002313E0 {
    char pad[0x18];
    int m18;
};

struct Conn_002313E0 {
    char pad[0x18];
    Info_002313E0* m18;
};

extern "C" Conn_002313E0* func_002A53F8(void* net, It_002313E0* it, int a);
extern "C" Conn_002313E0* func_002A5490(void* net, It_002313E0* it, int a);
extern "C" void* func_0022E358(void* self);
extern "C" unsigned int func_0024EF70(void* p);
extern "C" bool func_0024F8D8(void* p, char* name);
extern "C" bool func_0024F4C0(void* p);
extern "C" unsigned int func_0024F938(void* p);
extern "C" unsigned int func_001F0D78(const char* s);
extern "C" void* func_00240850();
extern "C" int func_0023DB90(void* p, int id);
extern "C" int func_002B1108(void* net, int id);
extern "C" void* func_001FA800(void* self);
extern "C" int func_00236248(void* self);
extern "C" int* func_002A39D8(void* net);
extern "C" int func_002B3080(Conn_002313E0* c);
extern "C" void func_001FF970(int* a, int b, Msg_002313E0* msg);
extern "C" bool func_002B1FC8(Conn_002313E0* c);
extern "C" bool func_002B2280(Conn_002313E0* c);
extern "C" void func_002A7EC8(void* net, int a);

void func_002313E0(void* self, int flag)
{
    void* net = D_00392068;
    It_002313E0 it;
    It_002313E0 it2;
    Packet_002313E0 pkt;
    int val;
    Conn_002313E0* c = func_002A53F8(net, &it, 1);
    if (!c) goto done;
next:
    {
        pkt.m_key = 0;
        pkt.m_flag = flag;
        if (flag)
            pkt.m_time = 0;
        else
            pkt.m_time = func_0024EF70(func_0022E358(self)) / 1000;
        char* p = pkt.m_data;
        char count = 0;
        for (Conn_002313E0* c2 = func_002A53F8(net, &it2, 0); c2; c2 = func_002A5490(net, &it2, 0)) {
            bool all = flag || func_0024F8D8(func_0022E358(self), D_003730A0) || !func_0024F4C0(func_0022E358(self));
            if (c2 != c || all) {
                char id = c2->m18->m18;
                if (func_0024F938(func_0022E358(self)) == func_001F0D78(D_003730B8))
                    val = func_0023DB90(func_00240850(), c2->m18->m18);
                else
                    val = func_002B1108(net, c2->m18->m18);
                *p = id;
                p++;
                memcpy(p, &val, 4);
                p += 4;
                count++;
            }
        }
        if (count > 0) {
            MsgX_002313E0 msg;
            int key = func_00236248(self);
            msg.m_data = &pkt;
            pkt.m_key = key;
            pkt.m_count = count;
            msg.m_size = count * 5 + 10;
            msg.m_type = 0x40;
            Msg_002313E0* pm = &msg;
            if (flag || key) {
                msg.mC = 2;
                msg.m10 = 8;
            }
            func_001FF970(func_002A39D8(net), func_002B3080(c), pm);
            if (!func_002B1FC8(c) && func_002B2280(c)) {
                unsigned int k[2];
                k[0] = func_00236248(self) ^ 0xDEADFACE;
                msg.m_size = 8;
                msg.m10 = 8;
                msg.mC = 2;
                msg.m_type = 0x80;
                msg.m_data = k;
                func_001FF970(func_002A39D8(net), func_002B3080(c), pm);
            }
        }
    }
    c = func_002A5490(net, &it, 1);
    if (c) goto next;
done:
    func_002A7EC8(net, *func_002A39D8(net));
}
