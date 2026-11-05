struct Item_00236DE0 {
    char pad0[0x10];
    int m10;
};
extern "C" Item_00236DE0* func_0023AFE8(void* a, int i);

struct Obj_00236DE0 {
    char pad0[0x44];
    char m44[8];
    int Get(int i);
};

int Obj_00236DE0::Get(int i)
{
    return func_0023AFE8(m44, i)->m10;
}
