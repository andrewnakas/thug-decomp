struct Rec_002939E0 { unsigned char id, a, b, c; };

struct Obj_002939E0 {
    char pad0[0x2E0];
    Rec_002939E0 m2E0[10];
    int m308;
    void Set(int id, int a, int b, int c);
};

void Obj_002939E0::Set(int id, int a, int b, int c)
{
    int found = 0;
    int idx = 0;
    for (int i = 0; i < m308; i++) {
        if (m2E0[i].id == id) {
            idx = i;
            found = 1;
            break;
        }
    }
    if (!found) {
        idx = m308;
        m308++;
    }
    m2E0[idx].c = c;
    m2E0[idx].a = a;
    m2E0[idx].id = id;
    m2E0[idx].b = b / 180;
}
