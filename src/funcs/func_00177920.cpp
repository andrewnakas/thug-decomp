extern int D_0039401C;
extern int D_0038BF80;

void Tick_00177920()
{
    if (D_0039401C == 0) {
        if (D_0038BF80)
            D_0038BF80 = 0;
    }
    D_0039401C++;
}
