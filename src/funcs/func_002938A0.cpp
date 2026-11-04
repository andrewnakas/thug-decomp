struct Obj_002938A0 {
    char pad0[0x30C];
    unsigned char m30C[10];
    unsigned char m316;
    void Remove(unsigned char id);
};

void Obj_002938A0::Remove(unsigned char id)
{
    for (int i = 0; i < m316; i++) {
        if (m30C[i] == id) {
            for (int j = i; j < m316 - 1; j++) {
                m30C[j] = m30C[j + 1];
            }
            m316--;
            return;
        }
    }
}
