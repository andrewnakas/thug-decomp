struct Obj_002B1FC8 {
    char pad0[0x14C];
    unsigned int m14C;
    bool IsFlag1() const;
};

bool Obj_002B1FC8::IsFlag1() const {
    return m14C & 1;
}
