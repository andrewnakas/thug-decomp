struct Card_00113200;
extern "C" int func_00323E18(int port, int slot, int* type, int* free, int* format);
extern "C" int func_00113000(Card_00113200* self);

struct Card_00113200 {
    int m0;
    int m_port;
    int m_slot;
    int m_error;
    int GetType();
};

int Card_00113200::GetType()
{
    int type;
    if (func_00323E18(m_port, m_slot, &type, 0, 0)
        || (func_00113000(this) && m_error != 1 && m_error != 0)) {
        m_error = 8;
        return 0;
    }
    switch (type) {
    case 1:
        return 1;
    case 2:
        return 2;
    case 3:
        return 3;
    }
    return 0;
}
