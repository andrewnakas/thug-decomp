struct Obj_00214C90 {
    char pad0[0x38];
    int m38;
};
extern Obj_00214C90* D_00390828;

bool Has_00214C90()
{
    return D_00390828->m38 != 0;
}
