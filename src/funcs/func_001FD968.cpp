extern "C" int func_001FEA20(void* self, int id);

int func_001FD968(void* self)
{
    for (int i = 1; i < 0x100; i++) {
        if (!func_001FEA20(self, i))
            return i;
    }
    return 0;
}
