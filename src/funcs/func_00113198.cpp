struct Card_00113198;
extern "C" int func_00323E18(int port, int slot, int a, int b, int* result);
extern "C" int func_00113000(Card_00113198* self);

struct Card_00113198 {
    int m0;
    int m_port;
    int m_slot;
    int m_error;
    bool Check();
};

bool Card_00113198::Check()
{
    int result;
    if (!func_00323E18(m_port, m_slot, 0, 0, &result) && !func_00113000(this)) {
        return result == 1;
    }
    m_error = 8;
    return false;
}
