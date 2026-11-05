extern int D_00388814;

int Unit_00225E18()
{
    switch (D_00388814) {
    case 1:
    case 2:
    case 3:
        return 0x400;
    case 5:
        return 0x2000;
    case 4:
        return 0x4000;
    }
    return 1;
}
