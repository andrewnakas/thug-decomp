struct Anim_001194A8 {
    char pad0[0x18];
    float m_start;
    float m_cur;
    float m_end;
    float m_speed;
    int m_dir;
    int m_mode;
    int m_done;
};

extern "C" float func_0010FAB8();

extern "C" float func_001194A8(Anim_001194A8* a)
{
    float t = 0.0f;
    float limit = 0.0f;
    float wrapped = 0.0f;
    a->m_done = 0;
    if (a->m_mode == 3) {
        return 0.0f;
    }
    if (a->m_dir == 0) {
        float dt = func_0010FAB8() * 60.0f;
        t = a->m_cur + a->m_speed * dt;
        a->m_done = a->m_end < t;
        if (a->m_start == a->m_end) {
            wrapped = a->m_end;
        } else {
            wrapped = a->m_start + (t - a->m_end);
            while (a->m_end < wrapped) {
                wrapped = a->m_start + (wrapped - a->m_end);
            }
        }
        limit = a->m_end;
    } else if (a->m_dir == -1) {
        float dt = func_0010FAB8() * 60.0f;
        t = a->m_cur - a->m_speed * dt;
        a->m_done = t < a->m_start;
        if (a->m_start == a->m_end) {
            wrapped = a->m_end;
        } else {
            wrapped = a->m_end + (t - a->m_start);
            while (wrapped < a->m_start) {
                wrapped = a->m_end + (wrapped - a->m_start);
            }
        }
        limit = a->m_start;
    }
    if (a->m_done) {
        if (a->m_mode == 0) {
            t = limit;
        } else if (a->m_mode == 2) {
            t = limit;
            a->m_dir = a->m_dir ? 0 : -1;
        } else if (a->m_mode == 1) {
            t = wrapped;
        }
    }
    if (t < a->m_start) {
        t = a->m_start;
    }
    if (a->m_end < t) {
        t = a->m_end;
    }
    return t;
}
