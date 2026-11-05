struct State_001E0C40 {
    char pad0[0xC88];
    long mC88;
    long mC90;
};
extern State_001E0C40 D_003F0898;

void Set_001E0C40(long a, long b)
{
    D_003F0898.mC88 = a;
    D_003F0898.mC90 = b;
}
