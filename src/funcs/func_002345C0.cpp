struct Data_002345C0 {
    signed char m0;
};

struct Msg_002345C0 {
    Data_002345C0* m0;
    char pad4[0x1C - 4];
    void* m_1C;
};

extern "C" void* func_0022E040(void* self);
extern "C" void* func_00187B48(void* a, int id);

int Handle_002345C0(Msg_002345C0* msg)
{
    Data_002345C0* d = msg->m0;
    func_00187B48(func_0022E040(msg->m_1C), d->m0);
    return 1;
}
