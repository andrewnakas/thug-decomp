struct Rec_00293A80 { unsigned char id, a, b, c; };

struct Obj_00293A80 {
    char pad0[0x2E0];
    Rec_00293A80 m2E0[10];
    int m308;
    void Remove(int id);
};

void Obj_00293A80::Remove(int id)
{
    int found = 0;
    for (int i = 0; i < m308; i++) {
        if (m2E0[i].id == id) {
            for (int j = i; j < m308 - 1; j++) {
                m2E0[j] = m2E0[j + 1];
            }
            found = 1;
            break;
        }
    }
    if (found) m308--;
}
