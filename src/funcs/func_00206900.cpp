struct Sub_00206900 {
    char pad0[0x20];
    int m20;
};
struct Obj_00206900 {
    char pad0[0x2E0];
    Sub_00206900* m2E0;
    int* Get();
};

int* Obj_00206900::Get()
{
    return &m2E0->m20;
}
