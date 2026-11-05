struct Data_00232B28 {
    signed char m0;
    int m4;
};

struct Comp_00232B28 {
    char pad[0x1298];
    int m_1298;
};

struct Msg_00232B28 {
    Data_00232B28* m0;
    char pad4[0x1C - 4];
    void* m_1C;
};

extern "C" void* func_0022DF08(void* self, int id);
extern "C" Comp_00232B28* func_00185578(void* obj, unsigned int name);

int Handle_00232B28(Msg_00232B28* msg)
{
    Data_00232B28* d = msg->m0;
    void* obj = func_0022DF08(msg->m_1C, d->m0);
    if (!obj) {
        return 3;
    }
    func_00185578(obj, 0x18223FD6)->m_1298 = d->m4;
    return 1;
}
