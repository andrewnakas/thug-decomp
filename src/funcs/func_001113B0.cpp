struct Buf_001113B0 {
    int m0;
    int m4;
    char* m_data;
    int m_size;
};

struct Msg_001113B0 {
    char pad[0xC];
    int m_id;
    char pad10[0x20 - 0x10];
    int m_len;
    char m_body[1];
};

extern "C" Buf_001113B0* func_00111550(void* self, int id);
extern "C" void* func_00331404(void* dst, const void* src, int n);

extern "C" void func_001113B0(void* self, Msg_001113B0* msg, int atEnd)
{
    Buf_001113B0* b = func_00111550(self, msg->m_id);
    if (atEnd) {
        func_00331404(b->m_data + (b->m_size - msg->m_len), msg->m_body, msg->m_len);
    } else {
        func_00331404(b->m_data, msg->m_body, msg->m_len);
    }
}
