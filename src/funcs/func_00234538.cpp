struct Data_00234538 {
    signed char m0;
};

struct Msg_00234538 {
    Data_00234538* m0;
    unsigned char m4;
    char pad5[0x1C - 5];
    void* m_1C;
};

extern "C" void* func_0022E040(void* self);
extern "C" void* func_00187B48(void* a, int id);
extern "C" void func_002067E0(void* obj);
extern "C" void func_00206828(void* obj);

int Handle_00234538(Msg_00234538* msg)
{
    Data_00234538* d = msg->m0;
    void* obj = func_00187B48(func_0022E040(msg->m_1C), d->m0);
    if (obj) {
        switch (msg->m4) {
        case 0x37:
            func_002067E0(obj);
            break;
        case 0x38:
            func_00206828(obj);
            break;
        }
    }
    return 1;
}
