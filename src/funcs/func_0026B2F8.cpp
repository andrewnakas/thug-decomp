struct Entry_0026B2F8 {
    char pad[0x5C];
    short m5C;
    char pad2[2];
};

struct Obj_0026B2F8 {
    char pad[0x50];
    Entry_0026B2F8* m50;
    char pad2[0x5C - 0x54];
    int m5C;
    Entry_0026B2F8* Find(int id);
};

Entry_0026B2F8* Obj_0026B2F8::Find(int id)
{
    if (m50) {
        for (int i = 0; i < m5C; i++) {
            if (m50[i].m5C == id)
                return &m50[i];
        }
    }
    return 0;
}
