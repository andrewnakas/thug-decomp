struct Entry_002BB3B0 {
    int m0;
    int m4;
    int m8;
};

struct Obj_002BB3B0 {
    char pad0[0x10];
    Entry_002BB3B0 m10[2];
    Entry_002BB3B0* m28;
    Entry_002BB3B0* Get(int i);
};

Entry_002BB3B0* Obj_002BB3B0::Get(int i) {
    if (i < 2) {
        return &m10[i];
    }
    return &m28[i - 2];
}
