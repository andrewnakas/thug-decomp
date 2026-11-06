extern "C" int func_003276D8(int* status);

struct Obj_001FA1B0 {
    char m_pad0[0x2A8];
    int m_ready;
    int Poll();
};

extern "C" int func_001FA648(Obj_001FA1B0* self);

int Obj_001FA1B0::Poll()
{
    if (func_001FA648(this) == 1 || func_001FA648(this) == 3) {
        m_ready = 0;
        int status;
        if (func_003276D8(&status) == 0 && status == 8)
            m_ready = 1;
    }
    return m_ready;
}
