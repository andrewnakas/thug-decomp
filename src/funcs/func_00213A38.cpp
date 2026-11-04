struct Obj_00213A38 {
    char pad0[0xC];
    int mC;
    char pad10[0x18];
    int m28;
};

struct Cmd_00213A38 {
    int m_arg;
    unsigned int m_op;
    int m_result;
    int m_done;
};

extern "C" void func_001848F0(Obj_00213A38* o, int a, int b);

void func_00213A38(Obj_00213A38* o, Cmd_00213A38* c)
{
    c->m_done = 1;
    switch (c->m_op) {
    case 0:
        o->m28 |= 1 << c->m_arg;
        c->m_result = 1;
        break;
    case 1:
        o->m28 &= ~(1 << c->m_arg);
        c->m_result = 1;
        break;
    case 2:
        {
            int mask = 1 << c->m_arg;
            if (o->m28 & mask) c->m_result = 1;
        }
        break;
    case 3:
        o->mC |= c->m_arg;
        break;
    case 4:
        o->mC &= ~c->m_arg;
        break;
    case 5:
        func_001848F0(o, c->m_arg, 0);
        c->m_result = 1;
        break;
    case 6:
        break;
    }
}
