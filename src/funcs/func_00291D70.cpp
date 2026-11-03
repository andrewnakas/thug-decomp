extern unsigned int D_00391D68[1];

int func_00291D70_find(unsigned int checksum);

int func_00291D70_find(unsigned int checksum) {
    for (int i = 0; i < 1; i++) {
        if (D_00391D68[i] == checksum) return i;
    }
    return -1;
}
