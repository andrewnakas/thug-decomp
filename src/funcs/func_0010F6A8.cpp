struct Entry_0010F6A8 {
    int m0;
    int m4;
    int m8;
    int mC;
};

struct Obj_0010F6A8;
extern "C" int func_0010F638(Obj_0010F6A8* self, int index);

struct Obj_0010F6A8 {
    int m0;
    int m4;
    int m8;
    int mC;
    int m_count;
    int m14;
    int m18;
    Entry_0010F6A8 m_entries[1];
    int RemoveMatch(int a, int b);
};

int Obj_0010F6A8::RemoveMatch(int a, int b)
{
    for (int i = 0; i < m_count; i++) {
        if (m_entries[i].m4 == a && m_entries[i].m8 == b) {
            return func_0010F638(this, i);
        }
    }
    return 0;
}
