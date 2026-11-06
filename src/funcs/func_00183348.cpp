extern int D_0034ECA0[];

int Find_00183348(int key)
{
    for (int i = 1; i < 22; i++) {
        if (D_0034ECA0[i] == key)
            return i;
    }
    return 0;
}
