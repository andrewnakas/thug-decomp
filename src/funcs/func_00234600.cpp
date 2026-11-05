struct Vec_00234600 {
    float x, y, z, w;
};

struct Packet_00234600 {
    short m_x;
    short m_y;
    short m_z;
    signed char m_a;
    signed char m_b;
    signed char m_c;
    signed char m_d;
    signed char m_e;
};

struct Msg_00234600 {
    Packet_00234600* m_data;
};

extern "C" void func_001DC138(int a, int b, Vec_00234600* pos, int c, float d, float e, float f);

bool func_00234600(Msg_00234600* msg)
{
    Packet_00234600* p = msg->m_data;
    Vec_00234600 pos;
    pos.x = p->m_x;
    pos.y = p->m_y;
    pos.z = p->m_z;
    func_001DC138(p->m_a, p->m_b, &pos, 0, p->m_c, p->m_d, p->m_e);
    return true;
}
