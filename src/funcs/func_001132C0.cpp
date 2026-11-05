struct Card_001132C0;
extern "C" int func_00323E18(int port, int slot, int* type, int* free, int* format);
extern "C" int func_00113000(Card_001132C0* self);

struct Card_001132C0 {
    int m0;
    int m_port;
    int m_slot;
    int m_error;
    int GetFree();
};

int Card_001132C0::GetFree()
{
    int free;
    if (!func_00323E18(m_port, m_slot, 0, &free, 0) && !func_00113000(this)) {
        return free;
    }
    m_error = 8;
    return 0;
}
