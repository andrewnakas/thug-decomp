struct Obj_002A7650 {
    char pad0[0x28];
    int m28;
    unsigned char m2C;
    unsigned char GetM2C() const;
};

unsigned char Obj_002A7650::GetM2C() const {
    return m2C;
}
