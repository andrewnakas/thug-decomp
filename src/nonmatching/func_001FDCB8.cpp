/* fuzzy: 73.8 */
/* sym: _vt$17ConnIter_001FDCB8 = 0x00366B58 */
/* sym: _vt$17NodeIter_001FDCB8 = 0x00366A90 */
struct Msg_001FDCB8 {
    unsigned char m_id;
    unsigned char m_flags;
    unsigned short m_size;
    void* m_data;
    int m8;
    int m_type;
    unsigned char m_channel;
    char pad11[0xB];
    int m_seq;
};

struct Packet_001FDCB8 {
    int m_id;
    char m_data[0x100];
};

struct Buf_001FDCB8 {
    int m_total;
    int m_id;
    char pad8[0x2C - 0x8];
    char* m_base;
    char* m_cur;
    unsigned char m_channel;
    char pad35[3];
    int m_seq;
};

class ItemBase_001FDCB8 {
public:
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    virtual ~ItemBase_001FDCB8();
};

class Item_001FDCB8 : public ItemBase_001FDCB8 {
public:
    Buf_001FDCB8* m18;
};

struct Node_001FDCB8 {
    int m0;
    Item_001FDCB8* m_item;
    int m8;
    Node_001FDCB8* m_next;
};

static inline Node_001FDCB8* Valid_001FDCB8(Node_001FDCB8* n)
{
    Node_001FDCB8* r = 0;
    if ((int)n->m_item != -1) r = n;
    return r;
}

static inline Node_001FDCB8* Next_001FDCB8(Node_001FDCB8* n)
{
    Node_001FDCB8* r = n->m_next;
    if ((int)r->m_item == -1) r = 0;
    return r;
}

struct Conn_001FDCB8 {
    char pad0[0x48];
    int m48;
    char pad4C[0x209C - 0x4C];
    Node_001FDCB8 m_list;
};

class ConnIter_001FDCB8 {
public:
    int m0;
    int m4;
    ConnIter_001FDCB8() { m4 = 0; }
    virtual void Run();
    virtual ~ConnIter_001FDCB8() {}
};

class NodeIter_001FDCB8 {
public:
    int m0;
    Node_001FDCB8* m_cur;
    NodeIter_001FDCB8() { m_cur = 0; }
    virtual void Run();
    virtual ~NodeIter_001FDCB8() {}
};

extern int D_0038EB78;
extern "C" void func_001FA800(Msg_001FDCB8* msg);
extern "C" int func_001FA648(int t);
extern "C" int func_00202B30(Conn_001FDCB8* c);
extern "C" int func_00202950(Conn_001FDCB8* c);
extern "C" void* func_00331404(void* dst, const void* src, unsigned int len);
extern "C" void func_001FA7A0(Buf_001FDCB8* b, int in_chrg);

struct Mgr_001FDCB8 {
    void SendStreams();
};

extern "C" Conn_001FDCB8* func_00200EC0(Mgr_001FDCB8* self, ConnIter_001FDCB8* it);
extern "C" Conn_001FDCB8* func_00200EF8(Mgr_001FDCB8* self, ConnIter_001FDCB8* it);
extern "C" void func_001FF970(Mgr_001FDCB8* self, int conn, Msg_001FDCB8* msg);

void Mgr_001FDCB8::SendStreams()
{
    Packet_001FDCB8 pkt;
    Msg_001FDCB8 msg;
    func_001FA800(&msg);
    int t = D_0038EB78;
    ConnIter_001FDCB8 cit;
    NodeIter_001FDCB8 nit;
    for (Conn_001FDCB8* c = func_00200EC0(this, &cit); c; c = func_00200EF8(this, &cit)) {
        int maxQueued = 5;
        int maxSend = 3;
        if (func_001FA648(t) == 1 || func_00202B30(c) == 1) {
            maxQueued = 2;
            maxSend = 1;
        }
        Node_001FDCB8* list = &c->m_list;
        int n = 0;
        for (Node_001FDCB8* nd = Valid_001FDCB8(list->m_next); nd; nd = Next_001FDCB8(nd))
            n++;
        if (n == 0) continue;
        int queued = func_00202950(c);
        if (queued >= maxQueued) continue;
        nit.m_cur = list;
        int budget = maxQueued - queued;
        if (maxSend < budget) budget = maxSend;
        nit.m_cur = Valid_001FDCB8(nit.m_cur->m_next);
        Item_001FDCB8* item = nit.m_cur ? nit.m_cur->m_item : 0;
        while (item) {
            nit.m_cur = Valid_001FDCB8(nit.m_cur->m_next);
            Item_001FDCB8* next = nit.m_cur ? nit.m_cur->m_item : 0;
            Buf_001FDCB8* b = item->m18;
            int sent = b->m_cur - b->m_base;
            int total = b->m_total;
            while (sent < total && budget > 0) {
                    int len = total - sent;
                    if (len > 0x100) len = 0x100;
                    pkt.m_id = b->m_id;
                    budget--;
                    func_00331404(pkt.m_data, b->m_cur, len);
                    sent += len;
                    msg.m_id = 0xF;
                    msg.m_size = len + 4;
                    msg.m_data = &pkt;
                    msg.m_type = 2;
                    msg.m_flags = 1;
                    msg.m_channel = b->m_channel;
                    msg.m_seq = b->m_seq;
                    b->m_seq++;
                    func_001FF970(this, c->m48, &msg);
                    b->m_cur += len;
            }
            if (sent >= total) {
                if (b) func_001FA7A0(b, 3);
                delete item;
            }
            item = next;
        }
    }
}
