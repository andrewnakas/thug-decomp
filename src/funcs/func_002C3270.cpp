struct Obj_002C3270 {
    char pad0[0x6AE0];
    int m6AE0[8];
    int FindSlot(int v) const;
};

int Obj_002C3270::FindSlot(int v) const {
    for (int i = 1; i < 9; i++) {
        if (v == m6AE0[i - 1]) {
            return i;
        }
    }
    return 0;
}
