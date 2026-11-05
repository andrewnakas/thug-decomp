extern int D_00452ED0[21];
extern "C" int func_00263A80(void* self, unsigned int i);

int Sum_00263AD8(void* self)
{
    int total = 0;
    for (unsigned int i = 0; i < 21; i++) {
        if (!D_00452ED0[i])
            total += func_00263A80(self, i);
    }
    return total;
}
