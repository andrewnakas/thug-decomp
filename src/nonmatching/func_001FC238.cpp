/* fuzzy: 98.6 */
struct Conn_001FC238;

struct Bytes2_001FC238 {
    char b[2];
};

struct Bytes1_001FC238 {
    char b[1];
};

struct Block_001FC238 {
    char b[0x514];
};

struct Msg_001FC238 {
    char* m_data;
    unsigned char m_id;
    unsigned long m_len;
    int m10;
    Conn_001FC238* m_conn;
    int m_flags;
    int pad1C;
    char m_buf[0xA30];
};

struct Conn_001FC238 {
    char pad0[0x5C];
    unsigned char* m5C;
    unsigned char* m60;
    char pad64[0xC];
    int m70;
    char pad74[0x20EC - 0x74];
    char m20EC[4];
};

extern "C" void* func_00200F80(int id);
extern "C" int func_001FA678(void* p, unsigned char id);
extern "C" void func_001F9638(void* p, unsigned char id, int len);
extern "C" void func_00331404(void* dst, void* src, int len);
extern "C" int func_00202758(Conn_001FC238* c);

struct Net_001FC238 {
    int Dispatch(Msg_001FC238* msg);
    int Process(Conn_001FC238* conn, int flags);
};

extern "C" int func_001FC488(Net_001FC238* self, Msg_001FC238* msg);

int Net_001FC238::Process(Conn_001FC238* conn, int flags)
{
    Msg_001FC238 msg;
    unsigned short len;
    unsigned char sub;
    unsigned char* p = conn->m5C;
    msg.m_flags = flags;
    msg.m10 = conn->m70;
    msg.m_data = msg.m_buf;
    msg.m_conn = conn;
    msg.m_len = 0;
    while (p < conn->m60) {
        msg.m_id = *p++;
        int big = ~func_001FA678(func_00200F80(conn->m70), msg.m_id) & 1;
        if (big) {
            *(Bytes2_001FC238*)&len = *(Bytes2_001FC238*)p;
            p += 2;
            msg.m_len = len;
        }
        if (msg.m_id == 7) {
            *(Bytes1_001FC238*)&sub = *(Bytes1_001FC238*)(p + 5);
            func_001F9638(conn->m20EC, sub, msg.m_len);
        }
        if (big) {
            if (msg.m_len) {
                func_00331404(msg.m_data, p, msg.m_len);
            }
        } else {
            *(Block_001FC238*)msg.m_data = *(Block_001FC238*)p;
        }
        if (func_00202758(conn)) {
            msg.m_flags |= 1;
        }
        int r = func_001FC488(this, &msg);
        if (r == 0 || r == 2) {
            conn->m60 = conn->m5C;
            return 2;
        }
        if (msg.m_id != 7) {
            func_001F9638(conn->m20EC, msg.m_id, msg.m_len);
        }
        p += msg.m_len;
    }
    conn->m60 = conn->m5C;
    return 1;
}
