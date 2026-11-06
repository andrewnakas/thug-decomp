/* fuzzy: 71.3 */
extern void* D_00392068;
extern void* D_0038FC78;
extern char D_00373720[];

struct Msg_002394C8 {
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

class Iter_002394C8 {
public:
    void* m_node;
    int m_index;
    Iter_002394C8() : m_index(0) {}
    virtual ~Iter_002394C8() {}
    virtual void Run();
};

struct Conn_002394C8 {
    char pad[0x30];
    int m_team;
};

// Per-group notification sent with message 0x4B.
struct GroupInfo_002394C8 {
    unsigned char m_net;
    int m_owner;
    int m_group;
};

// Body of message 0x3B: header plus the object ids.
struct IdList3B_002394C8 {
    unsigned char m_flag;
    unsigned char m_net;
    int m_owner;
    unsigned int m_time;
    unsigned int m_count;
    unsigned int m_ids[512];
};

// Body of message 0x5B.
struct IdList5B_002394C8 {
    unsigned char m_net;
    int m_owner;
    unsigned int m_count;
    unsigned int m_ids[512];
};

extern "C" void* func_001FA800(void* self);
extern "C" void func_001FF970(void* client, int conn, void* msg);
extern "C" void func_00200998(void* client, int conn, unsigned char id, unsigned short len, void* data, char* name,
                              int queue, int a, int b);
extern "C" int func_00202768(void* p);
extern "C" void* func_0022E048(void* g);
extern "C" void* func_0022E358(void* g);
extern "C" void func_002313E0(void* g, int v);
extern "C" void* func_00239358(int obj);
extern "C" bool func_0024F540(void* p);
extern "C" unsigned int func_002657A0(void* mgr, unsigned int n, unsigned int* ids, char* flags, int gen,
                                      unsigned int time);
extern "C" void func_00265E50(void* mgr, unsigned int id, int owner);
extern "C" void* func_002A39D8(void* net);
extern "C" Conn_002394C8* func_002A52F0(void* net, unsigned short id);
extern "C" Conn_002394C8* func_002A53F8(void* net, Iter_002394C8* it, int kind);
extern "C" Conn_002394C8* func_002A5490(void* net, Iter_002394C8* it, int kind);
extern "C" unsigned char func_002A7660(void* net);
extern "C" int func_002B1FE8(Conn_002394C8* conn);
extern "C" int func_002B3080(Conn_002394C8* conn);
extern "C" void* func_00331404(void* dst, const void* src, unsigned int n);

extern "C" void func_002394C8(int obj, int owner, unsigned int time, unsigned int n, unsigned int* ids, int broadcast)
{
    IdList3B_002394C8 list3B;
    IdList5B_002394C8 list5B;
    Iter_002394C8 it;
    char flags[8];
    void* game = D_0038FC78;
    void* net = D_00392068;
    unsigned int i;
    int team;

    if (broadcast) {
        void* client = func_002A39D8(net);
        void* target = func_00239358(obj);
        for (int k = 7; k >= 0; k--)
            flags[k] = 0;
        n = func_002657A0(func_0022E048(game), n, ids, flags, owner, time);
        if (n == 0)
            return;

        for (int g = 0; g < 8; g++) {
            if (!flags[g])
                continue;
            GroupInfo_002394C8 info;
            info.m_owner = owner;
            info.m_group = g;
            int send = 1;
            info.m_net = func_002A7660(net);
            Conn_002394C8* from = func_002A52F0(net, owner);
            Conn_002394C8* to = func_002A52F0(net, g);
            if (func_0024F540(func_0022E358(game)) && to && from)
                send = to->m_team != from->m_team;
            if (send) {
                Msg_002394C8 infoMsg;
                func_001FA800(&infoMsg);
                infoMsg.Set(&info, sizeof(info), 0x4B);
                func_001FF970(client, func_002B3080(from), &infoMsg);
                info.m_owner = owner;
                info.m_group = g;
                info.m_net = func_002A7660(net);
                if (to)
                    func_001FF970(client, func_002B3080(to), &infoMsg);
            }
        }

        list3B.m_flag = 1;
        list3B.m_time = time;
        list3B.m_owner = owner;
        list3B.m_count = n;
        list3B.m_net = func_002A7660(net);
        unsigned int size = list3B.m_count * sizeof(unsigned int);
        func_00331404(list3B.m_ids, ids, size);
        Msg_002394C8 msg;
        func_001FA800(&msg);
        msg.Set(&list3B, size + 0x10, 0x3B);
        msg.m_C = 2;
        msg.m_10 = 8;
        for (Conn_002394C8* c = func_002A53F8(net, &it, 0); c; c = func_002A5490(net, &it, 0))
            func_00200998(client, func_002B3080(c), msg.m_type, msg.m_size, msg.m_data, D_00373720, 8, 1, 0);

        list5B.m_owner = owner;
        list5B.m_count = n;
        list5B.m_net = func_002A7660(net);
        size = list5B.m_count * sizeof(unsigned int);
        func_00331404(list5B.m_ids, ids, size);
        msg.Set(&list5B, size + 0xC, 0x5B);
        for (Conn_002394C8* c = func_002A53F8(net, &it, 1); c; c = func_002A5490(net, &it, 1)) {
            if (func_002B1FE8(c))
                func_00200998(client, func_002B3080(c), msg.m_type, msg.m_size, msg.m_data, D_00373720, 8, 1, 0);
        }

        func_002313E0(game, 0);
        if (func_00202768(target))
            return;
    }

    if (func_0024F540(func_0022E358(game)))
        team = func_002A52F0(net, owner)->m_team;
    else
        team = owner;
    for (i = 0; i < n; i++)
        func_00265E50(func_0022E048(game), ids[i], team);
}
