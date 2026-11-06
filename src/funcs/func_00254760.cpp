struct Ent_00254760 {
    int m_state;
    unsigned int m_timer;
    int m_8;
};

extern "C" int func_00113E98(char* buf);
extern "C" float func_0010FAB8();
extern "C" unsigned int func_0033EBE0(float f);
extern "C" void* func_001F0708(int id);
extern "C" void func_001F04D8(void* p);

struct Obj_00254760 {
    char pad[0x40];
    unsigned int m_40;
    unsigned int m_44;
    char pad48[4];
    Ent_00254760 m_ent[24];
    int m_16C;
    int m_170;
    unsigned int Fn(unsigned int buttons, int idx);
};

unsigned int Obj_00254760::Fn(unsigned int buttons, int idx)
{
    unsigned int key;
    if (buttons & 0x8000) {
        key = 0x6949DB75;
    } else if (buttons & 0x2000) {
        key = 0x05DDD87C;
    } else if (buttons & 0x1000) {
        key = 0x30A4F836;
    } else if (buttons & 0x4000) {
        key = 0x0FD1AC26;
    } else {
        key = 0;
    }
    if (idx == 0 && key == 0) {
        char buf[0x100];
        int n = func_00113E98(buf);
        if (n > 0) {
            for (int i = 0; i < n; i++) {
                if (buf[i] == 0x14) {
                    key = 0x6949DB75;
                    break;
                } else if (buf[i] == 0x15) {
                    key = 0x05DDD87C;
                    break;
                } else if (buf[i] == 0x16) {
                    key = 0x30A4F836;
                    break;
                } else if (buf[i] == 0x17) {
                    key = 0x0FD1AC26;
                    break;
                }
            }
        }
    }
    if (m_ent[idx].m_state == 0) {
        if (key) {
            m_ent[idx].m_timer = m_40;
            m_ent[idx].m_state = 1;
        }
    } else if (key) {
        unsigned int dt = func_0033EBE0(func_0010FAB8() * 1000.0f);
        if (dt < m_ent[idx].m_timer) {
            m_ent[idx].m_timer -= dt;
        } else {
            m_ent[idx].m_timer = 0;
        }
        if (m_ent[idx].m_timer == 0) {
            if (m_ent[idx].m_state == 1) {
                m_ent[idx].m_state = 2;
            }
            m_ent[idx].m_timer = m_44;
        } else {
            key = 0;
        }
    } else {
        m_ent[idx].m_state = 0;
    }
    if (m_16C && idx == 0) {
        key = 0;
        void* v = func_001F0708(m_170);
        if (v) {
            func_001F04D8(v);
        } else {
            m_16C = 0;
        }
    }
    return key;
}
