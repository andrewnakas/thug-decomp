struct Obj_002A6D68 {
    char pad0[0x50];
    int m50[8];
    void SetAll(const int* src);
};

void Obj_002A6D68::SetAll(const int* src) {
    int i;
    for (i = 0; i < 8; i++) {
        m50[i] = src[i];
    }
}
