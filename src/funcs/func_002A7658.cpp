struct Obj_002A7650 {
    char pad0[0x28];
    int m28;
    unsigned char m2C;
    void SetM2C(unsigned char v);
};

void Obj_002A7650::SetM2C(unsigned char v) {
    m2C = v;
}
