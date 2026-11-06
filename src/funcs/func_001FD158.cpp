struct MsgDesc_001FD158 {
    unsigned char m_id;
    unsigned char m1;
    unsigned short m_length;
    void* m_data;
    int m8;
    int m_priority;
    unsigned char m_queue;
    char pad11[0xF];
};

struct Stats_001FD158 {
    char pad[0x17F8];
    int m_lost;
    int m_outOfOrder;
    int m_dupes;
};

struct Conn_001FD158 {
    char pad[0x4930];
    unsigned int m_lastSeq;
};

struct Handler_001FD158 {
    unsigned short* m_msg;
    int pad4;
    long m_result;
    Stats_001FD158* m_stats;
    Conn_001FD158* m_conn;
    int m_flags;
    int Run();
};

extern "C" MsgDesc_001FD158* func_001FA800(MsgDesc_001FD158*);
extern "C" void func_00200C00(Stats_001FD158*, MsgDesc_001FD158*);

int Handler_001FD158::Run()
{
    Handler_001FD158* h = this;
    MsgDesc_001FD158 desc;
    func_001FA800(&desc);
    h->m_result = 2;
    if (h->m_flags & 1)
        return 3;
    unsigned short* msg = h->m_msg;
    unsigned short ack = *msg;
    desc.m_data = &ack;
    desc.m_length = 2;
    desc.m_id = 8;
    func_00200C00(h->m_stats, &desc);
    Conn_001FD158* conn = h->m_conn;
    unsigned int last = conn->m_lastSeq;
    if (!last) {
        conn->m_lastSeq = *msg;
    } else {
        unsigned int seq = *msg;
        if (seq < last) {
            if (last - seq >= 5001) {
                conn->m_lastSeq = seq;
            } else {
                h->m_stats->m_outOfOrder++;
                h->m_stats->m_lost--;
                h->m_flags |= 2;
            }
        } else if (seq == last) {
            h->m_stats->m_dupes++;
            return 0;
        } else {
            unsigned int diff = seq - last;
            if (diff >= 2) {
                if (diff >= 5001) {
                    h->m_stats->m_outOfOrder++;
                    h->m_stats->m_lost--;
                    h->m_flags |= 2;
                } else {
                    h->m_stats->m_lost = h->m_stats->m_lost + (diff - 1);
                    h->m_conn->m_lastSeq = *msg;
                }
            } else {
                conn->m_lastSeq = seq;
            }
        }
    }
    return 1;
}
