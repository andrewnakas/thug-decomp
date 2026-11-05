struct Msg_0023AB80 {
    signed char m_type;
    unsigned char m_id;
    char pad2[2];
    int m4;
    int m8;
    int mC;
    char m10[1];
};

struct Ctx_0023AB80 {
    Msg_0023AB80* m_msg;
    char pad4[0x18];
    int m1C;
};

extern int D_00392068;
extern "C" void* func_00203360(int a);
extern "C" unsigned int func_002A7660(int a);
extern "C" void func_002394C8(void* obj, int a, int b, int c, char* d, int e);

int func_0023AB80(Ctx_0023AB80* ctx)
{
    Msg_0023AB80* msg = ctx->m_msg;
    void* obj = func_00203360(ctx->m1C);
    if (msg->m_type == 1) {
        msg = ctx->m_msg;
        unsigned int id = func_002A7660(D_00392068);
        if (msg->m_id == id) {
            func_002394C8(obj, msg->m4, msg->m8, msg->mC, msg->m10, 0);
        }
    }
    return 1;
}
