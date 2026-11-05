struct Msg_00231F88 {
    char pad[0x14];
    int m_14;
};

extern void* D_00392068;
extern "C" void* func_002A5248(void* a, int id);
extern "C" void func_002B2058(void* p);

int Handle_00231F88(Msg_00231F88* msg)
{
    void* p = func_002A5248(D_00392068, msg->m_14);
    if (p) {
        func_002B2058(p);
    }
    return 1;
}
