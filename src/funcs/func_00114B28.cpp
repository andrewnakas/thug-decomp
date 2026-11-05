struct Obj_00114B28 {
    int m0[5];
    unsigned int m_flags;
    int m_id;
    bool Mark(int id);
};

bool Obj_00114B28::Mark(int id)
{
    if (m_id == id) {
        m_flags |= 1;
        return true;
    }
    return false;
}
