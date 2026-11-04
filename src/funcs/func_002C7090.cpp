struct Inner_002C7090 {
    char pad0[0x30];
    int m30;
};

struct Obj_002C7090 {
    char pad0[0xA0];
    Inner_002C7090* mA0;
    int* GetPtr() const;
};

int* Obj_002C7090::GetPtr() const {
    return &mA0->m30;
}
