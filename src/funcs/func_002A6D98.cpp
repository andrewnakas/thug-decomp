struct Obj_002A6D68 {
    char pad0[0x50];
    int m50[8];
    int Get(int i) const;
};

int Obj_002A6D68::Get(int i) const {
    return m50[i];
}
