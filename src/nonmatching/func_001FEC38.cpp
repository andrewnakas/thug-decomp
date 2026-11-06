/* fuzzy: 99.5 */
/* sym: _vt$12ItA_001FEC38 = 0x00366AF8 */
/* sym: _vt$12ItB_001FEC38 = 0x00366AC0 */
/* sym: _vt$12ItC_001FEC38 = 0x00366AA8 */

struct Node_001FEC38 {
    int m0;
    void* m4;
    int m8;
    Node_001FEC38* mC;
    Node_001FEC38* m10;
    Node_001FEC38* Valid(unsigned int k = 0) { return k < ~(unsigned int)m4 ? this : 0; }
    void* GetData() { return m4; }
};

struct List_001FEC38 {
    Node_001FEC38 head;
    int m14;
};

#define ITER_001FEC38(Name)                       \
    class Name {                                  \
    public:                                       \
        int m0;                                   \
        Node_001FEC38* cur;                       \
        Name() { cur = 0; }                       \
        virtual ~Name() {}                        \
        virtual void Run();                       \
        void* Next()                              \
        {                                         \
            cur = cur->mC->Valid();               \
            if (!cur) return 0;                   \
            return cur->GetData();                \
        }                                         \
        void* Advance(Node_001FEC38* c)           \
        {                                         \
            cur = c->mC->Valid();                 \
            if (!cur) return 0;                   \
            return cur->GetData();                \
        }                                         \
        void* First(List_001FEC38* l)             \
        {                                         \
            cur = &l->head;                       \
            return Next();                        \
        }                                         \
    };

ITER_001FEC38(ItA_001FEC38)
ITER_001FEC38(ItB_001FEC38)
ITER_001FEC38(ItC_001FEC38)

struct Ref_001FEC38 {
    int m0;
    int m_count;
};

struct Msg_001FEC38 {
    unsigned char m_type;
    unsigned short m_len;
    char* m_data;
    Ref_001FEC38 m_ref;
};

extern "C" void func_001FA8C0(Msg_001FEC38* m, int flags);

static inline void Release_001FEC38(Msg_001FEC38* m)
{
    Ref_001FEC38* r = &m->m_ref;
    if (--r->m_count == 0) {
        if (m) func_001FA8C0(m, 3);
    }
}

struct Id_001FEC38 {
    char b[4];
};

class Item_001FEC38 : public Node_001FEC38 {
public:
    virtual ~Item_001FEC38();
};

class ItemA_001FEC38 : public Item_001FEC38 {
public:
    Msg_001FEC38* m_msg;
    unsigned int m_time;
};

class ItemB_001FEC38 : public Item_001FEC38 {
public:
    unsigned int m_sent;
    Msg_001FEC38* m_msg;
    int m20;
    unsigned char m_tries;
    char pad25[3];
    unsigned int m_time;
};

class ItemC_001FEC38 : public Item_001FEC38 {
public:
    unsigned char m_tries;
    unsigned char m19;
    char pad1A[2];
    int m1C;
    unsigned int m_sent;
    Id_001FEC38 m_id;
    unsigned int m_time;
    Msg_001FEC38* m_msg;
};

struct Net_001FEC38 {
    unsigned int m_now;
    char pad4[0x1838 - 4];
    void* m1838;
};

struct Conn_001FEC38 {
    List_001FEC38 m_a;
    List_001FEC38 m_b;
    List_001FEC38 m_c;
    char pad48[0x54 - 0x48];
    char* m_start;
    char* m_ptr;
    char pad5C[0x34FC - 0x5C];
    char m34FC[0x4934 - 0x34FC];
    int m4934;
};

struct Hdr_001FEC38 {
    unsigned char m_type;
    unsigned short m_len;
};

extern "C" int func_00201488(Net_001FEC38* n, Conn_001FEC38* c);
extern "C" int func_001FA678(void* p, unsigned char t);
extern "C" void* func_00331404(void* d, const void* s, int n);
extern "C" void func_001F9638(void* p, unsigned char t, unsigned short len);
extern "C" unsigned int func_00202788(Conn_001FEC38* c);

extern "C" bool func_001FEC38(Net_001FEC38* net, Conn_001FEC38* conn, int type, int flag)
{
    bool ok = true;
    switch (type) {
    case 0: {
        ItA_001FEC38 it;
        ItemA_001FEC38* o = (ItemA_001FEC38*)it.First(&conn->m_a);
        if (o) {
            ItA_001FEC38* p = &it;
            do {
                ItemA_001FEC38* next = (ItemA_001FEC38*)p->Advance(it.cur);
                if (net->m_now >= o->m_time) {
                    if (func_00201488(net, conn)) break;
                    Msg_001FEC38* m = o->m_msg;
                    int hdr = (func_001FA678(net->m1838, m->m_type) & 1) ? 1 : 3;
                    unsigned short need = m->m_len + hdr;
                    if ((conn->m_ptr - conn->m_start) + need < 0x512) {
                        *conn->m_ptr = m->m_type;
                        conn->m_ptr++;
                        if ((func_001FA678(net->m1838, m->m_type) & 1) == 0) {
                            __builtin_memcpy(conn->m_ptr, &m->m_len, 2);
                            conn->m_ptr += 2;
                        }
                        if (m->m_len) {
                            func_00331404(conn->m_ptr, m->m_data, m->m_len);
                            conn->m_ptr += m->m_len;
                        }
                        func_001F9638(conn->m34FC, m->m_type, m->m_len);
                        Release_001FEC38(m);
                        delete o;
                    } else {
                        ok = false;
                    }
                }
                o = next;
            } while (o);
        }
        break;
    }
    case 1: {
        ItB_001FEC38 it;
        for (ItemB_001FEC38* o = (ItemB_001FEC38*)it.First(&conn->m_b); o; o = (ItemB_001FEC38*)it.Next()) {
            if (net->m_now < o->m_time) continue;
            if (func_00201488(net, conn)) break;
            if (o->m_sent == 0) {
                if (flag) continue;
            } else {
                unsigned int d = net->m_now - o->m_sent;
                if (!(func_00202788(conn) < d)) continue;
            }
            Msg_001FEC38* m = o->m_msg;
            int hdr = (func_001FA678(net->m1838, m->m_type) & 1) ? 1 : 3;
            unsigned short need = m->m_len + hdr;
            if ((conn->m_ptr - conn->m_start) + need < 0x512) {
                *conn->m_ptr = m->m_type;
                conn->m_ptr++;
                if ((func_001FA678(net->m1838, m->m_type) & 1) == 0) {
                    __builtin_memcpy(conn->m_ptr, &m->m_len, 2);
                    conn->m_ptr += 2;
                }
                if (m->m_len) {
                    func_00331404(conn->m_ptr, m->m_data, m->m_len);
                    conn->m_ptr += m->m_len;
                }
                func_001F9638(conn->m34FC, m->m_type, m->m_len);
                if (o->m_sent) o->m_tries++;
                o->m_sent = net->m_now;
                o->m20 = conn->m4934;
            } else {
                ok = false;
            }
        }
        break;
    }
    case 2: {
        ItC_001FEC38 it;
        Hdr_001FEC38 h;
        h.m_type = 7;
        for (ItemC_001FEC38* o = (ItemC_001FEC38*)it.First(&conn->m_c); o; o = (ItemC_001FEC38*)it.Next()) {
            if (net->m_now < o->m_time) continue;
            if (func_00201488(net, conn)) break;
            if (o->m_sent == 0) {
                if (flag) continue;
            } else {
                unsigned int d = net->m_now - o->m_sent;
                if (!(func_00202788(conn) < d)) continue;
            }
            Msg_001FEC38* m = o->m_msg;
            unsigned short need = m->m_len + 9;
            h.m_len = m->m_len + 6;
            if ((conn->m_ptr - conn->m_start) + need < 0x512) {
                *conn->m_ptr = h.m_type;
                conn->m_ptr++;
                __builtin_memcpy(conn->m_ptr, &h.m_len, 2);
                conn->m_ptr += 2;
                *conn->m_ptr = o->m19;
                conn->m_ptr++;
                __builtin_memcpy(conn->m_ptr, &o->m_id, 4);
                conn->m_ptr += 4;
                *conn->m_ptr = m->m_type;
                conn->m_ptr++;
                if (m->m_len) {
                    func_00331404(conn->m_ptr, m->m_data, m->m_len);
                    conn->m_ptr += m->m_len;
                }
                func_001F9638(conn->m34FC, m->m_type, m->m_len);
                if (o->m_sent) o->m_tries++;
                o->m_sent = net->m_now;
                o->m1C = conn->m4934;
            } else {
                ok = false;
            }
        }
        break;
    }
    }
    return ok;
}
