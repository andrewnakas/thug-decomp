struct State_001E0C20 {
    char pad0[0xC88];
    long mC88;
    long mC90;
};
extern State_001E0C20 D_003F0898;

void Get_001E0C20(long* a, long* b)
{
    *a = D_003F0898.mC88;
    *b = D_003F0898.mC90;
}
