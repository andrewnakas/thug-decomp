struct Anim_00118980 {
    char pad0[0x18];
    int m_frame;
    char pad1C[0x40 - 0x1C];
    int m_40;
};

extern "C" bool func_00118980(Anim_00118980* self, bool inclusive, float a, float b)
{
    if (inclusive) {
        if (a < b) {
            if (self->m_40) {
                if ((float)self->m_frame < b) {
                    return false;
                }
            } else if ((float)self->m_frame < b - 1.0f) {
                return false;
            }
            return a - 1.0f <= (float)self->m_frame && (float)self->m_frame <= b;
        }
        return (float)self->m_frame <= a + 1.0f && b <= (float)self->m_frame;
    }
    if (a < b) {
        if (self->m_40) {
            if ((float)self->m_frame < b) {
                return false;
            }
        } else if ((float)self->m_frame < b - 1.0f) {
            return false;
        }
        return a - 1.0f <= (float)self->m_frame && (float)self->m_frame < b;
    }
    return (float)self->m_frame <= a + 1.0f && b < (float)self->m_frame;
}
