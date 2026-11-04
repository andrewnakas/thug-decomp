struct Msg_002AADE8 {
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

struct Data_002AADE8 {
    int m_value;
    unsigned char m_id;
};

extern void* D_00392068;
extern char D_003921F8[];
extern char D_00378B78[];
extern "C" void func_001FA800(Msg_002AADE8* m);
extern "C" int func_001E7E58(void* params, char* name, int* out, int req);
extern "C" int func_001E84E8(void* params, char* name, int* out, int req);
extern "C" void* func_002A39E0(void* s, int v);
extern "C" void func_00200C00(void* q, Msg_002AADE8* m);

bool func_002AADE8(void* params)
{
    Data_002AADE8 data;
    Msg_002AADE8 msg;
    void* s = D_00392068;
    int id;
    int value;
    func_001FA800(&msg);
    func_001E7E58(params, D_003921F8, &id, 1);
    func_001E84E8(params, D_00378B78, &value, 1);
    void* q = func_002A39E0(s, 0);
    data.m_id = id;
    data.m_value = value;
    msg.m_type = 99;
    msg.m_C = 2;
    msg.m_data = &data;
    msg.m_size = 8;
    msg.m_10 = 8;
    func_00200C00(q, &msg);
    return true;
}
