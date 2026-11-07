/* fuzzy: 81.0 */
extern void* D_00392068;
extern void* D_0038FC78;
extern char D_00375F50[];
extern char D_00371C78[];

struct Msg_002659C8 {
    unsigned char m_type;
    char pad1;
    unsigned short m_size;
    void* m_data;
    int m_8;
    int m_C;
    unsigned char m_10;
    char pad11[0x0F];
    void Set(void* d, unsigned short n, unsigned char t) { m_data = d; m_size = n; m_type = t; }
};

struct Iter_002659C8 {
    void* m_node;
    int m_index;
    void* m_tag;
    Iter_002659C8() : m_index(0) { m_tag = D_00371C78; }
    ~Iter_002659C8() { m_tag = D_00371C78; }
};

// Per-group notification sent with message 0x4B.
struct GroupInfo_002659C8 {
    unsigned char m_net;
    int m_gen;
    int m_group;
};

// Body of message 0x3B: header plus the object ids.
struct IdList3B_002659C8 {
    unsigned char m_flag;
    unsigned char m_net;
    int m_gen;
    unsigned int m_time;
    unsigned int m_count;
    unsigned int m_ids[512];
};

// Body of message 0x5B.
struct IdList5B_002659C8 {
    unsigned char m_net;
    int m_gen;
    unsigned int m_count;
    unsigned int m_ids[512];
};

extern "C" void* func_001FA800(void* self);
extern "C" void func_001FF970(void* client, int conn, void* msg);
extern "C" void func_00200998(void* client, int conn, unsigned char id, unsigned short len, void* data, char* name,
                              int queue, int a, int b);
extern "C" int func_00202768(void* p);
extern "C" void* func_0022E048(void* g);
extern "C" void func_002313E0(void* g, int v);
extern "C" unsigned int func_002657A0(void* mgr, unsigned int n, unsigned int* ids, char* flags, int gen,
                                      unsigned int time);
extern "C" void* func_00265978(int gen);
extern "C" unsigned int func_00265E50(void* mgr, unsigned int id, int gen);
extern "C" void* func_002A39D8(void* net);
extern "C" void* func_002A52F0(void* net, unsigned short id);
extern "C" void* func_002A53F8(void* net, Iter_002659C8* it, int kind);
extern "C" void* func_002A5490(void* net, Iter_002659C8* it, int kind);
extern "C" unsigned char func_002A7660(void* net);
extern "C" int func_002B1FE8(void* conn);
extern "C" int func_002B3080(void* conn);
extern "C" void* func_00331404(void* dst, const void* src, unsigned int n);

extern "C" void func_002659C8(int gen, unsigned int time, unsigned int n, unsigned int* ids, int broadcast)
{
    IdList3B_002659C8 list3B;
    IdList5B_002659C8 list5B;
    Msg_002659C8 msg;
    Iter_002659C8 it;
    char flags[8];
    GroupInfo_002659C8 info;
    Msg_002659C8 infoMsg;
    void* game = D_0038FC78;
    void* net = D_00392068;
    unsigned int i;

    func_001FA800(&msg);
    if (broadcast) {
        void* client = func_002A39D8(net);
        void* owner = func_00265978(gen);
        for (int k = 7; k >= 0; k--)
            flags[k] = 0;
        n = func_002657A0(func_0022E048(game), n, ids, flags, gen, time);
        if (n == 0)
            return;

        for (int g = 0; g < 8; g++) {
            if (!flags[g])
                continue;
            func_001FA800(&infoMsg);
            info.m_gen = gen;
            info.m_group = g;
            info.m_net = func_002A7660(net);
            void* conn = func_002A52F0(net, gen);
            infoMsg.Set(&info, sizeof(info), 0x4B);
            func_001FF970(client, func_002B3080(conn), &infoMsg);

            info.m_gen = gen;
            info.m_group = g;
            info.m_net = func_002A7660(net);
            conn = func_002A52F0(net, g);
            if (conn)
                func_001FF970(client, func_002B3080(conn), &msg);
        }

        list3B.m_flag = 1;
        list3B.m_time = time;
        list3B.m_gen = gen;
        list3B.m_count = n;
        list3B.m_net = func_002A7660(net);
        unsigned int size = list3B.m_count * sizeof(unsigned int);
        func_00331404(list3B.m_ids, ids, size);
        msg.Set(&list3B, size + 0x10, 0x3B);
        msg.m_C = 2;
        msg.m_10 = 8;
        for (void* c = func_002A53F8(net, &it, 0); c; c = func_002A5490(net, &it, 0))
            func_00200998(client, func_002B3080(c), msg.m_type, msg.m_size, msg.m_data, D_00375F50, 8, 1, 0);

        list5B.m_gen = gen;
        list5B.m_count = n;
        list5B.m_net = func_002A7660(net);
        size = list5B.m_count * sizeof(unsigned int);
        func_00331404(list5B.m_ids, ids, size);
        msg.Set(&list5B, size + 0xC, 0x5B);
        for (void* c = func_002A53F8(net, &it, 1); c; c = func_002A5490(net, &it, 1)) {
            if (func_002B1FE8(c))
                func_00200998(client, func_002B3080(c), msg.m_type, msg.m_size, msg.m_data, D_00375F50, 8, 1, 0);
        }

        func_002313E0(game, 0);
        if (func_00202768(owner))
            return;
    }

    for (i = 0; i < n; i++)
        func_00265E50(func_0022E048(game), ids[i], gen);
}
