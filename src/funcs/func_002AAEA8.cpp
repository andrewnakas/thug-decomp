struct Msg_002AAEA8 {
    unsigned char m_type;
    unsigned char m_1;
    unsigned short m_size;
    void* m_data;
    int m_8;
    int m_C;
    unsigned char m_10;
    int m_14;
    int m_18;
    int m_1C;
};

extern void* D_00392068;
extern char D_00392120[];
extern "C" void func_001FA800(Msg_002AAEA8* m);
extern "C" int func_001E84E8(void* params, char* name, int* out, int req);
extern "C" void* func_002A39E0(void* s, int v);
extern "C" void func_00200C00(void* q, Msg_002AAEA8* m);

bool func_002AAEA8(void* params)
{
    Msg_002AAEA8 msg;
    void* s = D_00392068;
    int v;
    int data;
    func_001FA800(&msg);
    func_001E84E8(params, D_00392120, &v, 1);
    void* q = func_002A39E0(s, 0);
    data = v;
    msg.m_data = &data;
    msg.m_size = 4;
    msg.m_type = 100;
    msg.m_C = 2;
    msg.m_10 = 8;
    func_00200C00(q, &msg);
    return true;
}
