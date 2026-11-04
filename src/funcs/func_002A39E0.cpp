struct Obj_002A39D8 {
    char pad0[0x14];
    int m14;
    int m18[2];
    int m20;
    int GetM18(int i) const;
};

int Obj_002A39D8::GetM18(int i) const {
    return m18[i];
}
