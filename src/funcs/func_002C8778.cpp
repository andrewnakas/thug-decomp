struct Obj_002C8778 {
    char pad0[0x54];
    unsigned char m54;
    char pad55[0xF];
    int m64;
    void Reset();
};

void Obj_002C8778::Reset() {
    m64 = 0;
    m54 = 1;
}
