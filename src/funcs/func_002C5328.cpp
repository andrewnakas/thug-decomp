extern int D_00392940;

struct Obj_002C5328 {
    char pad0[0xBC];
    int mBC;
    void Publish() const;
};

void Obj_002C5328::Publish() const {
    D_00392940 = mBC;
}
