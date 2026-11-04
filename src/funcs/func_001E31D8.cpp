struct Card_001E31D8 {
    int m_port;
    int m_state;
    int m_op;
    int Update();
};

extern "C" int func_001E2CB0(Card_001E31D8* c);
extern "C" bool func_001E2D50(Card_001E31D8* c, int* err);
extern "C" void func_001E2B88(Card_001E31D8* c);
extern "C" void func_001E2AB0(Card_001E31D8* c);
extern "C" bool func_001E2E08(Card_001E31D8* c);

extern int D_0038E280;

int Card_001E31D8::Update()
{
    int err = 0;
    switch (m_state) {
    case 0:
        m_state = func_001E2CB0(this);
        break;
    case 1:
    case 2:
        if (!func_001E2D50(this, &err)) {
            if (err) {
                return err;
            }
            break;
        }
        if (m_op == 3) {
            m_op = 4;
            func_001E2B88(this);
        } else if (m_op == 1) {
            m_op = 2;
            func_001E2AB0(this);
        }
        if (func_001E2E08(this)) {
            m_state = 3;
        } else {
            m_state = 0;
        }
        break;
    case 3:
        if (!(D_0038E280 & (0x100 << m_port))) {
            m_op = 6;
            D_0038E280 &= ~((1 << m_port) | (0x10 << m_port));
        }
        break;
    }
    return err;
}
