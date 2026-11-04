struct Obj_001DC658 {
    float m_v[5];
    int m_type;
    bool IsZero();
};

bool Obj_001DC658::IsZero()
{
    if (m_v[0] != 0.0f || m_v[1] != 0.0f) {
        return false;
    }
    if (m_type == 2) {
        if (m_v[2] != 0.0f || m_v[3] != 0.0f || m_v[4] != 0.0f) {
            return false;
        }
    }
    return true;
}
