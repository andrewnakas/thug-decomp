struct Owner_002B30A0 {
    char pad0[0x320];
    int m320;
};

struct Obj_002B30A0 {
    char pad0[0x18];
    Owner_002B30A0* m18;
    int GetOwnerM320() const;
};

int Obj_002B30A0::GetOwnerM320() const {
    return m18->m320;
}
