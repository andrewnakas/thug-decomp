extern "C" int func_001E2170(int bank);

int func_001E21C0(int i)
{
    int bank = 0;
    if (i >= 21) {
        bank = 1;
        i -= 21;
    }
    return ((func_001E2170(bank) >> i) ^ 1) & 1;
}
