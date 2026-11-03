struct Obj_002B1FC8 {
    char pad0[0x14C];
    unsigned int m14C;
    bool IsFlag200() const;
};

bool Obj_002B1FC8::IsFlag200() const {
    if (m14C & 0x200) {
        return true;
    }
    return false;
}
