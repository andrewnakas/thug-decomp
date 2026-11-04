extern "C" int func_00323CF8(int, int, int*);

struct C_00113000 {
    int pad[3];
    int m_C;
    int Poll();
};

int C_00113000::Poll()
{
    int result;
    func_00323CF8(0, 0, &result);
    if (result < 0) {
        int err;
        switch (result) {
        case -1:
            m_C = 0;
            return result;
        case -2: err = 1; break;
        case -3: err = 2; break;
        case -4: err = 3; break;
        case -5: err = 5; break;
        case -6: err = 6; break;
        case -7: err = 7; break;
        case -10: err = 4; break;
        default: err = 8; break;
        }
        m_C = err;
    }
    return result;
}
