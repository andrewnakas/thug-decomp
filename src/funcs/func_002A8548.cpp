struct Obj_002A8548 {
    char pad0[0x2C];
    unsigned char m2C;
    unsigned char m2D;
    bool IsSame() const;
};

bool Obj_002A8548::IsSame() const {
    return m2D == m2C;
}
