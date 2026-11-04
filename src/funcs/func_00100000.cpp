extern int D_00393E80;
extern int D_00393E84;
extern int D_00393E88;
extern int D_00393E8C;
extern int D_00393E90;
extern int D_00393E94;

void SeedRandom(int seed)
{
    D_00393E80 = seed;
    D_00393E84 = 0x12B9B0A1;
    D_00393E88 = 0x0AA2FB3F;
    D_00393E8C = seed;
    D_00393E90 = 0x12B9B0A1;
    D_00393E94 = 0x0AA2FB3F;
}
